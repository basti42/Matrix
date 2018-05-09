#include<vector>
#include<iostream>
#include<memory>
#include<random>
#include "../include/Matrix.hpp"

Matrix::Matrix(int rows, int cols, bool randomized)
: num_rows(rows),
  num_cols(cols),
  randomized(randomized)
{
    // random number generator
    double lower = -1.0;
    double upper = 1.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(lower, upper);

    // initialize the values
    this->values = std::vector<std::vector<double> >();
    for (int r=0; r<this->num_rows; r++)
    {
        std::vector<double> current = std::vector<double>();
        for (int c=0; c<this->num_cols; c++)
        {
            if (this->randomized)
            {
                double val = dis(gen);
                current.push_back(val);
            } else {
                // init to 1.0 for layer initialization
                current.push_back(1.0);
            }
        }
        this->values.push_back(current);
    }
}

// display the matrix values
void Matrix::show()
{
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            std::cout << " " << this->values[r][c] << " ";
        }
        std::cout << std::endl;
    }
}


// set the value at position [r, c] into the values array
void Matrix::set(int r, int c, double val)
{
    if (r<0 || r >this->num_rows-1)
    { std::cerr << "Row index out of bounds!" << std::endl; }
    else if (c<0 || c>this->num_cols-1)
    { std::cerr << "Col index out of bounds!" << std::endl; }
    else {
        this->values[r][c] = val;
    }
}

float Matrix::get(int r, int c)
{
    return this->values[r][c];
}

// transpose the Matrix and return a new instance
// of Matrix back
Matrix Matrix::T()
{
    Matrix t {Matrix(this->num_cols, this->num_rows, false)};
    // set the values for the transpose
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0; c<this->num_cols; c++)
        {
            t.set(c,r,this->values[r][c]);
        }
    }
    return t;
}

// multiply an int scalar to the Matrix
void Matrix::operator*(const int a)
{
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            this->values[r][c] = this->values[r][c]*a;
        }
    }
}

// multiply a double scalar to the Matrix
void Matrix::operator*(const double a)
{
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            this->values[r][c] = this->values[r][c]*a;
        }
    }
}

// divide by an int scalar to the Matrix
void Matrix::operator/(const int a)
{
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            this->values[r][c] = this->values[r][c]/a;
        }
    }
}

// divide by a double scalar to the Matrix
void Matrix::operator/(const double a)
{
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            this->values[r][c] = this->values[r][c]/a;
        }
    }
}

// add an int scalar to the Matrix
void Matrix::operator+(const int a)
{
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            this->values[r][c] = this->values[r][c]+a;
        }
    }
}

// add a double scalar to the Matrix
void Matrix::operator+(const double a)
{
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            this->values[r][c] = this->values[r][c]+a;
        }
    }
}

// subtract an int scalar to the Matrix
void Matrix::operator-(const int a)
{
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            this->values[r][c] = this->values[r][c]-a;
        }
    }
}

// subtract a double scalar to the Matrix
void Matrix::operator-(const double a)
{
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            this->values[r][c] = this->values[r][c]-a;
        }
    }
}

// Matrix multiplication (dot product)
// standardalgorithm as descriobed in wikipedia
Matrix Matrix::dot(Matrix &other)
{
    Matrix product = Matrix(this->num_rows, other.num_cols, false);

    for (int i=0;i<product.num_rows; i++)   // rows of product
    {
        for (int k=0;k<product.num_cols; k++)   // cols of product
        {
            for (int j=0;j<this->num_cols; j++) // cols of this / rows of other
            {
                product.values[i][k] += product.values[i][k] +
                                        this->values[i][j] * other.values[j][k];
            }
        }
    }

    return product;
}

// subtract one matrix from another
// return a new Matrix with the result
Matrix Matrix::sub(Matrix &other)
{
    if (this->num_rows != other.getRows() ||
        this->num_cols != other.getCols())
    { std::cerr << "Dimension missmatch for Subtraction!" << std::endl; }
    Matrix result{this->num_rows, this->num_cols, false};
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            result.set(r,c, other.get(r,c) - this->get(r,c));
        }
    }
    return result;
}

// add one matrix from another elementwise
// return a new Matrix with the result
Matrix Matrix::add(Matrix &other)
{
    if (this->num_rows != other.getRows() ||
        this->num_cols != other.getCols())
    { std::cerr << "Dimension missmatch for Addition!" << std::endl; }
    Matrix result{this->num_rows, this->num_cols, false};
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            result.set(r,c, other.get(r,c) + this->get(r,c));
        }
    }
    return result;
}

// multiply two matrices element wise
// return a new Matrix with the result
Matrix Matrix::mult(Matrix &other)
{
    if (this->num_rows != other.getRows() ||
        this->num_cols != other.getCols())
    { std::cerr << "Dimension missmatch for elementwise Multiplication!" << std::endl; }
    Matrix result{this->num_rows, this->num_cols, false};
    for (int r=0;r<this->num_rows; r++)
    {
        for (int c=0;c<this->num_cols; c++)
        {
            result.set(r,c, other.get(r,c) * this->get(r,c));
        }
    }
    return result;
}

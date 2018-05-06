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
                current.push_back(0.0);
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

// transpose the Matrix and return a new instance
// of Matrix back
Matrix Matrix::T()
{
    return Matrix(this->num_cols, this->num_rows, false);
}
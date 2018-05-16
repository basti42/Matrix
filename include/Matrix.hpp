#ifndef MATRIX_H
#define MATRIX_H

#include<vector>
#include<memory>

class Matrix
{
    private:
        int num_rows;
        int num_cols;
        bool randomized;
        std::vector<std::vector<double> > values;

    public:
        Matrix(int, int, bool);
        int getRows(){ return this->num_rows; }
        int getCols(){ return this->num_cols; }
        std::vector<std::vector<double> > getValues(){ return this->values; }
        void show();
        void set(int, int, double);
        float get(int, int);
        Matrix T();
        // operators * / + - for scalars
        void operator*(int);
        void operator*(double);
        void operator/(int);
        void operator/(double);
        void operator+(int);
        void operator+(double);
        void operator-(int);
        void operator-(double);
        // matrix calculation operations
        Matrix dot(Matrix&);
        Matrix sub(Matrix&);
        Matrix add(Matrix&);
        Matrix mult(Matrix&);
        // some more claculations, on this (mean, etc)
        Matrix mean();


};
#endif

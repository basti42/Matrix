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
        Matrix T();
};
#endif

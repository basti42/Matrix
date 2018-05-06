#include<vector>
#include<iostream>
#include<memory>
#include "../include/Matrix.hpp"


int main(int argc, char** argv)
{
    Matrix m = Matrix(3,5,true);
    m.show();

    Matrix t = m.T();
    t.show();

}

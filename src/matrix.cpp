#include<vector>
#include<iostream>
#include<memory>
#include "../include/Matrix.hpp"


int main(int argc, char** argv)
{
    Matrix m = Matrix(3,5,true);
    m.show();

    std::cout << std::endl;
    Matrix t = m.T();
    t.show();

    Matrix o = Matrix(5,1,true);

    std::cout << std::endl;
    std::cout << "Dot Product" << std::endl;
    Matrix p = m.dot(o);
    p.show();

}

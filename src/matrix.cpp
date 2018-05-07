#include<vector>
#include<iostream>
#include<memory>
#include "../include/Matrix.hpp"
#include "../include/Net.hpp"


int main(int argc, char** argv)
{
    // Matrix m = Matrix(3,5,true);
    // m.show();
    //
    // std::cout << std::endl;
    // // Matrix t = m.T();
    // // t.show();
    //
    // Matrix o = Matrix(5,1,true);
    // o.show();
    //
    // std::cout << std::endl;
    // std::cout << "Dot Product" << std::endl;
    // Matrix p = m.dot(o);
    // p.show();

    Net net = Net(3,4,1);

    std::cout << "Input Layer: " << std::endl;
    net.getInputLayer().show();

    std::cout << "Hidden Layer: " << std::endl;
    net.getHiddenLayer().show();

    std::cout << "Output Layer: " << std::endl;
    net.getOutputLayer().show();

}

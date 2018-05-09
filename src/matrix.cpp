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

    Net net = Net(5,6,3);

    std::cout << "Input Layer: " << std::endl;
    net.getInputLayer().show();

    std::cout << "Input Weights: " << std::endl;
    net.getInputWeights().show();

    std::cout << "Hidden Layer: " << std::endl;
    net.getHiddenLayer().show();

    std::cout << "Output Weights: " << std::endl;
    net.getOutputWeights().show();

    std::cout << "Output Layer: " << std::endl;
    net.getOutputLayer().show();

    std::cout << std::endl;
    std::cout << std::endl;

    Matrix d {1,5,true};
    d.set(0,0, 42);
    d.set(0,1,23);
    d.set(0,2,0.5);
    d.set(0,3,4);
    d.set(0,4,100);
    net.feedforward(d);

    Matrix t{1,3,false};
    t.set(0,0,4.0);
    t.set(0,1,3.0);
    t.set(0,2,2.0);

    std::cout << "Input Layer: " << std::endl;
    net.getInputLayer().show();

    std::cout << "Input Weights: " << std::endl;
    net.getInputWeights().show();

    std::cout << "Hidden Layer: " << std::endl;
    net.getHiddenLayer().show();

    std::cout << "Output Weights: " << std::endl;
    net.getOutputWeights().show();

    std::cout << "Output Layer: " << std::endl;
    net.getOutputLayer().show();

    net.backpropagate(t);
}

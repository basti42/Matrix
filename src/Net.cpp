#include "../include/Net.hpp"
#include "../include/Matrix.hpp"
#include <cmath>
#include <iostream>

// Constructor of the Net
Net::Net(int input, int hidden, int output)
: num_input(input),
  num_hidden(hidden),
  num_output(output),
  input_layer(Matrix(1,this->num_input, false)),
  hidden_layer(Matrix(1, this->num_hidden, false)),
  output_layer(Matrix(1, this->num_output, false)),
  weights_ih(Matrix(this->num_input, this->num_hidden, true)),
  weights_ho(Matrix(this->num_hidden, this->num_output, true))
{}

void Net::setHiddenLayer(Matrix &m)
{
    this->hidden_layer = m;
}

void Net::setOutputLayer(Matrix &m)
{
    this->output_layer = m;
}

/*
    using fast sigmoid to activate the layer
    f(x) = x / 1 + abs(x)
*/
void Net::activate(Matrix &layer)
{
    for (int i=0; i<layer.getRows(); i++)
    {
        for (int j=0; j<layer.getCols(); j++)
        {
            std::vector<std::vector<double> > vals = layer.getValues();
            layer.set(i, j, vals[i][j] / (1 + std::abs(vals[i][j])));
        }
    }
}

/*
    derivative of fast sigmoid:
    f'(x) = x / (1 - x)
*/
void Net::derive(Matrix &layer)
{
    for (int i=0;i<layer.getRows(); i++)
    {
        for (int j=0; j<layer.getCols(); j++)
        {
            std::vector<std::vector<double> > vals = layer.getValues();
            layer.set(i,j, vals[i][j] / (1 - vals[i][j]));
        }
    }
}

/*
    feed forwardm passing inputs through the net
*/
Matrix Net::feedforward(Matrix &data)
{
    // activate the hidden layer
    Matrix h_layer = data.dot(this->weights_ih);
    // std::cout << "PRE ACTIVATION HIDDEN" << std::endl;
    // h_layer.show();
    this->activate(h_layer);
    // std::cout << "POST ACTIVATION HIDDEN" << std::endl;
    // h_layer.show();
    this->setHiddenLayer(h_layer);
    // activate the output layer
    Matrix o_layer = h_layer.dot(this->weights_ho);
    this->activate(o_layer);
    this->setOutputLayer(o_layer);
    return o_layer;
}

/*
GRADIENT = deltaWeights = lr * error * derive(layer) x weights.T
*/
float Net::backpropagate(Matrix &target)
{
    float learning_rate = 0.01; // this needs to be set differently TODO
    // output error
    Matrix output_error = this->output_layer.sub(target);
    this->derive(this->output_layer);
    Matrix deltas = output_error.mult(this->output_layer);
    deltas * learning_rate;
    Matrix Tdelta = deltas.T();
    // update output weights
    Matrix dotproduct = this->weights_ho.dot(Tdelta);

    std::cout << "new Weights:" << std::endl;
    dotproduct.show();


    float error(42.0);
    return error;
}

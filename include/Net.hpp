#ifndef NET_H
#define NET_H

#include "Matrix.hpp"

class Net
{
    private:
        int num_input;
        int num_hidden;
        int num_output;
        Matrix input_layer;
        Matrix hidden_layer;
        Matrix output_layer;
        Matrix weights_ih;
        Matrix weights_ho;

        void activate(Matrix&);
        void derive(Matrix&);

    public:
        Net(int, int, int);
        int getNumInput(){ return this->num_input; }
        int getNumHidden(){ return this->num_hidden; }
        int getNumOutput(){ return this->num_output; }
        void setHiddenLayer(Matrix&);
        void setOutputLayer(Matrix&);
        Matrix getInputWeights(){ return this->weights_ih; }
        Matrix getOutputWeights(){ return this->weights_ho; }
        Matrix getInputLayer(){ return this->input_layer; }
        Matrix getHiddenLayer(){ return this->hidden_layer; }
        Matrix getOutputLayer(){ return this->output_layer; }

        Matrix feedforward(Matrix&);
        float backpropagate(Matrix&);
};

#endif

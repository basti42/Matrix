#include "../include/Net.hpp"
#include "../include/Matrix.hpp"

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

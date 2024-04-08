#include "types.h"

void init_neurone(Neuron *n);
float output_neuron(Neuron *n,float input[2]);
void gradient_descent(Neuron *n, float learning_rate, float input[2], float y, float* updated_weights);
void train_neuron(Neuron *n, float learning_rate, float input[2], float y);

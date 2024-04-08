#include "neurone.h"



int main(){

    Neuron n;
    float learning_rate;
    float input[2];
    float y;

    init_neurone(&n);
    train_neuron(&n,learning_rate,input,y);


    return 0;
}
#ifndef _TYPES_
#define _TYPES_


typedef float (*ActivationFunction) (float x);

typedef struct Neuron{
    //ActivationFunction act_fct;
	float weights[2];
	float bias;
	float output;
} Neuron;

#endif
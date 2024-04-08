#include <math.h>
#include "activation function library.h"


//this function is a classification loss function its name is the binary cross entropy formula
//sigmoid function is called
float loss_function(float *y,float *y_hat,int n){

    float loss = 0;
    for (int i = 0; i < n; i++){

        loss += *(y+i) *log(*(y_hat+i)) + //for Yi = 1
         (1-*(y+i))*log(1-*(y_hat+i));  //for Yi = 0
    }

    loss = -loss/n;
    return loss;
    
}
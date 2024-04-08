#include <math.h>

float derivative_sigmoid(float a){
    return a*(1-a);
}

float derivative_loss(float y,float a){
    return (a-y)/(a*(1-a));
}

float derivative_logLoss(float y,float a,float x){
    return derivative_loss(y,a) * derivative_sigmoid(a) * x;
}


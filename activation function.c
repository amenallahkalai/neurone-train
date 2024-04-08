#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*float Relu(float x){
    if (x>0){
        return x;
    }
    else{
        return 0;
    }
}*/

float sigmoid(float x){
    return 1/(1+exp(-x));
}

/*float softMax(float x,float *t,int n){

    float s = 0;
    float *p = t;
    for (int i = 1;i<=n;i++){
        s += exp(*p);
        p++;
    }
    return exp(x)/s;
}*/


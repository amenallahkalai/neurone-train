#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "loss_function.h"
#include "optimisation algorithms.h"
#include "types.h"



void init_neurone(Neuron *n){
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < 2; i++){
        n->weights[i] = (rand() / (double)RAND_MAX) * 2 - 1; // Cast RAND_MAX to double to avoid integer division
    }
    n->bias = (rand() / (double)RAND_MAX) * 2 - 1;
    n->output = 0;
    //n->act_fct = &sigmoid;
}

float output_neuron(Neuron *n,float input[2]){
    float output = 0;
    for (int i = 0; i < 2; i++){
        output += n->weights[i] * input[i] ;
    }
    output += n->bias;
    n->output =  sigmoid(output);
}


void gradient_descent(Neuron *n, float learning_rate, float input[2], float y, float* updated_weights) {
    
    for (int i = 0; i < 2; i++) {
        updated_weights[i] = n->weights[i] + learning_rate * derivative_logLoss(y, n->output, input[i]);
    }  
}


void train_neuron(Neuron *n, float learning_rate, float input[2], float y){

    FILE *file_loss = fopen("file_loss.txt", "a");
    FILE *file_weights = fopen("best_weights.txt", "w");

    if (file_loss == NULL || file_weights == NULL) {
        // Error handling if file opening fails
        printf("Error: Unable to open files.\n");
        return;
    }

    while (1){

        
        output_neuron(n,input);
        float loss = loss_function(&y,&n->output,1); 
        /*supposons que maana kn 1 sample de dataset ,
        kn aana akther et c'est le cas f aghleb awqat twalli haja o5ra
        ena aamltha juste bch nfkrkm b hkeyt el save lil model , so ...*/ 


        float updated_weights[2];
        gradient_descent(n,learning_rate,input, y, updated_weights);
        float W0 = vect(n->weights,input);
        float W1 = vect(updated_weights,input);

        if (W1 - W0 <0){ 
        /*mmkn zeda naamlou limite madem el courbe taa logLoss convexe
         nwallou naamlou naamlou lim(W1 - W0) = lim(dL/dw) hatta nalqouha 0 */ 
            for (int i = 0; i < 2; i++){
                n->weights[i] = updated_weights[i];
                fprintf(file_loss,"%f\n",loss); // save el loss fl file f kol iteration(epoch)
                printf("%f\n",loss); 

            }
        }
        else{
            for (int i = 0; i < 2; i++){
                fprintf(file_weight,"%f\n",n->weights[i]);
            }
            
            break;
        }
    }
    
    fclose(file_loss); // Close the file for loss
    fclose(file_weights); // Close the file for weights
}

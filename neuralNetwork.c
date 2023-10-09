#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NUM_INPUT 2
#define NUM_HIDDEN_NODES 2
#define NUM_OUTPUT 1
#define NUM_TRAINING_SET 4

double init_weights();
double sigmoid(double x);
double dSigmoid(double x);

int main(void) {

    // learning rate
    const double lr = 0.1f;

    double hiddenLayer[NUM_HIDDEN_NODES];
    double outputLayer[NUM_OUTPUT];

    double hiddenLayerBias[NUM_HIDDEN_NODES];
    double outputLayerBias[NUM_OUTPUT];

    double hiddenWeights[NUM_INPUT][NUM_HIDDEN_NODES];
    double outputWeights[NUM_HIDDEN_NODES][NUM_OUTPUT];

    double training_input[NUM_TRAINING_SET][NUM_INPUT] = {{0.0f, 0.0f},
                                                          {1.0f, 0.0f},
                                                          {0.0f, 1.0f},
                                                          {1.0f, 1.0f}};

    double training_output[NUM_TRAINING_SET][NUM_OUTPUT] = {{0.0f},
                                                            {1.0f},
                                                            {1.0f},
                                                            {0.0f}};
    
    
}

// initializes the wheights with random numbers between 0 and 1
double init_weights() {
    // returns "randomNumber" / "maximumRandomNumber"
    return ((double) rand()) / ((double) RAND_MAX);
}

double sigmoid(double x) {
    return 1 / (1 +exp(-x));
}

// derivative of sigmoid function
double dSigmoid(double x) {
    return x * (1 - x);
}
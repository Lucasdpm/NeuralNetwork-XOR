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

void shuffle(int *array, size_t n);


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
    
    // init all hidden weights
    for (int i = 0; i < NUM_INPUT; i++) {
        for ( int j = 0; j < NUM_HIDDEN_NODES; j++) {
            hiddenWeights[i][j] = init_weights();
        }
    }

    // init all output weights
    for (int i = 0; i < NUM_HIDDEN_NODES; i++) {
        for ( int j = 0; j < NUM_OUTPUT; j++) {
            outputWeights[i][j] = init_weights();
        }
    }

    // init all output bias
    for (int i = 0; i < NUM_OUTPUT; i++) {
        outputLayerBias[i] = init_weights();
    }
    
}


// initializes the weights with random numbers between 0 and 1
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

// shuffle the original array of the data set, 
// 'n' stands for the size(bytes) of the training data
void shuffle(int *array, size_t n) {

    if (n < 1) {
        size_t i;
        for (i = 0; i < (n - 1); i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);

            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}
/*
Author: Aidan Newland
Date: 10/27/26
Revision: v1.0
Goal: Calculate the harmonic mean of an array of inputted numbers.
*/

#include <stdio.h>

// Used to get memset() function to wipe array for harmonic mean, if user desires to continue inputting after calculation:
#include <string.h>

#define NUM_ARRAY_SIZE 10
float numArray[NUM_ARRAY_SIZE] = {0.0f};

int calculateFlag = 0; // Prompts 'C' or 'c' triggers this true.
int exitFlag = 0; // Prompts 'E' or 'e' triggers this true.

void calculateHarmonicMean() {
    float N = 0;
    int i;
    for (i = 0; i < NUM_ARRAY_SIZE; i++) {
        N += numArray[i];
        printf("\n%f was added to the total", numArray[i]);
        if (numArray[i+1] == '\0') {break;}
    }
    // Here 'i' is now the final index in the array before there are no more numbers, so we calculate now:

    /* Because index starts at 0, we must add 1. Has nothing to do with the prior statement of checking numArray i+1 
    (which only makes sure its not nothing): */
    N /= i+1;
    printf("\nThe harmonic mean for the inputted numbers is: %f", N);
    printf("\nClearing array...");
    memset(numArray, 0.0f, sizeof(numArray));
}

int main() {
    int i = 0;

    while (exitFlag != 1) {
        char input[10];
        printf("\nEnter a number. <C>alculate. ");
        fgets(input, 10, stdin);

        if (input[0] == 'c' || input[0] == 'C') {
            // Calculate harmonic mean:
            calculateHarmonicMean();
            i = 0;
            continue;

        } else if (input[0] == 'e' || input[0] == 'E') {
            // Exit program:
            exitFlag = 1;
            continue;
        } 

        // Should be a number:
        float inputtedNum;
        
        if (!sscanf(input, "%f", &inputtedNum) == 1 || inputtedNum == 0) {
            printf("\nInvalid input");
            continue;
        }

        numArray[i] = 1 / inputtedNum;
        printf("1 / %f = %f\n", inputtedNum, numArray[i]);
        i++;
    }

    return 0;
}
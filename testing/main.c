/*
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int getArraySize(int* array[]) {
    return (sizeof(*array) / sizeof(*array[0]));
}

int math_random(int min, int max) {
    int r = (rand() % (max - min + 1)) + min;
    return r;
}

int main(void) {

    srand(time(NULL));   // seed RNG once

    int myNewArray[15] = {
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250), 
        math_random(1, 250),
    }; // define an array

    int size = getArraySize(&myNewArray);

    printf("size: %d", size);

    int largest = 0;
    for (int i = 0; i < size; i++) {
        if (largest == 0) {largest = myNewArray[i]; continue;}

        int bool = myNewArray[i] > largest;
        printf("\n %d is bigger than %d? %d.", myNewArray[i], largest, bool);
        if (bool) {
            largest = myNewArray[i];
        }
    }
    printf("\nOur winning, biggest number issss ... (drumroll!): %d! Woohooo", largest);

    // int* pmyNewArray = &myNewArray[0]; // storing address of array via pointer
    // int* pSecondElement = &myNewArray[1]; // storing address of second element of array via pointer

    // printf("\n%p %p %p", pSecondElement, &pmyNewArray[1], &pmyNewArray[-1] + 2);

    return 0;
}
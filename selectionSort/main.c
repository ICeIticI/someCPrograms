/*
Author: Aidan Newland
Date: 9/22/26
Revision: v1.0
Goal: Program which sorts a randomized unsorted array into an array that is sorted from least to greatest
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h> // used for memcpy

void selectionSort(int list[], int size) {
    int tempData[] = list; // Temporary holding spot of the original array while we change the passed one.
    int smallestIndex = INT_MAX; // The current smallest index when looping through the original list values. Set to a very big number so anything really can override it
    
    for(int i = size; tempData[i] <= size; i++) {
        // Retrieving smallest index:
        for(int i2 = size; tempData[i2] <= size; i2--) {
            if (list[i2] < smallestIndex || smallestIndex == NULL) {
                smallestIndex = list[i2];
            }
        }
    
        // We now know the smallest index after going through the whole table:
        list[i] = tempData[smallestIndex];
        printf("\n%d", list[i]);
    }

}

int myArray[] = {3, 5, 4, 7, 9, 6, 5};
int myArraySize = sizeof(myArray) / sizeof(myArray[0]);

int main() {
    printf("\n%d", myArraySize);
    selectionSort(myArray, myArraySize);
}
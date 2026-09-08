/*
Author: Celtic
Date: 9/4/26
Revision: v1.0
Goal: Prompt user to enter a fahrenheit value that will be converted to Celsius. Additionally, test the result without parenthesis
*/

#include <stdio.h>

double toCelsius(double temp) { // Converts passed fahrenheit value to Celsius.
    double result = (100.0/180.0) * (temp - 32);
    return result;
}

int main() {
    // local definitions:
    double temp;
    double test;
    
    // statements:
    printf("Please enter a Farenheit value to be converted to Celsius: \n");
    scanf("%lf", &temp);
    
    test = toCelsius(temp);

    printf("The result is %f \n", test);

    return 0;
} // main
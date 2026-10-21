/*
Author: Celtic
Date: 10/20/26
Revision: v1.0
Goal: Convert strings representing roman numerals to integers
*/

#include <stdio.h>
#include <stdlib.h>

char roman_numerals[7] = {
    'I',
    'V',
    'X',
    'L',
    'C',
    'D',
    'M'
}; // index

int roman_values[7] = {
    1,
    5,
    10,
    50,
    100,
    500,
    1000,
}; // value

int decimalNumber = 0;

// char myRomanNumeral[2];

int check_numeral(int numeral) {
    for (int numeral_i = 0; numeral_i <= 7; numeral_i++) {
        if (numeral == roman_numerals[numeral_i]) {
            return 1;
        }
    }
    return 0;
}

int convert_string_to_value(int numeral) {
    int numeral_i = 0;
    for (numeral_i; numeral_i <= 7; numeral_i++) {
        if (roman_numerals[numeral_i] == numeral) {
            return roman_values[numeral_i];
        }
    }
}

int main() {

    char myRomanNumeral[80];

    printf("Please enter a roman numeral ");
    fgets(myRomanNumeral, 80, stdin);
    // sscanf(myRomanNumeral, "%4[^ ]", decimalNumber);
    // printf("%d", decimalNumber);

    for (int i = 0; (myRomanNumeral[i] != '\0') && (myRomanNumeral[i] != '\n'); i++) {
        if (check_numeral(myRomanNumeral[i]) == 0) { // Its not a correct numeral
            fprintf(stderr, "ERROR: Invalid roman numeral provided. %c\n", i);
            exit(1);
        }
        
        printf("\n%c", myRomanNumeral[i]);

        // find what value our numeral equals:
        int romanValue = convert_string_to_value(myRomanNumeral[i]);
        printf("\n%c equals to %d", myRomanNumeral[i], romanValue);

        if (&myRomanNumeral[i+1] == NULL || romanValue >= convert_string_to_value(myRomanNumeral[i+1])) {
            // either there is no more numerals, or our current numeral is greater than or equal to the next numeral:
            printf("\n0");
            decimalNumber += romanValue;
        } else {
            // our current numeral is less than the next numeral:
            printf("\n1");
            decimalNumber -= romanValue;
        }
        printf("\nour decimal value now equals %d\n", decimalNumber);
    }
}
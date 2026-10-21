/*
Author: Celtic
Date: 10/20/26
Revision: v1.0
Goal: Convert string money amounts to proper english words.
*/

#include <stdio.h>
#include <string.h> // has a function strlen, gets length of string

char* number_mapping[11] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten"
};

char* teens_mapping[10] = {
    "",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
};

char* tens_mapping[10] = {
    "",
    "",
    "twenty",
    "thirty",
    "fourty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

char* colossal_mapping[14] = {
    "",
    "",
    "",
    "hundred", // three digits so index [3]
    "thousand",
    "",
    "",
    "million",
    "",
    "",
    "billion",
    "",
    "",
    "trillion"
};

int decimalNumber = 0;
int stringLength;

char* getTensValue(int digitValue) {
    char newString[20] = "";

    strcat(newString, number_mapping[digitValue]);
    strcat(newString, " ");

    return newString;
}

char* getHundredsValue(int digitIndex, int digitValue) {
    char newString[20] = "";

    strcat(newString, number_mapping[digitValue]);
    strcat(newString, " ");
    strcat(newString, colossal_mapping[digitIndex]);
    strcat(newString, " ");

    return newString;
}

int main() {

    char moneyAmount[80];
    char moneyString[80] = "";

    printf("Please enter an amount of money and I'll convert it to english wording: ");
    fgets(moneyAmount, 80, stdin);
    stringLength = strlen(moneyAmount) - 1; // because the length would include the newline, I have to manually remove 1
    printf("\nLength: %d", stringLength);

    for (int i = 0; (moneyAmount[i] != '\0') && (moneyAmount[i] != '\n'); i++) {
        // if (check_numeral(moneyAmount[i]) == 0) { // Its not a correct numeral
        //     fprintf(stderr, "ERROR: Invalid number provided. %c\n", i);
        //     exit(1);
        // }
        
        int current_digit_pos = stringLength - i; // the index, so if its the 3 in 300, its 0
        int current_digit_val = moneyAmount[i] - '0'; // the value itself, so in 300 this would be the 3

        printf("\n%d %d\n", current_digit_pos, current_digit_val);
        if (current_digit_pos >= 3) {
            // hundreds and beyond

            if (current_digit_pos > 4) { // checking for like ten thousands, hundred thousands, ten millions, etc
                if ( current_digit_pos % 3 == 1) {
                    strcat(moneyString, getTensValue(current_digit_val));
                } else if (current_digit_pos % 3 == 2) {
                    strcat(moneyString, getHundredsValue(current_digit_pos, current_digit_val));
                }
            }
            strcat(moneyString, number_mapping[current_digit_val]);
            strcat(moneyString, " ");
            strcat(moneyString, colossal_mapping[current_digit_pos]);
            strcat(moneyString, " ");
            printf("\nmoney string so far: %s", moneyString);
        } else if (current_digit_pos == 2) {

            if (current_digit_val < 2) { // teens
                int next_digit_val = moneyAmount[i+1] - '0';
                strcat(moneyString, teens_mapping[next_digit_val]);
                strcat(moneyString, " ");
            } else {
                strcat(moneyString, getTensValue(current_digit_val));
                strcat(moneyString, " ");
            }
        } else { // ones
                strcat(moneyString, number_mapping[current_digit_val]);
                strcat(moneyString, " ");
        }
    }
}
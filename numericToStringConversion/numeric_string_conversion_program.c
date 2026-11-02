/*
Author: Celtic
Date: 10/20/26
Revision: v2.0
Goal: Convert string money amounts to proper english words. Additionally, I'm optimizing my previous approach, and making the program more modular.
*/

#include <stdio.h>
#include <stdlib.h> // used for malloc function
#include <string.h> // has a function strlen, gets length of string
#include <ctype.h> // has the isdigit() function, allows me to check if a character is a number or not. Also has toupper()

/* lists ones digits and ten spelled out, for converting the real-number into words */
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

/* lists the numbers between 11 and 19 into words */
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

/* lists all the tens numbers from 20 to 90 */
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

/* lists colossal numbers, ranging from hundred to trillion. Their indexes correspond to which figure they are (ex. a million is 7-figure) */
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

/* Converts a ones digit (ex. 2,000) into words for colossal numbers */
char* get_colossal_ones_value(int current_digit_pos, int current_digit_val) {
    char* result = malloc(80);
    sprintf(result, "%s %s", number_mapping[current_digit_val], colossal_mapping[current_digit_pos]);

    return result;
}

/* Converts a tens digit (ex. 20,000) into words for colossal numbers */
char* get_colossal_tens_value(int current_digit_val) {
    char* result = malloc(80);
    sprintf(result, "%s", tens_mapping[current_digit_val]);

    return result;
}


/* Converts a hundreds digit (ex. 200,000) */
char* get_colossal_hundreds_value(int current_digit_pos, int current_digit_val) {
    char* result = malloc(80);
    sprintf(result, "%s %s", number_mapping[current_digit_val], colossal_mapping[3]); // formats result like how printf does

    return result;
}


/* Converts collossal digits (numbers that go into hundreds, thousands, millions, billions) into words*/
char* convert_colossal_digit(int current_digit_pos, int current_digit_val) {
    // hundreds and beyond

    printf("\n%d .. ", current_digit_pos);
    if (current_digit_pos % 3 == 2) {
        // tens
        printf("tens value");
        return get_colossal_tens_value(current_digit_val);
    } else if (current_digit_pos % 3 == 1) {
        // ones
        printf("ones value");
        return get_colossal_ones_value(current_digit_pos, current_digit_val);
    } else {
        // hundreds
        printf("hundreds value");
        return get_colossal_hundreds_value(current_digit_pos, current_digit_val);
    }
}

/* Converts a tens digit into a word */
char* convert_tens_digit(int current_digit_val, int i, char* numberToConvert) {

    char* result = malloc(30);
    if (current_digit_val < 2) { // teens
        int next_digit_val = numberToConvert[i+1] - '0';
        sprintf(result, "%s", teens_mapping[next_digit_val]);
    } else {
        sprintf(result, "%s", tens_mapping[current_digit_val]);
    }
    return result;
}

/* converts a ones digit into a word */
char* convert_ones_digit(int current_digit_val, int i, char* numberToConvert, int stringLength) {
    int previous_digit_val = numberToConvert[i-1] - '0';
    if (previous_digit_val < 2 && stringLength > 1) {return "NULL";} // thirteen one won't make sense. Basically, the ones place shouldn't be spelled out if its a teens number
    // also, have to return a string spelling NULL because this is a char*-returning function
    // we also check that the stringLength is greater than 1 because if its not then the previous digit is a garbage value

    char* result = malloc(30);
    sprintf(result, "%s", number_mapping[current_digit_val]);
    
    return result;
    // strcat(money_words_string, number_mapping[current_digit_val]);
    // strcat(money_words_string, " ");
}

char* setMoneyAmount(char* moneyAmount, char* dollarBuffer) {

    int indexIncrement = 0; // increases each successful increment
    for (int i = 0; (moneyAmount[i] != '\0') && (moneyAmount[i] != '.'); i++) {
        if (moneyAmount[i] == '\n' || moneyAmount[i] == '$' ) {continue;}

        // Error check to make sure we're only getting numeric values:
        if (!isdigit(moneyAmount[i])) {
            fprintf(stderr, "ERROR: Non-numeric number provided. %c\n", i);
            exit(1);
        }

        printf("\n%d , %c", i, moneyAmount[i]);

        dollarBuffer[indexIncrement] = moneyAmount[i];
        indexIncrement++;
    }
}

/* the main, high-level function that links to the smaller functions */
char* convert_number_to_words(char* numberToConvert, int stringLength, char* money_words_string) {
    // char money_words_string[80] = "";
    int is_single_digit = stringLength == 1; // boolean, true if there is only one digit in the nunber. Cause then we can use the "zero" string if needed

    for (int i = 0; (numberToConvert[i] != '\0') && (numberToConvert[i] != '\n'); i++) {
        int current_digit_pos = stringLength - i; // the index, so if its the 3 in 300, its 2
        int current_digit_val = numberToConvert[i] - '0'; // the value itself, so in 300 this would be the 3
        char* string_addition; // What gets added onto money_words_string once we figure out what word that'll be.

        // We don't account for numbers with zeros that are more than two digits, because if its 20, then 'twenty zero' won't make sense:
        if (current_digit_val == 0 && !is_single_digit) {continue;}

        
        // printf("\n%d %d\n", current_digit_pos, current_digit_val);
        if (current_digit_pos >= 3) {
            string_addition = convert_colossal_digit(current_digit_pos, current_digit_val);
        } else if (current_digit_pos == 2) {
            string_addition = convert_tens_digit(current_digit_val, i, numberToConvert);
        } else { // ones
            string_addition = convert_ones_digit(current_digit_val, i, numberToConvert, stringLength);
            if (string_addition == "NULL") {continue;} // this odd check may happen if its a teen number, so for example the one in eleven shouldn't be pronounced (eleven one makes no sence)
        }
        strcat(money_words_string, string_addition);
        strcat(money_words_string, " ");
        free(string_addition); // frees malloc

    }
}

int main() {
    
    char moneyAmount[80];

    printf("Please enter an amount of money and I'll convert it to english wording: ");
    fgets(moneyAmount, 80, stdin);
    stringLength = strlen(moneyAmount) - 1; // because the length would include the newline, I have to manually remove 1

    char* dot = strchr(moneyAmount, '.');
    char* dollarAmount;
    char* centAmount;
    char moneyWordsString[80] = "";

    // printf("\n%s %s", dollarAmount, dot);
    
    // Dollars
    setMoneyAmount(moneyAmount, dollarAmount);
    stringLength = strlen(dollarAmount);
    printf("\nLength: %d", stringLength);
    
    // Cents
    printf("\n%p", dot);
    if (dot != NULL) {
        printf("\nHEEY");
        centAmount = dot + 1;
        setMoneyAmount(dot, centAmount);
    } else {
        // setMoneyAmount("0", centAmount);
        centAmount = "0";
    }
    
    // Setting dollar money to words:
    convert_number_to_words(dollarAmount, stringLength, moneyWordsString);
    strcat(moneyWordsString, "dollars and ");
    printf("here");
    
    // Setting cent money to words:
    convert_number_to_words(centAmount, strlen(centAmount) - 1, moneyWordsString);
    strcat(moneyWordsString, "cents.");

    
    // Capitalizing first letter, for good grammar
    printf("\n%c", moneyWordsString[1]);
    moneyWordsString[0] = toupper(moneyWordsString[0]);

    // Final result:
    printf("\n%s", moneyWordsString);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache.h"

char *memo[MAX_MEMOIZE] = {NULL}; // Define memoization storage

const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void number_to_words(int num, char *buffer) {
    if (num == 0) {
        strcat(buffer, "zero");
        return;
    }
    
    if (num >= 1000) {
        strcat(buffer, ones[num / 1000]);
        strcat(buffer, " thousand ");
        num %= 1000;
    }
    if (num >= 100) {
        strcat(buffer, ones[num / 100]);
        strcat(buffer, " hundred ");
        num %= 100;
    }
    if (num >= 20) {
        strcat(buffer, tens[num / 10]);
        strcat(buffer, " ");
        num %= 10;
    }
    if (num >= 10 && num < 20) {
        strcat(buffer, teens[num - 10]);
        return;
    }
    if (num > 0) {
        strcat(buffer, ones[num]);
    }
}

char *convert_to_words(int amount) {
    if (amount < MAX_MEMOIZE && memo[amount]) {
        return memo[amount]; // Return cached result
    }

    static char buffer[256];
    int dollars = amount / 100;
    int cents = amount % 100;
    buffer[0] = '\0';

    char dollar_words[128] = "";
    char cent_words[128] = "";

    number_to_words(dollars, dollar_words);
    number_to_words(cents, cent_words);

    snprintf(buffer, sizeof(buffer), "%d = %s dollars and %s cents", amount, dollar_words, cent_words[0] ? cent_words : "zero");

    // Cache the result
    if (amount < MAX_MEMOIZE) {
        memo[amount] = strdup(buffer); // Store in memoization array
    }

    return buffer;
}

void free_memoization() {
    for (int ii = 0; ii < MAX_MEMOIZE; ii++) {
        if (memo[ii]) {
            free(memo[ii]); // Free dynamically allocated memory
            memo[ii] = NULL;
        }
    }
}

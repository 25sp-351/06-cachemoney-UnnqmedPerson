#ifndef CACHE_H
#define CACHE_H

#define MAX_MEMOIZE 150000 // Memoization limit ($1500 in cents)

extern char *memo[MAX_MEMOIZE]; // Declare memoization storage

void init_memoization();  // Function to initialize memo array
void free_memoization();  // Function to free allocated memory
char *convert_to_words(int amount); // Function to convert numbers to words

#endif

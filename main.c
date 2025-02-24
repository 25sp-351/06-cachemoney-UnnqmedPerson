#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache.h"

int main() {
    int amount;
    char input[256];

    while (fgets(input, sizeof(input), stdin)) {
        if (input[0] == '$') {
            sscanf(input + 1, "%d", &amount);
        } else {
            sscanf(input, "%d", &amount);
        }
        printf("%s\n", convert_to_words(amount));
    }

    free_memoization(); // Free allocated memory before exiting
    return 0;
}

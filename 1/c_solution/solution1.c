#include "common.h"

#define MAX_BUFFER_SIZE 60

/*
Here's equivalent python code. Build from that.

total = 0

with open("../input.txt") as f:
    for line in f:
        digits = "".join([char for char in line if char.isdigit()])
        digits = digits[0] + digits[-1]
        total += int(digits)

print(total)
*/

int main() {
    FILE *f = fopen(INPUT_FILE, "r");

    if (f == NULL) {
        fprintf(stderr, "File \"%s\" could not be opened.", INPUT_FILE);
        exit(EXIT_FAILURE);
    }

    char *buffer = (char *)malloc(sizeof(char) * MAX_BUFFER_SIZE);

    if (buffer == NULL) {
        fclose(f);
        fprintf(stderr, "Buffer cannot be allocated. Clearly, something's wrong if you can't give me 60 bytes of memory.");
    }

    unsigned long total = 0; 

    while (fgets(buffer, MAX_BUFFER_SIZE, f) != NULL) {

        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        char firstDigit = -1;
        char lastDigit = -1;

        for (size_t i = 0; i < strlen(buffer); i++) {

            size_t end = strlen(buffer) - i - 1;

            if (firstDigit == -1 && (buffer[i] <= '9' && buffer[i] >= '1')) {
                firstDigit = buffer[i] - 48;
            }

            if (lastDigit == - 1 && (buffer[end] <= '9' && buffer[end] >= '1')) {
                lastDigit = buffer[end] - 48;
            }
        }

        if (firstDigit == -1 && lastDigit != -1) {
            firstDigit = lastDigit;
        } 

        else if (firstDigit != -1 && lastDigit == -1) {
            lastDigit = firstDigit;
        }

        else if (firstDigit == -1 && lastDigit == -1) {
            continue;
        }

        printf("line: %s\nfirst number: %d\nlast number:  %d\ndigit to add: %d\n\n", buffer, firstDigit, lastDigit, firstDigit * 10 + lastDigit);
        
        total += firstDigit * 10 + lastDigit;
    }

    printf("total: %lu\n", total);

    free(buffer);
    fclose(f);
}
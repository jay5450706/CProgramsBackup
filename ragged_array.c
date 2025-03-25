#include <stdio.h>
#include <stdlib.h>

int hello(int, int);
int hello(int, int);

int main() {
    int* ragged[3];  // Array of 3 pointers to int arrays (simulating 3 rows)

    // Allocating different column sizes for each "row"
    ragged[0] = (int*)malloc(2 * sizeof(int));  // First row has 2 columns
    ragged[1] = (int*)malloc(3 * sizeof(int));  // Second row has 3 columns
    ragged[2] = (int*)malloc(4 * sizeof(int));  // Third row has 4 columns

    // Example assignment
    ragged[0][0] = 1;
    ragged[0][1] = 2;
    ragged[1][0] = 3;
    ragged[1][1] = 4;
    ragged[1][2] = 5;
    ragged[2][0] = 6;
    ragged[2][1] = 7;
    ragged[2][2] = 8;
    ragged[2][3] = 9;

    // Example output
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < ((i == 0) ? 2 : (i == 1) ? 3 : 4); j++) {
            printf("%d ", ragged[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        free(ragged[i]);
    }

    return 0;
}

int hello(int a, int b){
    return a+b;
}
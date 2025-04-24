/*
 *Improved version of multiplication table program
 */

#include <stdio.h>

int main() {
    // totalTables: Total number of multiplication tables to display
    int totalTables = 10;
    printf("Enter the number of columns (multiplication tables to display): ");
    scanf("%d", &totalTables);

    if (totalTables < 1) {
        printf("Invalid Column value");
        return 0;
    }

    // tablesLeft: Keeps track of how many tables are yet to be printed
    int tablesLeft = totalTables;

    // tablesPerGroup: How many multiplication tables to show per row group
    int tablesPerGroup = 4;
    printf("Enter the number of columns per row (group): ");
    scanf("%d", &tablesPerGroup);

    if (tablesPerGroup < 1) {
        printf("Invalid columns per row value");
        return 0;
    }

    printf("\n");

    // startTable: the first table number of the current group (e.g., 1, 5, 9)
    int startTable = 1;

    // endTable: the last table number in the current group (will update per group)
    int endTable = 0;

    // currentMultiplier: the number currently being multiplied (i.e., 1 to 10)
    int currentMultiplier;

    // Outer loop runs until all tables are printed
    while (startTable <= totalTables) { //start table 1
        // Determine how many tables to print in the current group
        if (tablesLeft >= tablesPerGroup) {//tables left = 10
            endTable = startTable + tablesPerGroup - 1; //1+3 //end table 4
        } else {
            endTable = startTable + tablesLeft - 1;
        }

        //Print the multiplication tables from startTable to endTable
        //we could control the size of all tables by updating the following condition
        //currentMultiplier <= 10 (or 15 or totalTables)
        for (currentMultiplier = 1; currentMultiplier <= totalTables; currentMultiplier++) {
            for (int table = startTable; table <= endTable; table++) {
                printf("%d x %d = %d\t| ", table, currentMultiplier, table * currentMultiplier);
            }
            printf("\n"); // Move to the next line after one row of multiplication
        }

        // Update how many tables are left and prepare for next group
        tablesLeft -= tablesPerGroup;
        startTable = endTable + 1;

        printf("\n"); // Separate groups visually
    }

    return 0;
}
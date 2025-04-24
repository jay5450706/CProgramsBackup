/*
 *Prints a multiplication table on the console screen
 *You specify no_of_tables and the no_of_tables to be displayed,
 *per row group
 *
 *It will not crash when the no_of_tables to be displayed per row is greater than
 * of no_of_tables
 */


#include <stdio.h>

int main(){

    int no_of_tables = 10;
    printf("Enter the number of tables: ");
    scanf("%d", &no_of_tables);

    if(no_of_tables < 1){
        printf("Invalid number of tables");
        return 0;
    }

    int tables_left = no_of_tables;

    int tables_per_row = 4; //how many number of tables to display per row(group)
    printf("How many tables to display per row(group)?: ");
    scanf("%d", &tables_per_row);

    if(tables_per_row < 1){
        printf("Invalid tables per row value");
        return 0;
    }    

    printf("\n");

    //first multiplier/first factor of each table
    int first_factor = 1;

    //end table of each row
    int end_table = 0;

    //to store the first factor of each column so we don't lose it, in 
    //next iterations of outer for loop
    int k;

    //we should stop when the 2nd factor is greater than,
    //the no. of no_of_tables, we are not interested in more no_of_tables than specified.
    //we could use i but it is not visible here
    while (!(first_factor > no_of_tables))
    {
        if(tables_left >= tables_per_row){
            end_table = end_table + tables_per_row;
        }

        if(tables_left < tables_per_row){
            end_table = end_table + tables_left;
        }

        k = first_factor;

        //this outer loop will store the second factor in integer i,
        //in each iteration
        for (int i = 1; i <= no_of_tables; i++)
        {
            first_factor = k; //restore first_factor to original value
            for (; first_factor <= end_table; first_factor++)
            {
                printf("%d x %d = %d\t| ", first_factor, i, first_factor*i);
            }

            printf("\n"); 
        }

        if(!((tables_left - tables_per_row) < 0))
            tables_left -= tables_per_row;
        printf("\n");
    }

    return 0;
}
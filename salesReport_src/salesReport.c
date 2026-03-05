//@author AaronTrites
#include <stdio.h>

int readFile(){

    return 0;
}

int main(){
    //Variable Declaration
    float sales[12] = {23458.01f, 40112.00f, 56011.85f, 37820.88f, 37904.67f, 60200.22f, 72400.31f, 56210.89f, 67230.84f, 68233.12f, 80950.34f, 95225.22f};
    const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float minSales = 0.0f;
    const char *minMonth;
    float maxSales = 0.0f;
    const char *maxMonth;
    float avgSales = 0.0f;

    //Read file

    //Calculate AvgSales
    for (int i = 0; i < 12; i++){
        avgSales = avgSales + sales[i]; 
    }
    avgSales = avgSales / 12.0f;

    //Sort Highest to Lowest??


    /* GENERATE REPORT */
    printf("Monthly Sales Report for 2024\n\n");

    //Monthly Sales Report
    printf("%-10s %s\n", "Month", "Sales");
    for (int i = 0; i < 12; i++){
        printf("%-10s %.2f\n", months[i], sales[i]);
    }

    //Sales Summary Report
    printf("\nSales Summary Report:\n\n");
    //Calculate minSales and maxSales
    minSales = sales[0]; //default to first month
    minMonth = months[0]; //default to first month
    for (int i = 0; i < 12; i++){
        //minSales
        if (sales[i] < minSales){
            minSales = sales[i];
            minMonth = months[i];
        }
        //maxSales
        if (sales[i] > maxSales){
            maxSales = sales[i];
            maxMonth = months[i];
        }
    }
    printf("Minimum sales:\t%.2f (%s)\n", minSales, minMonth);
    printf("Maximum sales:\t%.2f (%s)\n", maxSales, maxMonth);
    printf("Average sales:\t%.2f\n\n", avgSales);

    //Six-Month Moving Average Report
    printf("Six-Month Moving Average Report:\n\n");
    for (int i = 0; i < 7; i++){
        float temp = 0.0f;
        for (int j = 0; j < 6; j++){
            temp = temp + sales[i+j];
        }
        temp = temp / 6;
//TODO Fix the column spacing between months and temp
        printf("%s-%s %.2f\n", months[i], months[i+5], temp);
    }


    //Sales Report (highest to lowest)
    printf("\nSales Report (highest to lowest):\n\n");
    printf("%-12s %s\n", "Month", "Sales");
    printf("%-12s $%.2f\n", maxMonth, maxSales);
//TODO Sort the months by sales
    for (int i = 1; i < 11; i++){
        printf("%-12s $%.2f\n", months[i], sales[i]);
    }
    printf("%-12s $%.2f\n", minMonth, minSales);

    return 0;  
}

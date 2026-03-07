//@author AaronTrites
#include <stdio.h>

int readFile(float sales[], const char *filename){
    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error: could not open file %s\n", filename);
        return 0;
    }

    for (int i = 0; i < 12; i++){
        if (fscanf(fp, "%f", &sales[i]) != 1){
            printf("Error: invalid data in file.\n");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int main(){
    //Variable Declaration
    float sales[12];
    const char *months[12] = {
        "January", "February", "March",
        "April", "May", "June", "July", 
        "August", "September", "October",
        "November", "December"};
    float minSales = 0.0f;
    const char *minMonth;
    float maxSales = 0.0f;
    const char *maxMonth;
    float avgSales = 0.0f;

    //Read file
    if (!readFile(sales, "sales.txt")){
        return 1;
    }

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
    //Calculate AvgSales
    for (int i = 0; i < 12; i++){
        avgSales = avgSales + sales[i]; 
    }
    avgSales = avgSales / 12.0f;
    printf("Average sales:\t%.2f\n\n", avgSales);

    //Six-Month Moving Average Report
    printf("Six-Month Moving Average Report:\n\n");
    for (int i = 0; i < 7; i++){
        float temp = 0.0f;
        for (int j = 0; j < 6; j++){
            temp = temp + sales[i+j];
        }

        //Build month-month string
        char strBuffer[16];
        snprintf(strBuffer, 16, "%s-%s", months[i], months[i+5]);
        //Output Month-Month movingAvgerage
        printf("%-16s %.2f\n", strBuffer, (temp/6.0f));
    }

    //Sales Report (highest to lowest)
    printf("\nSales Report (highest to lowest):\n\n");
    printf("%-12s %s\n", "Month", "Sales");
    //Sorting algorithm (bubble sort?)
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            float temp1;
            const char *temp2;
            if (sales[j] < sales[j+1]){ //Check if next is greater
                //Swap sales
                temp1 = sales[j];
                sales[j] = sales[j+1];
                sales[j+1] = temp1;
                //Swap months
                temp2 = months[j];
                months[j] = months[j+1];
                months[j+1] = temp2;
            }
        }
    }
    //Output sorted months
    for (int i = 0; i < 12; i++) {
        printf("%-12s $%.2f\n", months[i], sales[i]);
    }

    return 0;  
}

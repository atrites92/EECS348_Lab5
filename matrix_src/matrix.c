//@author AaronTrites
#include <stdio.h>
#include "matrix.h"

//Adds two matrices
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int sum[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j =0; j < SIZE; j++){
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

//Multiples two matrices
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int product[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            product[i][j] = 0;
            for (int k = 0; k < SIZE; k++){
                product[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
}

//Takes a matrix and turns it into its transpose
void transposeMatrix(int matrix[SIZE][SIZE]){
    int transpose[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            transpose[i][j] = matrix[j][i];
        }
    }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            matrix[i][j] = transpose[i][j];
        }
    }
}

//Takes a matrix and prints it
void printMatrix(int matrix[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j= 0; j < SIZE; j++){
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    #define SIZE 5
    //Variable Declaration
    int m1[SIZE][SIZE] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
        };
    int m2[SIZE][SIZE] = {
        {25,24,23,22,21},
        {20,19,18,17,16},
        {15,14,13,12,11},
        {10,9,8,7,6},
        {5,4,3,2,1}
        };
    int mSum[SIZE][SIZE];
    int mProduct[SIZE][SIZE];
    
    //Test integrity of matrix functions:
    //Print original matrices
    printf("Matrix 1:\n");
    printMatrix(m1);
    printf("Matrix 2:\n");
    printMatrix(m2);
    //Add
    addMatrices(m1,m2,mSum);
    printf("Addition:\n");
    printMatrix(mSum);
    //Multiply
    multiplyMatrices(m1,m2,mProduct);
    printf("Multiplication:\n");
    printMatrix(mProduct);
    //Transpose
    transposeMatrix(mProduct);
    printf("Transpose:\n");
    printMatrix(mProduct);

    return 0;  
}

//@author AaronTrites
#include <stdio.h>
#include "matrix.h"

//Adds two matrices and returns the summation matrix
//THIS FUNCTION HAS NOT BEEN TESTED
int** addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    int **sum[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++){
        for (int j =0; j < SIZE; j++){
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return sum;
}

//Multiples two matrices and returns the product matrix
int multiplyMatrices(){

    return 0;
}

//Takes a matrix and returns the transpose
int transposeMatrix(){

    return 0;
}

//Takes a matrix and prints it
int printMatrix(){

    return 0;
}

int main(){
    //Variable Declaration
    int[SIZE][SIZE] m1 = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
        };
    int[SIZE][SIZE] m2 = {
        {25,24,23,22,21},
        {20,19,18,17,16},
        {15,14,13,12,11},
        {10,9,8,7,6},
        {5,4,3,2,1}
        };
    int[SIZE][SIZE] mSum;
    int[SIZE][SIZE] mProduct;
    
    //Test integrity of matrix functions:
    mSum = addMatrices(m1,m2);
    //printf(mSum);
    mProduct = multiplyMatrices(m1,m2);
    return 0;  
}

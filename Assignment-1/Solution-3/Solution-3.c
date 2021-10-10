#include<stdio.h>
#include<stdlib.h>

int main(){

    int rows,cols;
    printf("Enter the number of Rows of the 2D matrix \n");
    scanf("%d",&rows);
    printf("Enter the number of Columns of the 2D matrix \n");
    scanf("%d",&cols);
    
    int arr1[rows][cols];
    printf("Enter the 2D array\n");

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            scanf("%d",&arr1[i][j]);
    }

    int newRows=rows*cols;
    int arr2[newRows];
    int k=0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            arr2[k]=arr1[i][j];
            k++;
        }
    }

    printf("\n Final 1D array:\n");
    for(int i=0;i<newRows;i++){
        printf("%d ",arr2[i]);
    }
}
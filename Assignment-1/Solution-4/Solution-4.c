#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 10000

//Function to implement the Selection sort Algorithm. 
void selection_sort(int arr[], int n){

    for(int i=0;i<n;i++){

        int temp=arr[i];
        int min=i;

        for(int j=i+1;j<n;j++){

            if(arr[j]<temp){
                min=j;
                temp=arr[j];

            }

        }

        temp = arr[i];
        arr[i]=arr[min];
        arr[min]=temp;

    }
    
}

//Function to implement the Bubble Sort Algorithm.
void bubble_sort(int arr[], int n){

    int count=1;

    while(count<n){

        for(int i=0;i<n-count;i++){

            if(arr[i]>arr[i+1]){

                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;

            }

        }

        count++;
    }
    
}
int main(){

    printf("Enter no of elements:\n");

    int n;
    scanf("%d",&n);

    int sortedArr1[n], unsortedArr1[n],sortedArr2[n], unsortedArr2[n];
    for(int i=0;i<n;i++){

        sortedArr1[i]=i;
        sortedArr2[i]=i;
        unsortedArr1[i]=rand() % MAX;
        unsortedArr2[i]=rand( )% MAX;

    }

    clock_t start,end;

    start=clock();
    selection_sort(sortedArr1,n);
    end=clock();
    printf("Total time taken by selection sort for sorted array: %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    start=clock();
    selection_sort(unsortedArr1,n);
    end=clock();
    printf("Total time taken by selection sort for unsorted array: %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);


    clock_t start2,end2;

    start2=clock();
    bubble_sort(sortedArr2,n);
    end2=clock();
     printf("Total time taken by bubble sort for sorted array: %f seconds\n",(double)(end2-start2)/CLOCKS_PER_SEC);

    start2=clock();
    bubble_sort(unsortedArr2,n);
    end2=clock();
     printf("Total time taken by bubble sort for unsorted array: %f seconds\n",(double)(end2-start2)/CLOCKS_PER_SEC);

    
   return 0;

}
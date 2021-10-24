#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (int)1e4

//Function to generate Best case array.
void BestCaseArray(int n, int arr[]) {
  for(int i = 0; i<n; i++)
    arr[i] = i;
}

//Function to generate Worst case array.
void WorstCaseArray(int n, int arr[]) {
  for(int i = 0; i<n; i++)
    arr[i] = n-i-1;
}

//Function to generate Average case array.
void AverageCaseArray(int n, int arr[]) {
  for(int i = 0; i<n; i++)
    arr[i] = rand()%MAX;
}

//Function to perform insertion sort on the input array.
void insertionSort(int n, int arr[]) {
  int key, j;
  for (int i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {

  srand(time(0));

  int n;
  printf("Enter the size of the input : ");
  scanf("%d", &n);

  int arr[n];

  int choice;

  printf("Please Select type of Input : ");
  printf("1. Average Case\n");
  printf("2. Best Case\n");
  printf("3. Worst Case\n");
  scanf("%d", &choice);

  switch(choice) {

    case 1:
      AverageCaseArray(n, arr);
      break;

    case 2:
      BestCaseArray(n, arr);
      break;
    
    case 3:
      WorstCaseArray(n, arr);
      break;

    default:
      printf("Incorrect option\n");
      return 0;
      break;
  }

  clock_t start = clock();

  insertionSort(n, arr);

  clock_t end = clock();
  printf("Total elapsed time : %f\n", (double)(end - start)/(double)CLOCKS_PER_SEC);

  return 0;
}
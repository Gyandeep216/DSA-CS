#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Problem-a
void insertItemAtLast(int a[], int n, int key)
{
    a[n] = key;
}

//Problem-b
void insertItemAtFront(int a[], int n, int key)
{
    for (int i = n; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = key;
}

//Problem-c
void insertItemAtIndex(int a[], int n, int i, int key)
{
    for (int x = n; x > i; x--)
    {
        a[x] = a[x - 1];
    }
    a[i] = key;
}

//Problem-d
void deleteItemFromLast(int a[], int n)
{
    a[n-1]=0;
}

//Problem-e
void deleteItemFromFirst(int a[], int n)
{
    for (int x = 0; x < n-1; x++)
        a[x] = a[x+1];
}

//Problem-f
void deleteItemFromIndex(int a[], int n, int i)
{
    for (int x = i; x < n - 1; x++)
    {
        a[x] = a[x + 1];
    }
}

//Problem-g
int findItemUnsortedAsc(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
            return i + 1;
    }
    return -1;
}

int findItemUnsortedDesc(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i + 1] > a[i])
            return i + 1;
    }
    return -1;
}

//Problem-h
int findItemSortedAsc(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
            return i;
    }
    return -1;
}

int findItemSortedDesc(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
            return i;
    }
    return -1;
}

//Problem-i
void sortArray(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    return;
}

//Problem-j
int* extractSubset(int a[], int n, int i, int j)
{
    int* subset = (int*)malloc(sizeof(int)*(j-i+1));
    for (int x = i; x <= j; x++)
        subset[x-i]=a[x];
    
    return subset;
}

//Problem-k
void deleteSubset(int a[], int n, int i, int j)
{
    for(int x=i; x<n; x++){
        if(x<=j)
            a[x]=a[j+1+(x-i)];
        else 
            a[x]=0;
    }
}

//Problem-l
int* SplitIntoTwoArray(int a[], int n)
{
    return extractSubset(a, n, 0, (n-1)/2);
}

//Problem-m
void cloneArray(int a[], int n, int b[])
{
    for (int i = n; i < 2 * n; i++)
        a[i] = b[i - n];
}

//Problem-n
void shiftLeft(int a[], int n)
{
    int curr = a[0];
    for (int i = 1; i < n; i++)
        a[i - 1] = a[i];
    a[n - 1] = curr;
    return;
}

//Problem-o
void shiftRight(int a[], int n)
{
    int curr = a[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = curr;
}

//Problem-p
void rotateArrayClockwise(int a[], int n, int r)
{
    for (int i = 1; i <= r; i++)
        shiftRight(a, n);
    return;
}

//Problem-q
void rotateArrayAntiClockwise(int a[], int n, int r)
{
    for (int i = 1; i <= r; i++)
        shiftLeft(a, n);
    return;
}

//Problem-r
int FindMin(int a[], int n)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[ans])
            ans = i;
    }
    return ans;
}

//Problem-s
int FindMax(int a[], int n)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[ans])
            ans = i;
    }
    return ans;
}

//Problem-t
void fillPseudoRandom(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand();
    return;
}

//Problem-u
void fillTrueRandom(int a[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = rand();
    return;
}

//Problem-w
void SetArrayToZero(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

//Problem-x
void deleteAllItemOfArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        A[i] = 0;
}

//Problem-y
void deleteArray(int A[])
{
    free(A);
}

//Problem-z
int *allocateArray(int A[], int n)
{
    A = (int *)malloc(n * sizeof(int));
    return A;
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
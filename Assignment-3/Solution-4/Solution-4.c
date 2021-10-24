#include "ArrayLib.h"
#define MAX 1000001

int main()
{
    int n, m;
    printf("Enter the initial no of elements in Array\n");
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int)*MAX);
    printf("Enter the elements\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int key, i, j, r;
    int b[100000];
    printf("Hello\n");
    printf("Enter choice:\n0. Exit\n1. Insert item at last\n2. Insert Item At First\n3. Insert Item At Index\n4. DeleteItemFromLast\n5. Delete Item from First\n6. DeleteItemFromIndex\n7. Find Item Unsorted\n8. Find Item Sorted\n9. Sort Array\n10. ExtractSubest\n11. DeleteSubset\n12. Split Into Two Array\n13.CloneArray\n14. ShiftLeftArray\n15. ShiftRightArray\n16. RotateArrayClockwise\n17. RotateArrayAntiClockwise\n18. FindMin\n19. FindMax\n20. FillArrayPseudoRandom\n21. FillArrayTrueRandom\n22. IncreaseArraySize\n23. SetArrayToZero\n24. DeleteAllItemOfArray\n25. DeleteArray\n26. AllocateArray\n27. PrintArray\n");
    int choice;
    do
    {
        printf("\nEnter choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Operations have been performed successfully\n");
            break;
        case 1:
            printf("Enter the number to be inserted\n");
            scanf("%d", &key);
            insertItemAtLast(a, n, key);
            n++;
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 2:
            printf("Enter the number to be inserted\n");
            scanf("%d", &key);
            insertItemAtFront(a, n, key);
            n++;
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 3:
            printf("Enter the number to be inserted and enter the index respectively\n");
            scanf("%d %d", &key, &i);
            insertItemAtIndex(a, n, i, key);
            n++;
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 4:
            deleteItemFromLast(a, n);
            n--;
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 5:
            deleteItemFromFirst(a, n);
            n--;
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 6:
            printf("Enter the index to be deleted from\n");
            scanf("%d", &i);
            deleteItemFromIndex(a, n, i);
            n--;
            break;
        case 7:
            printf("Considering the array to be a ascending array, the Unsorted element is: ");
            printf("%d\n", findItemUnsortedAsc(a, n));
            printf("Considering the array to be a descending array, the Unsorted element is: ");
            printf("%d\n", findItemUnsortedDesc(a, n));
            break;
        case 8:
            printf("For ascending: ");
            printf("%d\n", findItemSortedAsc(a, n));
            printf("For descending: ");
            printf("%d\n", findItemSortedDesc(a, n));
            break;
        case 9:
            sortArray(a, n);
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 10:
            printf("Enter the starting and ending indexes of the subarray in the given array\n");
            scanf("%d %d", &i, &j);
            int * temp = extractSubset(a, n, i, j);
            printArray(temp, j-i+1);
            break;
        case 11:
            printf("Enter the the starting and ending indexed of the subset to be deleted\n");
            scanf("%d %d", &i, &j);
            deleteSubset(a, n, i, j);
            printf("Required subset has been deleted\n");
            n = n - j + i - 1;

            printf("Updated array : ");
            printArray(a, n);
            break;
        case 12:
            printf("Array after splitting:\n");
            n = n / 2 + 1;
            temp = SplitIntoTwoArray(a, n);
            SplitIntoTwoArray(temp, (n+1)/2);
            break;
        case 13:
            printf("Enter %d elements for 2nd array\n", n);
            for (int i = 0; i < n; i++)
                scanf("%d", &b[i]);
            cloneArray(a, n, b);
            n *= 2;
            printf("Cloning has been done\n");
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 14:
            shiftLeft(a, n);
            printf("Array has been shifted left\n");
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 15:
            shiftRight(a, n);
            printf("Array has been shifted right\n");
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 16:
            printf("Enter no of rotations\n");
            scanf("%d", &r);
            r = r % n;
            rotateArrayClockwise(a, n, r);
            printf("Array has been rotated\n");
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 17:
            printf("Enter no of rotations\n");
            scanf("%d", &r);
            r = r % n;
            rotateArrayAntiClockwise(a, n, r);
            printf("Array has been rotated\n");
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 18:
            printf("The index containing the minimum element is :%d\n", FindMin(a, n));
            break;
        case 19:
            printf("The index containing the maximum element is :%d\n", FindMax(a, n));
            break;
        case 20:
            fillPseudoRandom(a, n);
            printf("Array has been filled with pseudo random numbers\n");
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 21:
            fillTrueRandom(a, n);
            printf("Array has been filled with true random numbers\n");
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 22:
            printf("Enter the new size of Array\n");
            scanf("%d", &m);
            printf("Size of Array has been changed from %d to %d\n", n, m);
            if (m > n)
                printf("%d elements are filled with garbage values\n", m - n);
        case 23:
            SetArrayToZero(a, n);
            printf("Updated array : ");
            printArray(a, n);
            break;
        case 24:
            n = 0;
            printf("Elements Of array has been deleted");
            break;
        case 26:
            printf("Enter the new size of array\n");
            scanf("%d", &m);
            temp = allocateArray(a, m);
            break;
        case 27:
            printArray(a, n);
            break;
        default:
            printf("Error 404\nExit Code status X");
        }
    } while (choice >= 1 && choice <= 27);
}
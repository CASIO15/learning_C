#include "stdio.h"
#include "stdlib.h"

// Find duplicates in sorted array, using hashtable

void Hash_find_duplicate_unsorted(int *,  int);
int find_max(int *, int);

int find_max(int *arr, int length)
{
    int i, max = *++arr;

    for (i=1; i < length; i++, arr++) {
        if (*arr >= max)
            max = *arr;
    }
    return max;
}

void Hash_find_duplicate_unsorted(int *arr, int len)
{
    int i, j, length=find_max(arr, len)+1;
    int HashTable[length];

    // HashTable initialization
    for (i=0; i < length; i++)
        HashTable[i] = 0;

    // Counting duplicate occurrences.
    for (i=0; i < len; i++)
            HashTable[arr[i]]++;

    // printing
    for (i=0; i < length; i++)
        if (HashTable[i] > 1)
            printf("Duplicate found: %2d || Number of occurrences %2d\n", i, HashTable[i]);
}

int main()
{
    int arr[] = {8,3,6,4,6,8,6,5,2,7};
    size_t length = sizeof(arr)/sizeof(int);

    Hash_find_duplicate_unsorted(arr, length);
    return 0;
}

/*
 * Duplicate found:  6 || Number of occurrences  3
 * Duplicate found:  8 || Number of occurrences  2
*/

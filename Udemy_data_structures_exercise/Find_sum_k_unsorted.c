#include "stdio.h"

void find_sum_k(int *, int k, int length);
void find_sum_k_hash(int *, int k, int length);
int find_max(const int *, int len);

void find_sum_k(int *arr, int k, int len) {
    int i, j;

    for (i=0; i < len; i++)
        for (j=i + 1; j < len; j++) {
            if (arr[i] + arr[j] == k)
                printf("%d + %d = %d\n", arr[i], arr[j], k);
            if (arr[i] > k)
                break;
        }
}

int find_max(const int *arr, int len)
{
    int i, max=arr[0];

    for (i=0; i < len; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void find_sum_k_hash(int *arr, int k, int length)
{
    int i, len=find_max(arr, length)+1; // Finding the max element (using it for the length of the HashTable array).
    int HashTable[len];

    // Initializing all the elements inside HashTable to zero
    for (i=0; i <= len; i++)
        HashTable[i] = 0;

    // Iterating over the HashTable, if HashTable[k-arr[i]] != 0 (it means that the corresponding element to complete the sum
    // is also inside arr, therefore we print it).
    for (i=0; i <= length; i++) {
       if ((HashTable[k - arr[i]] >= 1 && HashTable[k-arr[i]] <= length) && arr[i] <= k)
           printf("%d + %d = %d\n", arr[i], k-arr[i], k);
       HashTable[arr[i]]++;
    }
}


int main()
{
    int arr[] = {6,3,8,10,16,7,5,2,9,5,14,0};
    size_t length = sizeof(arr)/sizeof(int);

    find_sum_k(arr, 10, length);
    printf("\n");
    find_sum_k_hash(arr, 10, length);
    return 0;
}

/*
  Result:

  *  3 + 7 = 10
  *  8 + 2 = 10
  *  10 + 0 = 10
  *  5 + 5 = 10

  * 7 + 3 = 10
  *  2 + 8 = 10
  *  5 + 5 = 10
  *  0 + 10 = 10

*/

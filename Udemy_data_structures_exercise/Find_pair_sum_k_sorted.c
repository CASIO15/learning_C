#include "stdio.h"

void find_sum_k(int *arr, int k, int length);

void find_sum_k(int *arr, int k, int length)
{
    int i,j;

    i=0, j=length-1;
    while(i < j) {
        if (arr[j] + arr[i] > k)
            j--;
        else if (arr[i] + arr[j] == k) {
            printf("%d + %d = %d\n", arr[i], arr[j], k);
            i++, j--;
        }
        else
            i++;
    }
}


int main()
{
    int arr[] = {1,3,4,5,6,7,8,9,10,12,14};
    size_t length = sizeof(arr)/sizeof(int);

    find_sum_k(arr, 26, length);
    printf("\n");
    find_sum_k(arr, 10, length);
    return 0;
}

/*
  Result:

  * 12 + 14 = 26

  * 1 + 9 = 10
  * 3 + 7 = 10
  * 4 + 6 = 10

*/

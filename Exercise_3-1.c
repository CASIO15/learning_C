#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
    int arr[20000], i, res, res2;
    for (i = 0; i <= 10000; i++){
        arr[i] = i;
    }

    res = binsearch(5005, arr, 10000);
    res2 = binsearch2(5005, arr, 10000);

    printf("Test outside: %d  Test inside: %d\n", res, res2);
}

int binsearch(int x, int v[], int n) {
    int high, mid, low, count;
    count = 0;
    low = 0;
    high = n - 1;

    while (low <= high) {
        count += 1;
        mid = (low + high) / 2;
        x > v[mid] ? (low = mid + 1) : (high = mid - 1);
        printf("%d  %d\n", count, mid);
    }

    if (low == x) {
        return low;
    }
    else {
        return -1;
    }
}


int binsearch2(int x, int v[], int n)
{
    int high, low, mid, count;
    low = 0;
    high = n-1;
    count = 0;

    printf("\n");
    while (low <= high){
        count += 1;
        mid = (low + high) / 2;

        printf("%d  %d\n", count, mid);
        if (x > v[mid]){
            low = mid + 1;
        } else if (x < v[mid]){
            high = mid - 1;
        } else
            return mid;
    }
    return -1;
}

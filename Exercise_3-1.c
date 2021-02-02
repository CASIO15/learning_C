#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
    int arr[200000], i, res, res2;
    for (i = 0; i <= 100000; i++){
        arr[i] = i;
    }

    res = binsearch(15450, arr, 100000);
    res2 = binsearch2(15450, arr, 100000);
    
    printf("Test outside: %d  Test inside: %d\n", res, res2);
}

int binsearch(int x, int v[], int n) {
    int high, mid, low;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        x > v[mid] ? (low = mid + 1) : (high = mid - 1);
    }

    if (v[mid] == x)
        return mid;
    else
        return -1;
}


int binsearch2(int x, int v[], int n)
{
    int high, low, mid;
    low = 0;
    high = n-1;

    while (low <= high){
        mid = (low + high) / 2;

        if (x > v[mid]){
            low = mid + 1;
        } else if (x < v[mid]){
            high = mid + 1;
        } else
            return mid;
    }
    return -1;
}

#include "stdio.h"
#include "stdlib.h"

/* Array abstract data type implementation */

struct Array {
    int *A;
    int size;
    int length;
};

void display(struct Array);
void append(struct Array *, int);
void insert(struct Array *, int, int);
void del(struct Array *, int);
int linear_search(struct Array *, int);
int bin_search(struct Array, int l, int r, int key);
void swap(int *, int *);
int get(int idx, struct Array *);
void set(int idx, int x, struct Array *);
int max(struct Array *);
int min(struct Array *);
int sum(struct Array *);
float avg(struct Array *);
void reverse(struct Array *);
void left_shift(struct Array *);
void left_rotate(struct Array *, int);
void right_shift(struct Array *);
void right_rotate(struct Array *, int);
void insert_sorted(struct Array *, int);
char *is_sorted(struct Array *, int, int);
void exchange_pos_neg(struct Array *);
struct Array *merge(struct Array *arr, struct Array *arr2);

struct Array *merge(struct Array *arr, struct Array *arr2)
{
    struct Array *new = (struct Array *) malloc(sizeof(struct Array));
    int i,j,k;
    
    new->size = arr->size + arr2->size;
    new->length = arr->length + arr2->length;
    new->A = (int*) malloc(sizeof(int) * new->length);

    for (i=0, k=0, j=0; i < arr->length && j < arr2->length; k++) {
        if (arr->A[i] < arr2->A[j])
            new->A[k] = arr->A[i++];
        else
            new->A[k] = arr2->A[j++];
    }

    for (; i < arr->length; i++)
        new->A[k++] = arr->A[i];

    for (; j < arr2->length; j++)
        new->A[k++] = arr2->A[j];

    new->A[++k] = '\0';
    return new;
}

void exchange_pos_neg(struct Array *arr)
{
    int i, j;

    for (i=0, j=arr->length-1; i < j; ) {
        if (arr->A[i] < 0)
            i++;
        if (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

// 10 9 8 7 6 5 4 3 2 1 -1 -2 -3 -5 -9 -10 10 0 0 --> -10 -9 -5 -3 -2 -1 3 2 1 4 5 6 7 8 9 10 0 10 0

char *is_sorted(struct Array *arr, int start, int end)
{
    static unsigned int count=0;

    if (end < arr->length && start < end)
        if (arr->A[start] <= arr->A[end]) {
            count++;
            is_sorted(arr, start+1, end+1);
        }
    return (count == arr->length-1) ? "The array is sorted" : "The array is not sorted";
}

void insert_sorted(struct Array *arr, int n)
{
    int i, idx=arr->length;

    for (i=arr->length-1; arr->A[i] >= n; idx--, i--)
        arr->A[i+1] = arr->A[i];
    arr->length++;
    arr->A[idx] = n;
}

void right_shift(struct Array *arr)
{
    int i, j, temp;

    for (i=arr->length-2, j=arr->length-1; j > 0; j--, i--) {
        temp = arr->A[i];
        arr->A[j] = arr->A[i];
        arr->A[i] = temp;
    }
    arr->A[0] = 0;
}

void right_rotate(struct Array *arr, int offset)
{
    int i, j, arr_cpy[offset];
    if (offset <= arr->length) {
        for (i = arr->length - 1, j = 0; i >= arr->length - offset; i--, j++)
            arr_cpy[j] = arr->A[i];

        for (i = 0; i < offset; i++)
            right_shift(arr);

        for (i = 0, j = offset - 1; i < offset; i++, j--)
            arr->A[i] = arr_cpy[j];
    } else
        printf("Error: the offset is invalid\n");
}

void left_rotate(struct Array *arr, int offset)
{
    int i, j, arr_cpy[offset];

    if (offset <= arr->length) {
        for (i = 0; i < offset; i++)
            arr_cpy[i] = arr->A[i];

        for (i = 0, j = offset; j < arr->length; j++, i++)
            arr->A[i] = arr->A[j];

        for (i = arr->length - offset, j = 0; i < arr->length; i++, j++)
            arr->A[i] = arr_cpy[j];
    } else
        printf("Error: the offset is invalid\n");
}

void left_shift(struct Array *arr)
{
    int i, j, temp;

    for (i=0, j=1; j < arr->length; j++, i++) {
        temp = arr->A[j];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
    arr->A[arr->length-1] = 0;
}

void reverse(struct Array *arr)
{
    int i, j;

    for (i=0, j=arr->length-1; i < j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

float avg(struct Array *arr)
{
    return ((float) sum(arr)) / arr->length;
}

int sum(struct Array *arr)
{
    int sum=0, i;

    for (i=0; i < arr->length; i++)
        sum += arr->A[i];
    return sum;
}

int max(struct Array *arr)
{
    int max=arr->A[0], i;

    for (i=1; i < arr->length; i++)
        (max < arr->A[i]) ? max = arr->A[i] : 0;
    return max;
}

int min(struct Array *arr)
{
    int min=arr->A[0], i;

    for (i=1; i < arr->length; i++)
        (min > arr->A[i]) ? min = arr->A[i] : 0;
    return min;
}

int get(int idx, struct Array *arr)
{
    if (idx >= 0 && idx < arr->length)
        return *(arr->A+idx);
    return -1;
}

void set(int idx, int x, struct Array *arr)
{
    if (idx >= 0 && idx < arr->length)
        arr->A[idx] = x;
}

void swap(int *s, int *t)
{
    int temp;

    temp = *s;
    *s = *t;
    *t = temp;
}

void display(struct Array arr)
{
    int i;
    printf("-----------------\n");
    printf("The elements are:\n");
    printf("-----------------\n");

    for (i = 0; i < arr.length; arr.A++, i++)
        printf("%d ", *arr.A);
}

int bin_search(struct Array arr, int l, int r, int key)
{
    int mid;

    while (l <= r) {
        mid = (l+r)/2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int linear_search(struct Array *arr, int item)
{
    int i;

    for (i=0; i < arr->length; i++)
        if (arr->A[i] == item) {
            /* Improving linear search */

            //swap(&arr->A[i], &arr->A[i-1]);
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    return -1;
}


void del(struct Array *arr, int index)
{
    int i;

    for (i=index; i < arr->length-1; i++)
        arr->A[i] = arr->A[i+1];

    arr->length--;
}

void append(struct Array *arr, int n)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = n;
    else
        printf("There is not enough space |arr size = %d|\n", arr->length);
}

void insert(struct Array *arr, int index, int n)
{
    int i;

    for (i = arr->length; index < i; i--)
        arr->A[i] = arr->A[i-1];
    arr->A[i] = n;
    arr->length++;
}


int main ()
{
    int i, n, new_arr[] = {1,2,3,4,5,6,7,8,9,10};
    struct Array arr;
    struct Array arr2;

    arr2.length = arr2.size = 10;
    arr2.A = (int*) malloc(sizeof(int) * arr2.length);
    arr2.A = new_arr;

    printf("Enter the size of an array:");
    scanf("%d", &arr.size);

    arr.A = (int *) malloc(arr.size * sizeof(int));
    arr.length=0;

    printf("How many elements the array will contain ?");
    scanf("%d", &n);

    printf("Enter all elements:");
    for (i=0; i < n; i++)
        scanf("%d", &arr.A[i]);

    arr.length = n;
    //display(arr);
    //printf("\n10 is at index %d\n", bin_search(arr, 0, arr.size, 10));
    //printf("\n10 is at index %d\n", linear_search(&arr, 10));
    //set(4, 101, &arr);
    //display(arr);
    //printf("\nThe max element is %d\n", max(&arr));
    //printf("\nThe min element is %d\n", min(&arr));
    //printf("\nThe element is: %d", get(0, &arr));
    //printf("\nThe sum of all the elements = %d | and the average is %g\n", sum(&arr), avg(&arr));
    //reverse(&arr);
    //left_shift(&arr);
    //left_rotate(&arr, 7);
    //right_shift(&arr);
    //right_rotate(&arr, 3);
    //insert_sorted(&arr, 18);
    //exchange_pos_neg(&arr);
    display(*merge(&arr, &arr2));
    //printf("\n%s\n", is_sorted(&arr, 0, 1));
    free(arr.A);
    return 0;
}

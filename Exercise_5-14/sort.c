
void my_qsort(void *lineptr[], int left, int right, int (*comp) (void *, void *), int reverse);

void my_qsort(void *lineptr[], int left, int right, int (*comp) (void *, void *), int reverse)
{
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right)
        return;
    swap(lineptr, left, (left+right)/2);
    last = left;

    for(i=left+1; i <= right; i++) {
        if (reverse && (*comp)(lineptr[i], lineptr[left]) < 0) // if sort flag is on (1), sort in decreasing order
            swap(lineptr, ++last, i);
        if (!reverse && (*comp)(lineptr[i], lineptr[left]) > 0) // if sort flag is off (0), sort in ascending order
            swap(lineptr, ++last, i);
    }
    swap(lineptr, left, last);
    my_qsort(lineptr, left, last-1, comp, reverse);
    my_qsort(lineptr, last+1, right, comp, reverse);

}


void swap(void *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

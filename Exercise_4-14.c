#include <stdio.h>

#define swap(t, x, y) {t temp; temp = x; x = y; y = temp;}

int main()
{

    int x = 1, y = 2;
    printf("Before x=%d y=%d\n", x, y);

    swap(int, x ,y);
    printf("After x=%d y=%d\n", x, y);

    return 0;
}

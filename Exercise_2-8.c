#include <stdio.h>

#define BYTESIZE 8
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)   \
  (byte & 128 ? '1' : '0'),    \
      (byte & 64 ? '1' : '0'), \
      (byte & 32 ? '1' : '0'), \
      (byte & 16 ? '1' : '0'), \
      (byte & 8 ? '1' : '0'),  \
      (byte & 4 ? '1' : '0'),  \
      (byte & 2 ? '1' : '0'),  \
      (byte & 1 ? '1' : '0')


unsigned rightrot(unsigned x, int n);

int main()
{
    unsigned x = 0b10011101;

    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(rightrot(x, 4)));
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    unsigned mask_x, mask_y;

    mask_x = x >> n;
    mask_y = x << (BYTESIZE-n);

    return mask_y ^ mask_x;
}

/*
 *  00001001
XOR
 *  11010000
 *  --------
 *  11011001
 */

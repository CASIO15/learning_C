#include <stdio.h>

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

unsigned setbits(int x, int p, int n, int y);

int main()
{
    unsigned int x = 0b00001010;
    unsigned int y = 0b10011001;

    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(setbits(x, 0, 4, y)));
    return 0;
}

unsigned setbits(int x, int p, int n, int y)
{
    p++;
    unsigned int mask_x, mask_y;
    mask_y = (~(~0 << n) & y) << (p-1);
    mask_x = (~(~0 << (p-1)) & x);

    return mask_x | mask_y;
}

/*
 x = 0b00001010 |10|
 y = 0b10011001 |153|
 -------------------------
 correct result = 00100110
 -------------------------
 
 mask_x = 00000010
 mask_y = 00100100
 
 -----------------
 
 mask_x = 00000010
or
 mask_y = 00100100
 ------------------
 result = 00100110 |38|
 
 */

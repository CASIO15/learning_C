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
    unsigned int x = 0b11111111;
    unsigned int y = 0b00001010;
    
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(setbits(x, 5, 7, y)));
    return 0;
}

unsigned setbits(int x, int p, int n, int y)
{
    unsigned int mask_x, mask_y;
    mask_x = x >> (7-n) & x << (p-1);
    mask_y = y << (p-1);

    return ~mask_x | mask_y;
}

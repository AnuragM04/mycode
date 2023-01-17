#include <stdio.h>

int main()
{
    // Binary Notation - Base - 2 
    // 000  -- 0*2^2 + 0*2^1 + 0*2^0
    // 001  -- 0*2^2+ 0*2^1 + 1*2^0    --- 1
    // 010  -- 0*2^2 + 1*2^1 + 0*2^0   --- 2
    // 011  -- 0*2^2 + 1*2^1 + 1*2^0   --- 3
    // 100  -- 1*2^2 + 0*2^1 + 0*2^0   --- 4

    // Decimal - 10
    // 376 - 3*10^2 + 7*10^1 + 6*10^0 ---- 376

    // HexaDecimal - 16
    // 0x376 - 3*16^2 + 7*16^1 + 6*16^0 ---  886

    // Octal - 8
    // 0o376 - 3*8^2 + 7*8^1 + 6*8^0 ---  110

    // 1 byte - 8 bits --- 0 - 2^8
    // char - signed 8 bits ----  -ve & +ve 8bits they use one bit for sign -2^7 --- +2^7
    // unsigned char --- all +ve  ---range of 0 - 2^8
    // short -- signed 2 bytes - 16 bits --- range of  -2^15 --- +2^15 .... one bit reserved for sign.
    // unsigned short --- all +ve 16 bits ---- range of -- 0 --- 2^16
    // int --- singed 32 bits .... range of -2^31 --- +2^31 -- one bit reserved for sign


    // Decimal - 10
    // 376 - 3*10^2 + 7*10^1 + 6*10^0

    short s = 20;
    int i = 50;
    float f = 5.9345;

    printf("Decimal - %d\n", i);
    printf("Hex - %x\n", i);
    printf("Octal - %o\n", i);

    printf("Decimal - %d\n", s);
    printf("Hex - %x\n", s);
    printf("Octal - %o\n", s);

    printf("F - %.2f\n", f);

    i = (int)f;
    printf("I - %d\n", i);

    f = (float)s;
    printf("F - %.2f\n", f);

    i = (int)s;
    printf("I - %d\n", i);

    i = 376345345;
    printf("I - %d\n", i);

    s = (short)i;
    printf("S - %d\n", s);

    char ch = 127;
    printf("C - %d\n", ch);

    ch = (char)1300;
    printf("C - %d\n", ch);

    char cb = 20;
    if (ch == cb) {
        printf("Both are same\n");
    }

    for (int k=0;k<701; k++){
        ch = (char) k;
        printf("%d\n", ch);
    }

    
    return 0;
}

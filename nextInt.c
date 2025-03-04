#include <stdio.h>

int glyph2int(char glyph, int radix)
{
    int digit;
    if ('0' <= glyph && glyph <= '9')
    {
        digit = glyph - '0';
    }

    else if ('A' <= glyph && glyph <= 'Z')
    {
        digit = glyph - 'A';
        digit = digit + 10;
    }

    else if ('a' <= glyph && glyph <= 'z')
    {
        digit = glyph - 'a';
        digit = digit + 10;
    }

    else
    {
        digit = -1;
    }

    if (digit > (radix - 1))
    {
        digit = -1;
    }

    return digit;
}

int nextInt(int radix)
{
    int number;
    int digit;
    int count;
    char buffer[256];

    number = 0;
    count = 0;
    const int MAX_LENGTH = 256;

    // read actual number
    printf("Enter the value for the number: ");
    fgets(buffer, MAX_LENGTH, stdin);

    digit = glyph2int(buffer[0], radix);

    while (digit != -1)
    {
        number = (number * radix) + digit;
        count++;
        digit = glyph2int(buffer[count], radix);
    }
    printf("%d\n", number);
    return number;
}

int main()
{
    int radix;
    char buffer[256];
    const int MAX_LENGTH = 256;

    // read input for radix
    printf("Enter the value for the radix: ");
    scanf("%d", &radix);
    while (getchar() != '\n'); // clear input

    // call nextInt
    nextInt(radix);
    return 0;
}

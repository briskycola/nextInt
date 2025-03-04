# nextInt:

This is a C implementation of the nextInt(int radix) method part of the Scanner class in Java. This program
essentially reads an array of ASCII characters and then, given the specified radix, converts the number into
the equivalent number in base 10. For example, with the radix `16`, the string `AA` will be converted to `170`.

## Components:

This program consists of the following functions
    1. `glyph2int(char glyph, int radix)`
        - This function reads a single ASCII character and returns the
        associated value for the glyph within the given radix

        - Ex: The character B will be returned as 11
        (`B` - `A` + `10`) = (`66` - `65` + `10`) = `11`

    2. `nextInt(int radix)`
        - This method will call `glyph2int` for every char
        in the array until EOF.

        - The following algorithm will be applied to properly
        sum the values, given the radix, into a final base 10 number.
        ```c
        while (digit != -1)
        {
            number = (number * radix) + digit;
            count++;
            digit = glyph2int(buffer[count], radix);
        }
        ```

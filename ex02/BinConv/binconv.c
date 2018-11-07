// Include the standard input output libray for printing.
#include <stdio.h>
// Include the special int libary for defining special int types.
#include <stdint.h>

// This is the entry point of the program.
int main()
{
    // Defines an unsigned 16 bit integer which is going to be converted.
    uint16_t ToConvert = 3091;

    // This is an array of 0 characters, which is going to be filled.
    char BinaryRepresentation[16] = "0000000000000000";

    // An array of all the powers of two up to 15 in reversed order.
    int PowerArray[16] = {32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

    // Copies the value of ToConvert into a new unsigned 16 bit integer called x.
    uint16_t x = ToConvert;

    // Starts a for-loop with counter i, going from 0 to 15.
    for (int i = 0; i < 16; i++)
    {
        // If x is greater than the i-th index of the power array.
        if (x >= PowerArray[i])
        {
            // Substract the value of the power array from x.
            x -= PowerArray[i];
            // Sets the i-th index of the Binary representation to the character '1'.
            BinaryRepresentation[i] = '1';
        }
    }

    // Prints the computed result.
    printf("%d = %s\n", ToConvert, BinaryRepresentation);

    // Returns 0, to satisfy the main functions requirement to return an int.
    // The 0 indicates that the program ran successfully.
    return 0;
} // This is the end of the main function.

// if (x >= 32768)
// {
//     x -= 32768;
//     BinaryRepresentation[0] = '1';
// }
// if (x >= 16384)
// {
//     x -= 16384;
//     BinaryRepresentation[1] = '1';
// }
// if (x >= 8192)
// {
//     x -= 8192;
//     BinaryRepresentation[2] = '1';
// }
// if (x >= 4096)
// {
//     x -= 4096;
//     BinaryRepresentation[3] = '1';
// }
// if (x >= 2048)
// {
//     x -= 2048;
//     BinaryRepresentation[4] = '1';
// }
// if (x >= 1024)
// {
//     x -= 1024;
//     BinaryRepresentation[5] = '1';
// }
// if (x >= 512)
// {
//     x -= 512;
//     BinaryRepresentation[6] = '1';
// }
// if (x >= 256)
// {
//     x -= 256;
//     BinaryRepresentation[7] = '1';
// }
// if (x >= 128)
// {
//     x -= 128;
//     BinaryRepresentation[8] = '1';
// }
// if (x >= 64)
// {
//     x -= 64;
//     BinaryRepresentation[9] = '1';
// }
// if (x >= 32)
// {
//     x -= 32;
//     BinaryRepresentation[10] = '1';
// }
// if (x >= 16)
// {
//     x -= 16;
//     BinaryRepresentation[11] = '1';
// }
// if (x >= 8)
// {
//     x -= 8;
//     BinaryRepresentation[12] = '1';
// }
// if (x >= 4)
// {
//     x -= 4;
//     BinaryRepresentation[13] = '1';
// }
// if (x >= 2)
// {
//     x -= 2;
//     BinaryRepresentation[14] = '1';
// }
// if (x >= 1)
// {
//     x -= 1;
//     BinaryRepresentation[15] = '1';
// }
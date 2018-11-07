// Include the standard input output libray for printing.
#include <stdio.h>
// Include special integer types in the program.
#include <stdint.h>

// This is the entry point of the program.
int main()
{
  // Declares a_16, b_16, c_16 as 16 bit integers.
  int16_t a_16, b_16, c_16;
  // Declares a_32, b_32, c_32 as 32 bit integers.
  int32_t a_32, b_32, c_32;
  // Declares a_u16, b_u16, c_u16 as an unsinged 16 bit integer.
  uint16_t a_u16, b_u16, c_u16;

  // Sets b_16 and a_16 to the value of 22222.
  b_16 = a_16 = 22222;
  // Sets b_32 and a_32 to the value of 22222.
  b_32 = a_32 = 22222;

  // Stores the result a_32 + b_32 in c_32.
  c_32 = a_32 + b_32;
  // Same for a_16 + b_16.
  c_16 = a_16 + b_16;

  // Prints the result of a_32 + b_32 with special formating.
  printf("a_32 + b_32 = %d + %d = %d \n\n", a_32, b_32, c_32);
  // Prints the result of a_16 + b_16 with special formating.
  printf("a_16 + b_16 = %hd + %hd = %hd\n\n", a_16, b_16, c_16);

  // Store the result of a_16 + c_32 in a_u16.
  a_u16 = a_16 + c_32;

  // Prints the result of the last operation with special formating.
  printf("a_16 + c_32 = %hd + %d = %hu\n\n", a_16, c_32, a_u16);

  // Sets a_u16 to the value of 2222.
  a_u16 = 2222;
  // Sets b_u16 to the value of -222, which doesn't really work,
  // because b_u16 is an unsinged integer, so it gets set to 65314 instead.
  b_u16 = -222;
  // Stores the result of a_u16 + b_u16 in c_u16.
  c_u16 = a_u16 + b_u16;
  // Prints the result of the previous operation, with special formating.
  // Also here there was extra cation taken to include the singed
  // value of the variable.
  printf("a_u16 + b_u16 = %hu(=%hd) + %hu(=%hd) = %hu(=%hd)\n\n", a_u16,
         a_u16, b_u16, b_u16, c_u16, c_u16);

  // Sets a_32 to the value of 555.
  a_32 = 555;
  // Sets b_32 to the value of 1001.
  b_32 = 1001;
  // Stores the result of a_32 * b_32 into c_32,
  // and sets c_16 to the value of c_32. This
  // causes an integer overflow in c_16.
  c_16 = c_32 = a_32 * b_32;
  // Prints what operation was done.
  printf("c_16 = c_32 = a_32 * b_32\n");
  // Prints the actual result of the operation, showing that
  // c_16 overflowed.
  printf("%hd = %d = %d * %d\n\n", c_16, c_32, a_32, b_32);
  // Stores the value of a_32 * b_32 into c_16, which
  // causes and integer overflow, this overflown value
  // gets stored into c_32.
  c_32 = c_16 = a_32 * b_32;
  // Prints what operation was done.
  printf("c_32 = c_16 = a_32 * b_32\n");
  // Shows that the ordering of variable assignment
  // is important.
  printf("%d = %hd = %d * %d\n\n", c_32, c_16, a_32, b_32);

  // Returns 0, to satisfy the main functions requirement to return an int.
  // The 0 indicates that the program ran successfully.
  return 0;
} // End of the main function.

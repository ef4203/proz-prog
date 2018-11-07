// The program will use the standard input/output libary.
#include <stdio.h>

// Adds special aliases for certain integer types.
#include <stdint.h>

// The Entry point of the program.
int main()
{
  // Defines y and z as 16 bit integers with values 1024 and 65 respectively.
  int16_t y = 1024, z = 65;

  // Sets y to the value of y times z.
  // But because z is limited to 16 bits only this creates an
  // integer overflow, coincidentally (or not) resulting in 1024.
  y = y * z;

  // And now outputs the value of y.
  printf("1. Ausgabe: %d\n", y);

  // Outputs the result of the expression y / 3 * 3 - 3 * / 3.
  // When dividing by y by 3 the remainder of 1/3rd gets cut off,
  // and when multiplying by 3 again, theres an entire 1 missing.
  // Then you substract the same operation but in reverse other,
  // where the remainder of the division doesn't get cut of
  // because you have multiplied by 3 before.
  printf("2. Ausgabe: %d\n", y / 3 * 3 - 3 * y / 3);

  // Outputs a new (empty) line.
  printf("\n");

  // Returns 0 to satisfy the main functions requirement to return an integer.
  return 0;

} // End of the main function.

// Include the standard input output libray for printing.
#include <stdio.h>

// This is the entry point of the program.
int main()
{
    // Sets the size of the diamond/lozenge as n.
    int n = 4;

    // Start a for loop with until the the iterator hits n.
    // This will print the first half of the shape.
    for (int i = 1; i <= n; i++)
    {
        // Print some spaces for centering the shape.
        printf("%*s", (n - i) * 2, "");

        // Start a nested loop iterating until the current i.
        for (int j = 1; j <= i; j++)
        {
            // Print the current value of j with a space after it.
            printf("%d ", j);
        }
        // Start another nested loop iteration from current i - 1 until 1.
        for (int k = i - 1; k > 0; k--)
        {
            // Print the current value of k with a space.
            printf("%d ", k);
        }
        // Print a new line character.
        printf("\n");
    }

    // Start another loop, from n - 1 to 1.
    // This will print the lower part of the shape.
    for (int i = n - 1; i > 0; i--)
    {
        // Print some spaces for centering the shape.
        printf("%*s", (n - i) * 2, "");

        // Start a nested loop iterating until the current i.
        for (int j = 1; j <= i; j++)
        {
            // Print the current value of j with a space after it.
            printf("%d ", j);
        }
        // Start another nested loop iteration from current i until 1.
        for (int k = i - 1; k > 0; k--)
        {
            // Print the current value of k with a space.
            printf("%d ", k);
        }
        // Print a new line character.
        printf("\n");
    }

    // Returns 0, to satisfy the main functions requirement to return an int.
    // The 0 indicates that the program ran successfully.
    return 0;
} // This is the end of the main function.

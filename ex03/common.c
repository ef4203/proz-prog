double factorial(int n)
{
    if (n == 1)
        // Return 1 if n is 1.
        return 1;
    else
        // Other wise multiply n by n-1 factorial.
        return n * factorial(n - 1);
}

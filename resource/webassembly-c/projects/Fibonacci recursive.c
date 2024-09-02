#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int result = fibonacci(20); // Change this value based on the desired difficulty
    return result;
}

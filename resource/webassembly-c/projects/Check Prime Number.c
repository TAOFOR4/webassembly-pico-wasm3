int isPrime(int num)
{
    if (num <= 1)
        return 0; // zero and one are not prime
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

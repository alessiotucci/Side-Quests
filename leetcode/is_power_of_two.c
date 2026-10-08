bool isPowerOfTwo(int n)
{
    // edge case, n is zero!
    if (n == 0)
        return (false);
    // base case, end the recursion
    if (n == 1 || n == 2)
        return (true);
    // odd number, cannot be a power of two
    if (n % 2 != 0)
        return (false);
    else
        return (isPowerOfTwo(n / 2));
    
}

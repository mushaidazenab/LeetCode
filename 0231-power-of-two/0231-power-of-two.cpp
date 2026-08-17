class Solution {
public:
bool isPowerOfTwo(int n)
{
    // bitwise manipulation
    // we know any number whch is power of two will have only one '1'
    // in its binary, and the number right before it will have all '1's except
    // at the  place where that particualr number (power of two) has '1'
    // in its binary
    // => AND operation of n and n -1 should evaluate to 0000 if n is some power
    // of two
    if (n <= 0)
    {
        return false;
    }
    if ((n & (n - 1)) == 0)
    {
        return true;
    }
    return false;
}
};
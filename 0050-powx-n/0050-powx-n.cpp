class Solution {
public:

double solve(double x, long long n)
{
    if (n == 0)
    {
        return 1.0;
    }
    double half = solve(x, n / 2);
    if (n % 2 == 0)
    {
        return half * half;
    }
    else
    {
        return x * half * half;
    }
}
double myPow(double x, int n)
{
    long long N = n; //we cast it to long lon gn to avoid overflow
    //in signed integers, range is 2,147,483,647 to -2,147,483,648 
    // notice that +ve int have one count less than -ve int 
    // if someone passes n = -2,147,483,648  and we do -( -2,147,483,648)
    // see that we go out of bounds, hence the conversion to long long
    if (N < 0)
    {
        return 1.0 / solve(x, -N);
    }
    return solve(x, N);
}
};

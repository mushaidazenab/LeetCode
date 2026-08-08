class Solution {
public:
int mySqrt(int x)
{
    int left = 0, right = x;
    int res = 0;
    double mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (mid * mid > x)
        {
            right = mid - 1;
        }
        else if (mid * mid < x)
        {
            left = mid + 1;
            res = mid;
        }
        else
            return mid;
    }
    return res;
}
};
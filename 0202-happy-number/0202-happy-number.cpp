class Solution {
public:
bool isHappy(int n)
{
    int holder;
    int sum = 0;
    unordered_set<int> seen;
    // seen.insert(n);
    while (n != 0)
    {
        holder = n % 10;
        sum += (holder * holder);

        n /= 10;

        if (n == 0)
        {
            if (sum == 1)
            {
                return true;
            }
            n = sum;
            if (seen.count(sum) == 1)
                return false;
            seen.insert(sum);
            sum = 0;
        }
    }
    return false;
}
};
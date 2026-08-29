class Solution {
public:
int maxProduct(vector<int> &nums)
{
    int res = *max_element(nums.begin(), nums.end());
    int currMax = 1, currMin = 1;
    for (int n : nums)
    {
        if (n == 0)
        {
            currMax = 1, currMin = 1;
            continue;
        }

        int temp = currMax;
        currMax = max({n * currMax, n * currMin, n});
        currMin = min({temp * n, n * currMin, n});
        res = max(currMax, res);
    }
    return res;
}
};
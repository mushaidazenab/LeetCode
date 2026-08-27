class Solution {
public:
int maxSubArray(vector<int> &nums)
{
    int maxSub = nums[0];
    int currentSum = 0;

    for (int n : nums)
    {
        if (currentSum < 0)
            currentSum = 0;

        currentSum += n;
        maxSub = max(maxSub, currentSum);
    }

    return maxSub;
}
};
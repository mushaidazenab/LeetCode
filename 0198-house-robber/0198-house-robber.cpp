class Solution {
public:
int rob(vector<int> &nums)
{
    int prev1 = 0; // stores max till on ehouse before the current house - incase we'd want to skip the current house
    int prev2 = 0; // stores max till two houses before the current house - incase we'd want to rob the current house
    for (int n : nums)
    {
        int currentMax = max(n + prev2, prev1);
        prev2 = prev1;
        prev1 = currentMax; // n is basically teh current house we're looking at
        }
    return prev1;
}
};
class Solution {
public:
vector<int> findMissingElements(vector<int> &nums)
{
    // sort in ascending
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }

    vector<int> missingNos;
    int prev = nums[0];
    // brute force approach
    for (int i = 0; i < nums.size(); i++)
    {
        while (nums[i] != prev)
        {
            missingNos.push_back(prev);
            prev++;
        }
        prev++;
    }
    return missingNos;
}
};

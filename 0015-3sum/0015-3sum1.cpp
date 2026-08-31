class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            int a = nums[i];

            // skip duplicate values for the first element
            if (i > 0 && a == nums[i - 1])
            {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r)
            {
                int threeSum = a + nums[l] + nums[r];

                if (threeSum > 0)
                {
                    r--;
                }
                else if (threeSum < 0)
                {
                    l++;
                }
                else
                {
                    res.push_back({a, nums[l], nums[r]});
                    l++;

                    // skip duplicate values for the second element
                    while (nums[l] == nums[l - 1] && l < r)
                    {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};

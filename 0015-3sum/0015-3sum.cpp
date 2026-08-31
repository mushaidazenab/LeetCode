class Solution {
public:
   vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    int n = nums.size();

    // sort the array
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i)
    {
        // since the array is sorted, if nums[i] > 0 => the numbers are postive
        // nth after it can really add up to zero, we need -ve no. as well for that
        if (nums[i] > 0)
            break;

        // skip duplicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                // skip duplicates for left and right pointers
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0)
            {
                left++; // sum too small
            }
            else
            {
                right--; // sum too large
            }
        }
    }

    return result;
}
};
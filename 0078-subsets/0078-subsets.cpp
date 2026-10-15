class Solution {
void generateSubsets(const vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result)
    {
        // base case: all elements have been considered
        if (index == nums.size())
        {
            result.push_back(current);
            return;
        }

        // option 1: exclude the current element
        generateSubsets(nums, index + 1, current, result);

        // option 2: include the current element
        current.push_back(nums[index]);
        generateSubsets(nums, index + 1, current, result);
        
        // backtrack to restore the state before returning
        current.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(nums, 0, current, result);
        return result;
    }
};
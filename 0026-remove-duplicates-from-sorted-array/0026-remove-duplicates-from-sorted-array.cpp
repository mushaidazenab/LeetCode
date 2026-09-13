class Solution {
public:

int removeDuplicates(vector<int> &nums)
{
    int size = nums.size();
    int left = 1, right = 1; //starting both at index 1 bcz 0th index will always be unique

    for (right = 1; right < size; right++)
    {
        if (nums[right] != nums[right - 1])
        {
            nums[left] = nums[right];
            left++;
        }
    }
    return left;
}
};
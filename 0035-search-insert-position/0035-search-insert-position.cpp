class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
    if(nums.empty()) return 0;

    int left = 0, right = nums.size() - 1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(nums[mid] == target)
            return mid;
        else if(target > nums[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left; //why left? dry run it for nums = { 4 } and target = 2 and for target= 5
}
};
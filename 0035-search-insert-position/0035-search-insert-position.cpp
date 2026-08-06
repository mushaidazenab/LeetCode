class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
    // brute force
    if(nums.empty()) return 0;

    int i;
    for(i = 0; i < nums.size(); i++){
        if(nums[i] == target || nums[i] > target){
            return i;
        }
    }

    return i; // incase we want to insert at end (i.e. none of nums[i] > target)
}
};
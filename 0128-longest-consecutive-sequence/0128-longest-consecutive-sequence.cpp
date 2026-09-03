class Solution {
public:int longestConsecutive(vector<int> &nums)
{
    // so for this problem, we're gonna first store all the values in a hashset
    // for every value in nums, we re gonna see if there exists a number
    //  to its left in the number line hence we do find(n-1)
    int longest = 0; // holds the size of longest sequence
    unordered_set<int> numSet(nums.begin(), nums.end());
    // notice that i used numSet (hashset) here instead of nums (array)
    //  thats bcs the array might contain duplicates whereas a hashset is gauranteed to have unique values
    //  so using array here exceeds the time limit
    for (int n : numSet)
    {
        // find returns numSet.end() if it can not find nums(n-1) throughout the array
        // if (n - 1) is not found => n is the start of the sequence
        if (numSet.find(n - 1) == numSet.end())
        {
            int length = 0;
            // as long as n+length exists, increment length (length acts s both an offset (relative to n) and a counter for sequence length)
            while (numSet.find(n + length) != numSet.end())
            {
                length++;
            }
            longest = max(longest, length);
        }
    }
    return longest;
}
};
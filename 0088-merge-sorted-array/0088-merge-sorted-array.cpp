class Solution {
public:
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // m = nums 1, n = nums2
    int last = m + n - 1; // last index of nums1
    while (m > 0 && n > 0)
    {
        if (nums1[m - 1] > nums2[n - 1])
        {
            nums1[last] = nums1[m - 1];
            m--;
        }
        else
        {
            nums1[last] = nums2[n - 1];
            n--;
        }
        last--;
    }
    // adding left over values from nums 2 in nums 1 (if any)
    while (n > 0)
    {
        nums1[last] = nums2[n - 1];
        n--;
        last--;
    }
}
};
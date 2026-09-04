class Solution {
public:
int maxArea(vector<int> &height)
{
    // brute force
    // int res = 0;
    // int area;
    // // i = left, j = right
    // for (int i = 0; i < height.size(); i++)
    // {
    //     for (int j = i + 1; j < height.size(); j++)
    //     {
    //         area = (j - i) * min(height[i], height[j]);
    //         res = max(area, res);
    //     }
    // }
    // return res;

    int res = 0;
    int left = 0, right = height.size() - 1;
    int area;
    while (left < right)
    {
        area = (right - left) * min(height[left], height[right]);
        res = max(area, res);
        if (height[left] > height[right])
        {
            right--;
        }
        else if (height[right] > height[left])
        {
            left++;
        }
        else // we can essentially move any pointer in this scenario (when height[l] == height[r])
        {
            left++;
        }
        // we could condense else if and else into a single else condition but id let it stay as is so its easier to understand later
    }
    return res;
}
};
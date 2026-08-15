class Solution {
public:

int majorityElement(vector<int> &nums)
{
    //soln using hashmaps - better soln exists
    unordered_map<int, int> count;
    int reqNum = 0, maxCount = 0;

    for (int n : nums)
    {
        count[n]++;
        if (count[n] > maxCount)
        {
            reqNum = n;
            maxCount = count[n];
        }
    }

    return reqNum;
}

};

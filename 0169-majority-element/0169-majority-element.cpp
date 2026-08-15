class Solution {
public:

int majorityElement(vector<int> &nums)
{
    // using boyer moore algorithm - it is gauranteed to work if
    //  majority element exists

    int reqNum = 0, count = 0;
    for (int n : nums)
    {
        if (count == 0)
            reqNum = n;
        if (reqNum == n)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return reqNum;
}

};
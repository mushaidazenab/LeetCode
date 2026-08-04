class Solution {
public:
vector<int> findMissingElements(vector<int> &nums)
{
    int max = nums[0];
    int min = nums[0];
    // store max and min
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > max)
            max = nums[i];
        if (nums[i] < min)
            min = nums[i];
    }
    // sort in ascending
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    int sizeOfRequiredArray = max - min + 1;

    vector<int> missingNos;
    int missingNosIndex = 0;

    cout << endl
         << "missing numbers: ";

    int j = 0; // nums

    while (j < nums.size())
    {
        if (nums[j] != min)
        {
            missingNos.push_back(min);
            cout << min << " ";
            min++;
            // j++;
            continue;
        }
        min++;
        j++;
    }
    return missingNos;
}
};
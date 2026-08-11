class Solution {
public:
vector<int> replaceElements(vector<int> &arr)
{
    int maxx;
    for (int i = 0; i < arr.size(); i++)
    {

        if (i == arr.size() - 1)
        {
            arr[i] = -1;
            return arr;
        }
        maxx = arr[i + 1];
        for (int j = i + 2; j < arr.size(); j++)
        {
            maxx = max(maxx, arr[j]);
        }
        arr[i] = maxx;
    }

    return arr;
}
};

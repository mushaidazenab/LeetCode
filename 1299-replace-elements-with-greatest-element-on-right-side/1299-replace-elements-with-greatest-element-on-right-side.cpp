class Solution {
public:
vector<int> replaceElements(vector<int> &arr)
{
    int maxx = -1;
    int current;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        current = arr[i];
        arr[i] = maxx;
        maxx = max(maxx, current);
    }
    return arr;
}
};
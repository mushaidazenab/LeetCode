class Solution {
public:
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";

    string prefix;

    // go through each character of the first string
    for (int i = 0; i < strs[0].size(); i++)
    {
        // compare this character with every other string
        for (int j = 1; j < strs.size(); j++)
        {
            // if current string is too short
            // or the characters don't match
            if (i >= strs[j].size() || strs[j][i] != strs[0][i])
            {
                return prefix;
            }
        }

        // every string had the same character at index i
        prefix.push_back(strs[0][i]);
    }

    return prefix;
}

};
class Solution {
public:

int lengthOfLongestSubstring(string s)
{
    int l = 0;
    int res = 0;
    unordered_set<char> charSet;
    for (int r = 0; r < s.length(); r++)
    {
        while (charSet.count(s[r]))
        {
            charSet.erase(s[l]);
            l++;
        }
        charSet.insert(s[r]);
        res = max(res, r - l + 1);
    }
    return res;
}
};
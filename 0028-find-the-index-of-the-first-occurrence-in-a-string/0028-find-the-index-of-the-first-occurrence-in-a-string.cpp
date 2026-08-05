class Solution {
public:
int strStr(string haystack, string needle)
{
    if (needle == "")
        return -1;
    if (haystack.size() < needle.size())
        return -1;
    for (int i = 0; i < haystack.size() - needle.size() + 1; i++)
    {
        for (int j = 0; j < needle.size(); j++)
        {
            if (haystack[i + j] != needle[j])
                break;
            if (j == needle.size() - 1)
                return i;
        }
    }
    return -1;
}
};
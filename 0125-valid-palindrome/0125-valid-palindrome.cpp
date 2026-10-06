class Solution {
public:

bool check(string &s, int l, int r) //passes string by reference otherwise memory limit exceeded
{
    if (l == r || l > r)
    {
        return true;
    }
    if (!isalnum(s[l]))
    {
        return check(s, l + 1, r);
    }
    if (!isalnum(s[r]))
    {
        return check(s, l, r - 1);
    }
    return ((tolower(s[l]) == tolower(s[r])) && check(s, l + 1, r - 1));
}
bool isPalindrome(string s)
{
    int l = 0;
    int r = s.size() - 1;
    return check(s, l, r);
}
};

class Solution {
public:

int lengthOfLastWord(string s)
{
    int right = s.length() - 1;
    int count = 0;

    while (right >= 0 && s[right] == ' ')
    {
        right--;
    }

    while (right >= 0 && s[right] != ' ')
    {
        count++;
        right--;
    }

    return count;
}
};
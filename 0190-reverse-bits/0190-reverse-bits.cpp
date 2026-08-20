class Solution {
public:
int reverseBits(int n)
{
    string s = "";
    for (int i = 0; i < 32; i++)
    {
        s += '0' + (n % 2);
        n /= 2;
    }

    int value = 0;
    for (char c : s)
    {
        value = value * 2 + (c - '0');
    }
    return value;
}
};
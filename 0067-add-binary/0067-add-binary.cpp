class Solution {
public:
string addBinary(string a, string b)
{
    string res = "";
    int carry = 0;
    int digitA, digitB;
    int total;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        digitA = (i >= 0) ? a[i] - '0' : 0;
        digitB = (j >= 0) ? b[j] - '0' : 0;
        total = digitA + digitB + carry;
        res.push_back((total % 2) + '0'); // appends the resulting binary digit ( 0 or 1) to the front of res
        carry = total / 2;                // updates carry for next column
        i--;
        j--;
    }

    reverse(res.begin(), res.end());
    return res;
}
};
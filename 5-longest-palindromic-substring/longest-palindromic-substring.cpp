class Solution {
public:
string longestPalindrome(string s)
{
    int maxLength = 0;
    string palindrome = "";
    int leftPtr, rightPtr;
    for (int i = 0; i < s.length(); i++)
    {
        // odd lengthed palindromes
        leftPtr = i;
        rightPtr = i;
        while (leftPtr >= 0 && rightPtr <= s.length() && (s[leftPtr] == s[rightPtr]))
        {

            if (maxLength < rightPtr - leftPtr + 1)
            {
                maxLength = rightPtr - leftPtr + 1;
                palindrome = "";
                for (int j = leftPtr; j <= rightPtr; j++)
                    palindrome.push_back(s[j]);
            }
            leftPtr--;
            rightPtr++;
        }

        // even lengthed palindromes
        leftPtr = i;
        rightPtr = i + 1;
        while (leftPtr >= 0 && rightPtr <= s.length() && (s[leftPtr] == s[rightPtr]))
        {

            if (maxLength < rightPtr - leftPtr + 1)
            {
                maxLength = rightPtr - leftPtr + 1;
                palindrome = "";
                for (int j = leftPtr; j <= rightPtr; j++)
                    palindrome.push_back(s[j]);
            }
            leftPtr--;
            rightPtr++;
        }
    }
    return palindrome;
}
};
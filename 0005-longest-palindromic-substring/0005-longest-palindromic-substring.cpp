class Solution {
public:
string longestPalindrome(string s)
{
    int maxLength = 0;
    string palindrome = "";
    int leftPtr, rightPtr;
    // what we re trying to do is that treat every index as a centre and expand about it to see if the corresponding indexes have the same value (is it a palindrome?)
    // thus we do left-- and right++ opposed to traditional left++ and right--
    // since we re basically expanding about the index(potential center of longest palindrome)
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
                //clear the original palindrome and replace it with the new longer palindromic substring(or string, who knows)
                palindrome = "";
                //using loop to push back every char in the substring
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
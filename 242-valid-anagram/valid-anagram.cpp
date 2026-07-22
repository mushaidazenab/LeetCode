class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> frequencyCounter;
        unordered_map<char, int> frequencyCounter2;

        for (int i = 0; i < s.length(); i++)
        {
            frequencyCounter[s[i]]++;
            frequencyCounter2[t[i]]++;
        }

        if (frequencyCounter != frequencyCounter2)
            return false;
        else
            return true;
    }
};
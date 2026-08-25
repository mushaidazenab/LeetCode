class Solution {
public:
bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> seen;
    unordered_map<string, char> reverseSeen;
    string temp = "";
    int i = 0;
    for (char p : pattern)
    {
        temp = "";
        if (i >= s.length()) // when no. of letters > no. of words
            return false;

        if (i < s.length() && s[i] == ' ')
            i++; // moves past ' ' while calculating next word

        // storing word in temp
        while (s[i] != ' ' && i < s.length())
        {
            temp += s[i];
            i++;
        }

        // checks if the key (p) exists in the map seen
        // if it does, also check if the corresponding word we just calculated (temp)
        // is different from the one we mapped it to before
        // if thats the case, it means we re trying to map the same key to a new value
        // so we return false because a particular key is supposed to be mapped to
        // same values
        if (((seen.find(p) != seen.end()) && (seen[p]) != temp))
        {
            return false;
        }

        if (((reverseSeen.find(temp) != reverseSeen.end()) && (reverseSeen[temp] != p)))
        {
            return false;
        }
        seen[p] = temp;
        reverseSeen[temp] = p;
    }
    if (i < s.length()) // no. of words > no. of letters i.e. to check if there are unmapped words left in 's'
        return false;
    return true;
}
};
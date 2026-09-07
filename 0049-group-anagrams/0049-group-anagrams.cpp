class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    // vector<vector<string>> syntax for 2D list
    // create an empty hashmap
    unordered_map<string, vector<string>> map;

    // now the key idea for this to work is that when anagrams are sorted, they will result in the same string
    // so we iterate through every string and see if it (after sorting) exists in our hashmap
    // its key (which was the sorted string) will be the same if the anagram exists already
    // if key matches, then append the original string to that key of hashmap
    for (string s : strs)
    {
        string key = s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }
    // this step is basically there to convert our hashmap to a 2D vector so that it matches the return type of our function
    // i.e. translating our hashmap to 2D vector
    vector<vector<string>> result; // 2D vector in which each column is of type vector and row contains strings
    // unordered_map in c++ is stored as std::pair containing pair.first() and pair.second()
    //  pair.first() stores the key
    // pair.second() stores the value i.e. the strings stored in each vector column in our case

    for (auto pair : map) //
    {
        result.push_back(pair.second);
    }
    return result;
}
};
class Solution {
public:
int minimumPushes(string word)
{
    int minPushes = 0;

    unordered_map<char, int> uniqueCharMap; // stores frequency of each unique character

    for (int i = 0; i < word.size(); i++)
    {
        uniqueCharMap[word[i]]++;
    }
    int noOfUniqueChars = uniqueCharMap.size();

    vector<int> descendingSort; // sorting frequency in descending order (greater frequency => greater priority => less overall psuhes required)

    for (auto it : uniqueCharMap)
    {
        descendingSort.push_back(it.second);
    }
    // bubble sort
    for (int i = 0; i < noOfUniqueChars - 1; i++)
    {
        for (int j = 0; j < noOfUniqueChars - i - 1; j++)
        {
            if (descendingSort[j] < descendingSort[j + 1])
            {
                swap(descendingSort[j], descendingSort[j + 1]);
            }
        }
    }
    
    // key idea:
    // for every first 8 unique characters, we can assign them each one unique key so we have to push each alphabet once
    // similarly, for next 8 chars, we assign then 2nd position so we have to push each of them twice
    // and so on till 26th char (if there is)

    if (noOfUniqueChars <= 8) // why 8? becuase we have 8 potential keys where we can map alphabets (from 2 to 9, included)
    {
        for (int i = 0; i < noOfUniqueChars; i++)
        {
            minPushes += descendingSort[i];
        }
        return minPushes;
    }
    else if (noOfUniqueChars <= 16)
    {
        for (int i = 0; i < 8; i++)
        {
            minPushes += descendingSort[i];
        }

        for (int i = 8; i < noOfUniqueChars; i++)
        {
            minPushes += (descendingSort[i] * 2);
        }

        return minPushes;
    }
    else if (noOfUniqueChars <= 24)
    {
        for (int i = 0; i < 8; i++)
        {
            minPushes += descendingSort[i];
        }

        for (int i = 8; i < 16; i++)
        {
            minPushes += (descendingSort[i] * 2);
        }
        for (int i = 16; i < noOfUniqueChars; i++)
        {
            minPushes += (descendingSort[i] * 3);
        }
        return minPushes;
    }
    else if (noOfUniqueChars > 24)
    {
        for (int i = 0; i < 8; i++)
        {
            minPushes += descendingSort[i];
        }

        for (int i = 8; i < 16; i++)
        {
            minPushes += (descendingSort[i] * 2);
        }
        for (int i = 16; i < 24; i++)
        {
            minPushes += (descendingSort[i] * 3);
        }
        for (int i = 24; i < noOfUniqueChars; i++)
        {
            minPushes += (descendingSort[i] * 4);
        }
        return minPushes;
    }
    return minPushes;
}
};
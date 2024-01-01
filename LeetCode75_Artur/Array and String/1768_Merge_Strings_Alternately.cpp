#include <iostream>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        size_t word1Size = word1.size();
        size_t word2Size = word2.size();
        string res = string(word1Size + word2Size, ' ');

        size_t i = 0, j = 0;
        size_t k = 0;
        while(i < word1Size || j < word2Size)
        {
            if(i < word1Size)
                res[k++] = word1[i++];
            if(j < word2Size)
                res[k++] = word2[j++];
        }

        return res;
    }
};
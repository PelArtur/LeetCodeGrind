#include <iostream>

using namespace std;

class Solution
{
public:
    size_t gcd(size_t a, size_t b)
    {
        if (a < b)
            return gcd(b, a);

        if (! (a % b))
            return b;
        else
            return gcd(b, a % b);
    }

    string gcdOfStrings(string str1, string str2)
    {
        size_t maxLen = gcd(str1.size(), str2.size());
        size_t subStrLen = 0;

        while(subStrLen < maxLen && str1[subStrLen] == str2[subStrLen])
            subStrLen++;

        if(!subStrLen)
            return "";

        size_t i = subStrLen, j = subStrLen;
        while(i < str1.size() || j < str2.size())
        {
            if(i < str1.size() && str1[i] != str1[i % subStrLen])
                return "";

            if(j < str2.size() && str2[j] != str2[j % subStrLen])
                return "";

            i++;
            j++;
        }

        return str1.substr(0, subStrLen);
    }
};
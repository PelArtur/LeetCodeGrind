#include <iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int lenStringOne = word1.length();
        int lenStringTwo = word2.length();

        string result = "";

        if (lenStringOne == lenStringTwo){
            for(int i = 0; i < lenStringOne; i++){
                result += word1[i];
                result += word2[i];
            }
        } else{
            int i = 0;
            int mediumLimit = lenStringOne > lenStringTwo ? lenStringTwo : lenStringOne;
            int highLimit = lenStringOne < lenStringTwo ? lenStringTwo : lenStringOne;
            string * biggerWord = lenStringOne > lenStringTwo ? &word1 : &word2;
            
            while(i < mediumLimit){
                result += word1[i];
                result += word2[i];
                i++;
            }
            for(i = mediumLimit; i < highLimit; i++){
                result +=  (*biggerWord)[i];
            }
        }
    return result;
    }
};

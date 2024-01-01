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

/*  TRYING BETTER APPROACH

int i = 0;
 string result = "";
 while (i < word1.length() || i < word2.length(){
    if (i < word1.length()){
        result += word1[i];
    }
    if (i < word2.length()){
        result += word2[i];
    }

    i++;
 }

 Пояснення:
 Спочатку ми перевіряєм, чи наш індекс менший ніж хоча б за одну довжину з двох.
 За рахунок цього, якщо один стрінг вже буде повністю записаний, інший продовжить
 додаватись допоки індекс не буде дорівнювати розміру більшого стрінгу.
 */


/*
 https://leetcode.com/problems/determine-if-two-strings-are-close/?envType=daily-question&envId=2024-01-14
 */


#include <map>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


class Solution {
public:
    static bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        }

        vector<int> wordOneCharFreq(26, 0);
        vector<int> wordTwoCharFreq(26, 0);

        for(int idx = 0; idx < word1.size(); ++idx){
            wordOneCharFreq[word1[idx] - 'a'] += 1;
            wordTwoCharFreq[word2[idx] - 'a'] += 1;
        }

        for(int idx = 0; idx < 26; ++idx){
            if(wordOneCharFreq[idx] && !wordTwoCharFreq[idx]){
                return false;
            }
        }

        sort(wordOneCharFreq.begin(), wordOneCharFreq.end());
        sort(wordTwoCharFreq.begin(), wordTwoCharFreq.end());

        return wordOneCharFreq == wordTwoCharFreq;

    }
};


int main(){

    cout << Solution().closeStrings("abc", "cba");

    return 0;
}


/*
 Main idea:

 Наче не дуже складна, але я не додумався до того що якщо кількості
 входжень однакові, то можна перетворити другу стрінгу на першу.

 Головна ідея така:
 Два base case:
 1. Різна довжина стрінг
 2. Різні символи в стрінгах

 Головна ідея:
 Рахуємо частоту символів для кожної стрінги окремо.
 Проходимось по обох масивах, якщо десь є значення, а десь ні, то
 означає що є різні символи в стрінгах, тому повертаємо false.

 Далі сортуємо масиви частот.
 Якщо вони однакові(приклад без зайвих нулів)
 [1,2,4] abbcccc
 [1,2,4] caabbbb
 То це означає, що в цьому випадку дві стрінги можна зробити однаковими
 Будь-яка зміна не змінить загальної кількості тих чи інших символів.
 Якщо в нас унікальні символи з обох слів однакові, й частота символів
 сходиться, то ми можемо спочатку для кожного символа отримати його правильну
 кількість, а потім за допомогою операції переміщення поставити його на місце.


 [1,2,4] abbcccc
 [1,2,4] caabbbb

 caabbbb -> accbbbb -> abbcccc

 */
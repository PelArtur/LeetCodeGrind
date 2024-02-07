/*
 https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> count;

        for(auto chr : s)
            count[chr]++;

        vector<pair<char, int>> countArr;
        countArr.reserve(count.size());
        for(auto val : count)
            countArr.emplace_back(val);

        sort(countArr.begin(), countArr.end(), [](auto &left, auto &right) {
            return left.second > right.second;
        });

        string res;
        for(auto val : countArr)
            res += string(val.second, val.first);

        return res;
    }
};


int main()
{
    cout << Solution().frequencySort("tree") << endl;
    cout << Solution().frequencySort("cccaaa") << endl;
    cout << Solution().frequencySort("Aabb") << endl;
}

/*
 Main idea:
 Спершу підрахувати кількість входжень кожного символа в
 стрічці. Додати ці пари літера-кількість входження у масив
 і відсортувати його у незростаючому порядку.

 Після чого додати ці символи у відповідній кільості в масив.

 Часова складність алгоритму: О(n), де n це розмір вхідного
 масиву.

 Чому не mlogm, де m це кількість унікальних символів. Ця
 складність на сортування масиву радше матиме константний час,
 оскільки за умовою завдання серед символів можуть бути лише
 малі, великі літери латинського алфавіту та числа, загалом 62.
 Цей час нівелюється часом на обхід усієї стрічки, яка має розмір
 до 5*10^5.

 Також є варіант без сортування з чистим O(n) за допомогою bucket,
 але через великий розмір стрічки буде дуже в рази більше використовуватись
 додаткової пам'яті.

  class Solution {
  public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;

        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
 };


 Також є більш оптимальний варіант через використання мапи, оскільки
 вона є впорядкована і не займає додаткової пам'яті O(n). Аналог варіанту
 купи.

     string frequencySort(string s) {
        unordered_map<char, int> freqOfChar;
        for(char c : s) {
            freqOfChar[c] ++;
        }

        map<int, string> dupStr;
        for(auto v : freqOfChar) {
            char c = v.first;
            int n = v.second;
            dupStr[n] += string(n, c);
        }

        string res;
        for(auto rit = dupStr.rbegin(); rit != dupStr.rend(); ++rit) {
            res += rit->second;
        }
        return res;
    }
*/
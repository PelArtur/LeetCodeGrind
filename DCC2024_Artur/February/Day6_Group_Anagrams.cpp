/*
 https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<vector<int>, vector<string>> anagrams;

        vector<int> letters;
        for(const auto& word : strs)
        {
            letters = vector<int>(26, 0);
            for(auto chr : word)
                letters[chr - 'a']++;
            anagrams[letters].push_back(word);
        }

        vector<vector<string>> res;
        for(const auto& val : anagrams)
            res.push_back(val.second);

        return res;
    }
};


int main()
{
    vector<string> test1 = {"eat","tea","tan","ate","nat","bat"};
    vector<string> test2 = {""};
    vector<string> test3 = {"a"};

    Solution().groupAnagrams(test1);
    Solution().groupAnagrams(test2);
    Solution().groupAnagrams(test3);
}

/*
 Main idea:
 За умовою анаграми є два підходи для розподілу слів
 під групи анаграми, то можна або рахувати кількість
 входжень, або відсортувати слово, оскільки там є тільки
 малі латинські літери.

 На варіанті С++ використовувся перший спосіб, на пайтоні
 відповідно другий. Ідея полягає в тому, щоб у мапі, ключ
 якою буде властивість анаграми, яка була згадана вище, а
 значеннями буде масив із слів, які підпадають під цю властивість.

 Після обходу масиву, проводиться обхід мапи і в масив результату
 додаються значення мапи.

 Часова складність алгоритму: O(nk), де n — розмір масиву, k — розмір
 найдовшого слова.
 Для другого способу: O(nklog(k))
*/
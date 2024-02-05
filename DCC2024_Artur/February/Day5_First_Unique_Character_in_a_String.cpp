/*
 https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        auto letters = vector<int>(26, -1);

        for(int i = 0; i < s.size(); ++i)
        {
            if( letters[s[i] - 'a'] >= 0 )
                letters[s[i] - 'a'] = -2;
            else if( letters[s[i] - 'a'] == -1 )
                letters[s[i] - 'a'] = i;
        }

        int currMin = INT_MAX;
        for(auto val : letters)
            if( val >= 0 )
                currMin = min(currMin, val);

        return currMin == INT_MAX ? -1 : currMin;
    }
};


int main()
{
    cout << Solution().firstUniqChar("leetcode") << endl;
    cout << Solution().firstUniqChar("loveleetcode") << endl;
    cout << Solution().firstUniqChar("aabb") << endl;
}

/*
 Main idea:
 Оскільки за умовою завдання літери є тільки латинськими та малими,
 то можна створити масив розміром 26, забивши його значеннями -1.

 У цьмоу масиві буде зберігатись індекс літери, яка зустрілась один
 раз, якщо така літера не зустрічалась взагалі, то за її індексом
 знаходитиметься -1, а якщо зустрічаласб більше, ніж один раз, то -2.

 Після цього всього перевіряються всі індекси, які є більші або рівні 0
 і повертається мінімальне. Якщо в масиві знаходяться тільки значення
 -1 та -2, то повертається -1.

 Часова складність алгоритму: O(n)
*/
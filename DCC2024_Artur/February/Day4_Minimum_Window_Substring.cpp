/*
 https://leetcode.com/problems/minimum-window-substring/solutions/?envType=daily-question&envId=2024-02-04
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        s.push_back('_');
        unordered_map<char, int> occurrenceT;
        unordered_map<char, int> occurrenceWindow;

        int uniqueCharT;
        int uniqueCharS = 0;
        int currMin = INT_MAX;

        for(auto chr : t)
            occurrenceT[chr]++;

        uniqueCharT = (int) occurrenceT.size();
        int minL = -1;

        int l = 0;
        int r = 0;
        while( r < s.size() )
        {
            if( uniqueCharS != uniqueCharT )
            {
                if( occurrenceT[s[r]] )
                {
                    occurrenceWindow[s[r]]++;
                    if( occurrenceWindow[s[r]] == occurrenceT[s[r]] )
                        uniqueCharS++;
                }
                r++;
            }
            else
            {
                while( uniqueCharS == uniqueCharT )
                {
                    if( occurrenceT[s[l]] )
                    {
                        occurrenceWindow[s[l]]--;
                        if( occurrenceWindow[s[l]] < occurrenceT[s[l]] )
                            uniqueCharS--;
                    }
                    l++;
                }
                if( currMin > (r - l) )
                {
                    currMin = r - l;
                    minL = l - 1;
                }
            }
        }

        string res = "";
        if( minL == -1 )
            return res;

        for(int i = minL; i <= minL + currMin; ++i)
            res.push_back(s[i]);

        return res;
    }
};


int main()
{
    cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << Solution().minWindow("a", "a") << endl;
    cout << Solution().minWindow("a", "aa") << endl;
}

/*
 Main idea:
 Sliding window + Hashmap
 Будемо перевіряти розмір усіх підпослідовностей зліва-направо
 і зберігати найменшу, для цього буде sliding window.

 Спершу створимо дві мапи, одна міститиме кількість входжень
 кожної літери в стрічці t, інша кількість входжень літер з стрічки
 t у поточному вікні(підпослідовності) стрічки s.

 Також буде три параменти: кількість унікальних літер в стрічці t,
 кількість унікальних літер в стрічці s, кількість яких у вікні є
 більшою або рівною кількості відповідних літер у мапі стрічки t,
 мінімальна довжина підпослідовності.

 Рахуємо всі входження в стрічці t. Проходимось правим поінтером по
 стрічці s до тих пір, поки вікно не міститиме необхідну кількість літер
 зі стрічки t.
 Дальше рухаємо лівий поінтер, поступово забираючи з мапи вікна пройдені
 літери і коли вже дійшли до того стану, що утвориене вікно не виконує умову
 завдання, перевіряємо чи підмасив, включаючи останню літеру, яку ми забрали,
 оскільки її не хватає, щоб виконалась умова, має менший розмір, ніж поточний
 мінімальний підмасив, якщо це так, то зберігаємо розмір цього підмасиву і лівий
 поінтер.

 У кінці перевіряємо чи лівий поінтер був змінений, якщо ж його значення залишилось
 -1, то повертаємо пусту стрічку. В іншому випадку повертаємо підпослідовність, починаючи
 з цього поінтера розміром мінімального підмасиву.

 Часова складність роботи алгоритму: O(m + n)
*/
/*
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int currVowels = 0;
        for(int i = 0; i < k; ++i)
            if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )
                currVowels++;

        int maxVowels = currVowels;
        for(int i = k; i < s.size(); ++i)
        {
            if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )
                currVowels++;
            if( s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u' )
                currVowels--;
            if( currVowels > maxVowels )
                maxVowels = currVowels;
        }

        return maxVowels;
    }
};

int main()
{
    Solution solution;

    string test1 = "abciiidef";
    string test2 = "aeiou";
    string test3 = "leetcode";

    cout << solution.maxVowels(test1, 3) << endl;
    cout << solution.maxVowels(test2, 2) << endl;
    cout << solution.maxVowels(test3, 3) << endl;
}

/*
 Main idea:
 Sliding window
 Рахуємо кількість голосних у перших k літер і записуємо
 це число як поточний максимум.
 Ідемо по стрічці починаючи з k за індексом букви, якщо
 ця буква є голосною, то до поточного значення додаємо
 одиницю. Якщо i - k буква голосна, то від поточного
 значення віднімаємо одиницю.

 Після цього перевіряємо чи поточна кількість голосних є
 більшою за максимум, якщо це так, то перезаписуємо максимум

 Часова складність алгоритму: O(n)
*/
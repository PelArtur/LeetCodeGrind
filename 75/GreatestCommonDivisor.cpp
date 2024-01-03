/*
 https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75
 */
#include <numeric>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 == str2 + str1){
            return str1.substr(0, gcd(str2.size(), str1.size()));
        } else{
            return "";
        }
    }
};
/*
Main idea:

Обидва стрінга складаються з однакових підстрінгів у тому випадку,
якщо str1 + str2 = str2 + str1. Тобто, оскільки підстрінги однакові
і обидва стрінги повністю з них складаються, то порядок цих стрінгів
не важливий.

До цього моменту я не додумався, підгледів у розв'язку.

Далі, щоб знайти підстрінг, з якого складаються стрінги
використовується gcd, щоб знайти найбільше спільне кратне.
Це працює оскільки у завданні сказано знайти найбільший підстрінг.
 */
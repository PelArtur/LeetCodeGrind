/*
 https://leetcode.com/problems/assign-cookies/?envType=daily-question&envId=2024-01-01
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int findContentChildren(vector<int>& children, vector<int>& cookies) {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());

        int child = 0;

        for(int cookie = 0; cookie < cookies.size() && child < children.size(); ++cookie){
            if(cookies[cookie] >= children[child]){
                ++child;
            }
        }
        return child;
    }
};


/*
 Main idea:
 Посортувати печенька і апетит дітей в зростаючому порядку.
 Після цього йти по печеньках: якщо печенька задовільняє дитину
 - збільшити пойнтер на дитину. Таким чином наступне печеня ми
 будемо шукати для дитини, що буде мати більший апетит.

 Діти
 4 7 9

 Печеня
 1 5 8

 1 Печеня не знайде своє місце(буде порівнюватись
 з 4 і буде менше)

 5 печеня буде більшим за першу дитину - пойнтер збільшиться на 1
 Тепер перевірка буде з другою дитиною 7

 І так далі
 */


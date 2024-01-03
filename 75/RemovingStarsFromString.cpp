#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string static removeStars(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        stack<char> Stack;
        string result = "";
        for(char character : s){
            if(character == '*') {
                Stack.pop();
                continue;
            }
            Stack.push(character);
        }
        while(!Stack.empty()){
            result += string(1, Stack.top());
            Stack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/*
Main idea:
Рухаємось по стрічці, якщо зірочка попаєм,
якщо ні, то пушим змінну.

Важливі моменти:
ios_base::sync_with_stdio(false); - вимикає кросплатформеність C/C++: побічний ефект - більша швидкість
cin.tie(nullptr);
cout.tie(nullptr);
Вимикають input i output даних, прийдеться вручну сетати аутпут і додатково робити щось типу команди
вивести аутпут. Побічний ефект - збільшення швидкості.

Швидше реверснути в кінці весь стрінг, ніж покроково додавати чар на початок стрінга.
 */
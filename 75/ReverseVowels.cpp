
/*
 https://leetcode.com/problems/reverse-vowels-of-a-string/submissions/?envType=study-plan-v2&envId=leetcode-7
 */
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <iostream>



using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        stack<char> Stack;
        queue<char> Queue;
        vector<int> positions;
        string result = "";
        int idx = 0;
        int track = 0;
        for(char letter : s){
            if(letter == 'a' || letter == 'e' || letter == 'i' || letter ==  'o' || letter == 'u'){
                Stack.push(letter);
                positions.push_back(idx);
            } else {
                Queue.push(letter);
            }
            idx++;
        }
        for(int kdx = 0; kdx < s.size(); ++kdx){
            if(kdx == positions[track]){
                result += Stack.top();
                Stack.pop();
                track++;
                continue;
            }
            result += Queue.front();
            Queue.pop();
        }
        return result;
    }
};

/*
 Main idea:

 Таке рішення чисто для веселості
 Юзаю стак щоб розвернути vowels, чергу щоб все пройшло вперед ногами.

 */
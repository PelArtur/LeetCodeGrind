/*
 https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=leetcode-75
 */

class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string temp = "";

        int spaceCounter = 0;
        string result = "";
        for(int idx = 0; idx < s.size(); ++idx){
            if(s[idx] == ' '){
                if(spaceCounter == 0){
                    if(idx == 0){
                        continue;
                    }
                    if(temp != ""){
                        words.push(temp);
                        temp = "";
                    }
                    spaceCounter++;
                } else{
                    continue;
                }
            } else{
                temp += s[idx];
                spaceCounter = 0;
                if(idx == s.size() - 1){
                    words.push(temp);
                }
            }
        }

        while(!words.empty()){
            for(int idx = 0; idx < words.top().size(); ++idx){
                result += words.top()[idx];
            }
            words.pop();
            if(!words.empty()){
                result += ' ';
            }
        }

        return result;

    }
};


/*
 Main idea:
 Скіпати пробіли якщо їх більше одного, якщо це тільки перше входження
 то додавати попереднє слово до стаку. Пізніше розвертати стак і дода-
 вати всі слова в стрінг резалт.


Better Solution:
 class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string temp = "";

        int spaceCounter = 0;
        string result = "";
        for(int idx = 0; idx < s.size(); ++idx){
            if(s[idx] == ' '){
                if(spaceCounter == 0){
                    if(idx == 0){
                        continue;
                    }
                    if(temp != ""){
                        words.push(temp);
                        temp = "";
                    }
                    spaceCounter++;
                } else{
                    continue;
                }
            } else{
                temp += s[idx];
                spaceCounter = 0;
                if(idx == s.size() - 1){
                    words.push(temp);
                }
            }
        }

        while(!words.empty()){
            for(int idx = 0; idx < words.top().size(); ++idx){
                result += words.top()[idx];
            }
            words.pop();
            if(!words.empty()){
                result += ' ';
            }
        }

        return result;

    }
};
 */
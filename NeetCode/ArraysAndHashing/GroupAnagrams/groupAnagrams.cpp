/*
 https://leetcode.com/problems/group-anagrams/
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> groupedAnagrams;
        vector<vector<string>> result;
        string copy;
        for(string str : strs){
            copy = str;
            sort(str.begin(), str.end());
            if(groupedAnagrams.find(str) == groupedAnagrams.end()){
                groupedAnagrams[str] = groupedAnagrams.size();
                result.push_back({copy});
            } else{
                result[groupedAnagrams[str]].push_back(copy);
            }
        }
        return result;
    }
};

/*
 Main idea:

 Головна проблема в цій задачі це трекати стрінги з однаковими символами.
 Вирішується вона сортуванням стрінг, таким чином однакові стрінги
 будуть ідентичними на всіх індексах. {str1[5] == str2[5]}

 Мапа буде трекати чи існує масив з такими символами, якщо ні то додавати
 такий масив і додавати в мапу посилання на нього.
 Якщо такий масив буде, то буде брати посилання з мапи і додавати туди
 значення стрінги.
 */
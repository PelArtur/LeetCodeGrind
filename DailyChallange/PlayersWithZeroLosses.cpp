/*
 https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15
 */
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> playersData;


        vector<vector<int>> playersResult(2);
        // 100 - win
        // 200 - lost 1 time
        // 300 - lost many times
        // 0 no info

        for(vector<int> matchResult : matches){
            if(playersData[matchResult[0]] == 0)
                playersData[matchResult[0]] = 100;

            if(playersData[matchResult[1]] == 100){
                playersData[matchResult[1]] = 200;
            } else if (playersData[matchResult[1]] == 200){
                playersData[matchResult[1]] = 300;
            } else if(playersData[matchResult[1]] == 0){
                playersData[matchResult[1]] = 200;
            }
        }


        for(auto playerData : playersData){
            if(playerData.second == 100){
                playersResult[0].push_back(playerData.first);
            } else if(playerData.second == 200){
                playersResult[1].push_back(playerData.first);
            }
        }

        return playersResult;

    }
};
/*
 Main idea:

 Якщо тіп новий і виграв, додаєм його до виграшів
 Якщо тіп програв, сетаєм йому програш
 Якщо тіп програв і він вже програвав
 сетаєм йому кілька програшів

 Проходимось по мапі, якщо в когось значення, що відповідає
 одному одному програшу, додаємо його в другий масив
 Якщо таке, що відповідає лише виграшам тоді в перший масив.
 */
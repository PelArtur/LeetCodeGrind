/*
 https://leetcode.com/problems/keys-and-rooms/description/?envType=study-plan-v2&envId=leetcode-75
 */

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size() == 0){
            return false;
        }

        int numberOfVisitedRooms = 0;
        map<int, int> visitedRooms;
        queue<int> keys;

        keys.push(0);
        visitedRooms[0] = 1;

        while(!keys.empty()){
            numberOfVisitedRooms++;

            for(int roomKey : rooms[keys.front()]){
                if(visitedRooms[roomKey] != 0)
                    continue;

                visitedRooms[roomKey] = 1;
                keys.push(roomKey);
            }

            keys.pop();
        }

        return numberOfVisitedRooms == rooms.size();
    }
};


/*
 Main idea:

 Створюєм чергу, по якій будемо ходити по кімнатах.
 Спочатку додаємо туди 0 кімнату, адже ми починаємо
 завдання з неї. Далі для кожного ключа в кімнаті
 перевіряємо, чи ми вже маємо цей ключ. Якщо він
 в нас є, не додаємо його в чергу. Якщо його немає,
 додаємо його в чергу й залишаєм позначку, що ми
 такий ключ вже маємо. Поки в нас не закінчаться ключі,
 заходимо в кімнату, беремо всі ключі і йдемо в наступну
 по черзі.
 Кожного разу як витягуємо з черги елемент, додаємо до
 кількості пройдених кімнат 1.
 */
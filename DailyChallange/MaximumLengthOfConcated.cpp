/*
 https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23
 */
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLength = 0;
        vector<bitset<26>> uniqueWords;

        for(string word : arr){
            bitset<26> binaryRepresentation;
            for(char character : word){
                binaryRepresentation.set(character - 'a');
            }
            if(binaryRepresentation.count() == word.size()){
                uniqueWords.push_back(binaryRepresentation);
            }
        }

        vector<bitset<26>> connections = {bitset<26>()};

        for(int idx = 0; idx < uniqueWords.size(); ++idx){
            for(int jdx = 0; jdx < connections.size(); ++jdx){
                if((uniqueWords[idx] & connections[jdx]).any()){
                    continue;
                }
                connections.push_back(uniqueWords[idx] | connections[jdx]);
                maxLength = max(maxLength, (int)(uniqueWords[idx].count() + connections[jdx].count()));
            }
        }
        return maxLength;
    }
};
/*
 Main idea:

 Ми не беремо до уваги стрінги, що містять дублікати-чари. Таким
 чином спочатку утворюємо список бітсетів усіх стрінгів, що мають
 унікальні елементи. Створюємо ще один вектор, що міститиме всі
 можливі поєднання. Для кожної стрінги в списку унікальних ми
 перевіряємо її з кожним утвореним словом в іншому списку, якщо
 між двома бітсетами є хоча б одне співпадіння, то ми переходимо
 до наступного елементу, якщо співпадінь немає, додаємо до списку
 всіх можливих поєднань нове поєднання. Для наступного унікального
 слова ми вже будемо враховувати це нове поєднання. Також в кінці
 додавання нового сполучення ми перевіряємо що довше: нове слово-
 сполучення чи максимальне слово в списку.
 */
/*
 https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class RandomizedSet
{
private:
    unordered_map<int, int> elemInd;
    vector<int> set;
    int size;

public:
    RandomizedSet()
    {
        elemInd.clear();
        set.clear();
        size = 0;
    }

    bool insert(int val)
    {
        if( elemInd.find(val) != elemInd.end() )
            return false;
        set.push_back(val);
        elemInd[val] = size++;
        return true;
    }

    bool remove(int val)
    {
        if( elemInd.find(val) == elemInd.end() )
            return false;
        int removeElemInd = elemInd[val];
        size--;
        swap(set[removeElemInd], set[size]);
        elemInd[set[removeElemInd]] = removeElemInd; //replace ind of last elem to removed
        set.pop_back();
        elemInd.erase(val);
        return true;
    }

    int getRandom()
    {
        int ind = rand() % size;
        return set[ind];
    }
};


int main()
{
    RandomizedSet* obj = new RandomizedSet();
    obj->insert(1);
    obj->insert(2);
    obj->insert(3);
    obj->remove(3);
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;

}

/*
 Main idea:
 Kлас містить три атрибути:
  - elemInd — мапа, у якій ключ це значення числа сету, а значення
    мапи це індекс цього числа в сеті;
  - set — масив, який містить всі елементи масиву;
  - size — розмір сету;

 insert(int val):
 спершу перевіряємо чи елемент міститься в мапі, якщо так, то вертаємо
 false.
 Якщо ж елемента немає в мапі, то додаємо його в масив, а в мапу за ключем
 значення цього числа записуємо останній індикс масиву.

 remove(int val):
 Якщо елементу немає в мапі, то повертаємо false
 Якщо він є, то отримуємо його індекс у масиву, зменшуємо значення розміру
 масиву на 1, свапаємо останній елемент масиву з елементом, який необхідно
 видалити. Для останнього елементу масиву, який ми свапнули, змінюємо значення
 індексу на індекс елемента, який ми маємо видалити. Попаєм масив і видаляємо
 елемент з мапи.

 getRandom():
 Генеруємо рандомне число і беремо модуль числа за розміром масиву, тоді можливі
 варіанти [0, size-1] і кожне числа має однаковий шанс бути вибраним.

 Часова складність функцій: O(1)
 Усі функції виконуються за O(1), оскільки доступ та зміна елементів у масиві та
 мапі виконується за константний час. Метод swap і математичні процедури також за
 константний час.

 Проте можуть виникнути проблему із методом find у unordered_map, оскільки через
 особливість хешування може трапитись таке, що два різних елемента матимуть одинаковий
 хеш код, тоді вони будуть занесені в bucket. Якщо у мапі буде n елементів, які мають
 одинаковий хешкод, тоді час пошуку елементу в такі мапі становитиме O(n).
 У нашому завданні такого випадку може не трапитись, оскількі тут операції виконуються
 тільки наж простими числами, але якщо це будуть, наприклад, стрінги, тоді не вдасться
 отримати часову складність O(1) для всіх функцій, окрім радномної.
*/
/*
 https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=daily-question&envId=2024-01-16
 */
class RandomizedSet {
private:
    map<int, int> intPointers;
    vector<int> numbers;
    int size = 0;
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if(intPointers.find(val) != intPointers.end())
            return false;

        numbers.push_back(val);
        intPointers[val] = size;
        size++;
        return true;
    }

    bool remove(int val) {
        if(intPointers.find(val) == intPointers.end())
            return false;

        numbers[intPointers[val]] = numbers[size-1];
        intPointers[numbers[size-1]] = intPointers[val];
        numbers.pop_back();
        intPointers.erase(val);
        size--;
        return true;

    }

    int getRandom() {
        return numbers[rand() % size];
    }
};

/*
 Main idea:

 Коли додаємо елемент:
 Перевіряємо чи він вже є. Якщо є - false.
 Якщо немає - додаємо його в кінець масиву
 В мапі ключ - елемент, значення - індекс
 на якому це значення.

 Коли видаляємо елемент:
 Якщо елементу немає - false
 Якщо є -
 З мапи беремо індекс за яким стоїть елемент,
 що має бути видаленим. За цим індексом ставимо
 елемент, що є останнім в масиві. Переписуєм для
 останнього елементу індекс на той, за яким стояв
 видалений елемент. Після цих операцій попаєм останній
 елемент з масиву і чистим видалений елемент з мапи.

 Рандомний елемент:
 Повертаємо елемент масиву за індексом rand()%розмір масиву.
 */
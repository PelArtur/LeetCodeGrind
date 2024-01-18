/*
 https://leetcode.com/problems/smallest-number-in-infinite-set/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class SmallestInfiniteSet
{
private:
    priority_queue<int, vector<int>, greater<>> minHeap;
    unordered_map<int, bool> inHeap;
public:
    SmallestInfiniteSet()
    {
        for(int i = 1; i <= 1000; ++i)
        {
            minHeap.push(i);
            inHeap[i] = true;
        }
    }

    int popSmallest()
    {
        int smallest = minHeap.top();
        inHeap[smallest] = false;
        minHeap.pop();
        return smallest;
    }

    void addBack(int num)
    {
        if( inHeap[num] )
            return;

        minHeap.push(num);
        inHeap[num] = true;
    }
};


int main()
{
    auto* obj = new SmallestInfiniteSet();
    cout << obj->popSmallest() << endl;
    obj->addBack(3);
    obj->addBack(1);
    obj->addBack(5);
    obj->addBack(2);
    obj->addBack(2);
    obj->addBack(4);

    cout << obj->popSmallest() << endl;
    cout << obj->popSmallest() << endl;
    cout << obj->popSmallest() << endl;
    cout << obj->popSmallest() << endl;
    cout << obj->popSmallest() << endl;
}

/*
 Main idea:
 Використовуємо minHeap, яка забито значеннями від 1 до 1000, бо
 за умовою операції виконуються лише над позитивними цілими числами
 та які не перевищують цю 1000.

 Такоє є мапа, у якій зберігатимуться дані, чи число є пристунім у
 даних.

 Часова складність роботи алгоритму: O(nlogn)
*/
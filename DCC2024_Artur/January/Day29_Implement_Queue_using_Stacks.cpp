/*
 https://leetcode.com/problems/implement-queue-using-stacks/?envType=daily-question&envId=2024-01-29
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue
{
private:
    stack<int> *queueHelper;
    stack<int> *queue;

    void fillQueue()
    {
        while( !queueHelper->empty() )
        {
            queue->push(queueHelper->top());
            queueHelper->pop();
        }
    }

public:
    MyQueue()
    {
        queueHelper = new stack<int>;
        queue = new stack<int>;
    }

    void push(int x)
    {
        queueHelper->push(x);
    }

    int pop()
    {
        if( queue->empty() )
            fillQueue();

        int val = queue->top();
        queue->pop();
        return val;
    }

    int peek()
    {
        if( queue->empty() )
            fillQueue();
        return queue->top();
    }

    bool empty()
    {
        return queue->empty() && queueHelper->empty();
    }
};


int main()
{
    MyQueue* obj = new MyQueue();

    obj->push(1);
    obj->push(2);
    cout << "Peek: " << obj->peek() << endl;
    cout << "Pop: " << obj->pop() << endl;
    cout << "Is empty: " << obj->empty() << endl;
}

/*
 Main idea:
 Викорисати два стаки: один який гратиме роль черги, інший допоміжний.
 У допоміжний стак будуть пушитись елементи, коли приходить команда
 "pop", то перевіряється чи основний стак не є пустим, якщо він є пустим,
 то всі елементи з допомоміжного стаку попаються і переносяться в основний,
 після чого останній елемент основного стаку попається та повертається.

 Функція peek() працює за таким же принципом, тільки значення в черзі не
 попається.

 Функція empty() повертає true тільки тоді, коли обидва стаки пусті.

 Часова складність алгоритму:
 push(): O(1)
 pop() та peek(): O(n), якщо стак не пустий, то O(1)
 empty: O(1)

 Мій розв'язок на сайті:
 https://leetcode.com/problems/implement-queue-using-stacks/solutions/4646024/two-stacks-one-stack-and-all-o-1-approaches/?envType=daily-question&envId=2024-01-29

 На пайтоні є хороший спосіб зробити це завдання використовуючи лише один
 стак у вигляді списку, завдяки методу pop(), за допомогою якого можна
 ефективно видалити елемент.

 class MyQueue:
    def __init__(self):
        self.myStack = []

    def push(self, x: int) -> None:
        self.myStack.append(x)

    def pop(self) -> int:
        return self.myStack.pop(0)

    def peek(self) -> int:
        return self.myStack[0]

    def empty(self) -> bool:
        if len(self.myStack) == 0:
            return True
        else:
            return False
*/
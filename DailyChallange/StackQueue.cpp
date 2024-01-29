/*
 https://leetcode.com/problems/implement-queue-using-stacks/?envType=daily-question&envId=2024-01-29
 */
class MyQueue {
private:
    stack<int> popStack;
    stack<int> pushStack;
public:
    MyQueue() {

    }

    void push(int x) {
        pushStack.push(x);
    }

    int pop() {
        if(!popStack.empty()){
            int ret = popStack.top();
            popStack.pop();
            return ret;

        } else if (!pushStack.empty()){
            while(!pushStack.empty()){
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            int ret = popStack.top();
            popStack.pop();
            return ret;
        }
        return -1;
    }

    int peek() {
        if (!popStack.empty()) {
            return popStack.top();
        } else if (!pushStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            if (!popStack.empty()) {
                return popStack.top();
            }
        }
        // Handle the case when both stacks are empty
        return -1;
    }


    bool empty() {
        return popStack.empty() && pushStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 /*
  Main idea:

  Використовую два стаки
  один для зберігання всіх елементів, що пушаться
  інший на випадок попу, так як потібно зберігати
  всі елементи під час попу в правильному положені
  Тому, кожного разу як колиться поп, я юзаю стак
  з правильним ордером черги, і використовую лише
  стак для всіх пушів. Оновлююю поп стак лише якщо
  він пустий
  Таким чином пуш стак тримає всі елементи в
  реверснутому положенні, тоді як поп стак тримає
  елементи в правильному
  */
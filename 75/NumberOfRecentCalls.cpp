/*
 https://leetcode.com/problems/number-of-recent-calls/?envType=study-plan-v2&envId=leetcode-75
 */

class RecentCounter {
private:
    int recentRequests;
    queue<int> requests;
public:
    RecentCounter(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        recentRequests = 0;
    }

    int ping(int t) {
        recentRequests++;
        requests.push(t);
        while(t - 3000 > requests.front()){
            requests.pop();
            recentRequests--;
        }
        return recentRequests;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */


/*
 Main idea:
 Нам приходить якесь число.
 Ідея в тому, що всі числа які не входять в проміжок
 наше число - 3000 мають бути викинуті з врахування.
 Також ми маємо інформацію, що наша послідовність чисел
 строго зростає.
 Таким чином, перевіряємо чи перше число >= ніж t-3000.
 Якщо це твердження неправдиве, то видаляємо числа, допоки
 твердження не буде правдивим.
 */
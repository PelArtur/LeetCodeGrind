/*
 https://leetcode.com/problems/asteroid-collision/submissions/1151907566/?envType=study-plan-v2&envId=leetcode-75
 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.empty()){
            return {};
        }

        stack<int> stck;

        for(int asteroid : asteroids){
            if(stck.empty() || asteroid > 0){
                stck.push(asteroid);
                continue;
            }
            if((stck.top() > 0 && asteroid < 0)){
                if(abs(stck.top()) > abs(asteroid)){
                    continue;
                } else if (abs(stck.top()) < abs(asteroid)){
                    stck.pop();

                    while(true){
                        if (!stck.empty() && (stck.top() > 0 && asteroid < 0)){
                            if(abs(stck.top()) < abs(asteroid)){
                                stck.pop();
                            } else if (abs(stck.top()) > abs(asteroid)){
                                break;
                            } else {
                                stck.pop();
                                break;
                            }
                        } else {
                            stck.push(asteroid);
                            break;
                        }
                    }
                } else{
                    stck.pop();
                }
            } else{
                stck.push(asteroid);
            }
        }
        if(stck.empty()){
            return {};
        }

        int size = stck.size();
        vector<int> remainedAsteroids(size);

        for(int idx = size - 1; idx >= 0; --idx){
            remainedAsteroids[idx] = stck.top();
            stck.pop();
        }
        return remainedAsteroids;
    }
};
/*
 Цей солюшин довгий бо я не врахував що астеройди стукаються
 лише якщо top > 0 і asteroid < 0.


 Main idea

 Додавати астероїди в стак якщо вони більше нуля - адже якщо
 в стаці найвищий астероїд додатній, то вони незалежні
 Також якщо в стаці найвищий астероїд від'ємний, то він вже
 летить в іншу сторону(вліво) в той час як поточний астероїд
 летить вправо.

 Якщо в стаці додатній астероїд, а поточний від'ємний, то ми
 розглядаємо три випадки:
 якщо в стаці більший астероїд, то ми скіпаєм ітерацію
 якщо в стаці такий же за розміром астероїд, то ми
 видаляємо цей астероїд і скіпаєм ітерацію
 якщо в стаці менший астероїд, то ми запускаємо цикл, допоки
 не дійдемо до від'ємного астероїда або не видалим весь стак

 У кінці переносимо стак в ліст і повертаємо значення
 Б'є 90% інших людей.


 Тут простіше рішення після того як я проаналізував до кінця
 class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.empty()){
            return {};
        }

        stack<int> stck;

        for(int asteroid : asteroids){
            if(stck.empty() || asteroid > 0){
                stck.push(asteroid);
                continue;
            } else {
                while(!stck.empty() && stck.top() > 0 && abs(stck.top()) < abs(asteroid)){
                    stck.pop();
                }
                if(stck.empty() || stck.top() < 0){
                    stck.push(asteroid);
                } else {
                    if(abs(stck.top()) == abs(asteroid)){
                        stck.pop();
                    }
                }
            }
        }

        if(stck.empty()){
            return {};
        }

        int size = stck.size();
        vector<int> remainedAsteroids(size);

        for(int idx = size - 1; idx >= 0; --idx){
            remainedAsteroids[idx] = stck.top();
            stck.pop();
        }
        return remainedAsteroids;
    }
};
 */
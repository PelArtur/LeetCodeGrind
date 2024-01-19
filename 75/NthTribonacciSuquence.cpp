/*
 https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=study-plan-v2&envId=leetcode-75
 */

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        } else if(n == 1 || n == 2){
            return 1;
        }
        vector<int> tribonacciSequence(n + 1);
        tribonacciSequence[0] = 0;
        tribonacciSequence[1] = 1;
        tribonacciSequence[2] = 1;
        for(int idx = 3; idx <= n; ++idx){
            tribonacciSequence[idx] += tribonacciSequence[idx - 3] + tribonacciSequence[idx - 2] + tribonacciSequence[idx - 1];
        }
        return tribonacciSequence[n];
    }
};

/*
 Main idea:

 Створюємо масив, що буде зберігати послідовність трібоначчі
 Оскільки третій елемент послідовності стоїть за idx = 3,
 то наш n шуканий елемент буде також стояти за індексом n
 Тому ми створюємо масив довжиною n+1, та сетаєм перші три
 елементи масиву числами, що розпочинають послідовність
 Далі для кожного нового елементу додаємо попередні три, поки
 не дійдемо до n-ого елементу. Повертаєм цей елемент
 */
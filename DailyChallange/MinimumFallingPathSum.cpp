/*
 https://leetcode.com/problems/minimum-falling-path-sum/?envType=daily-question&envId=2024-01-19
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if(matrix.size() == 1){
            return matrix[0][0];
        }

        for(int idx = 1; idx < matrix.size(); ++idx){
            for(int jdx = 0; jdx < matrix.size(); ++jdx) {
                if (jdx == 0 && matrix.size() != 1) {
                    matrix[idx][jdx] += min(matrix[idx - 1][jdx + 1], matrix[idx - 1][jdx]);
                } else if (jdx == matrix.size() - 1 && matrix.size() != 1) {
                    matrix[idx][jdx] += min(matrix[idx - 1][jdx - 1], matrix[idx - 1][jdx]);
                } else {
                    matrix[idx][jdx] += min(matrix[idx - 1][jdx],
                                            min(matrix[idx - 1][jdx + 1], matrix[idx - 1][jdx - 1]));
                }
            }
        }
        int minimumPath = 999999;
        for(int idx = 0; idx < matrix.size(); ++idx){
            minimumPath = min(minimumPath, matrix[matrix.size() - 1][idx]);
        }

        return minimumPath;
    }
};

int main(){
    vector<vector<int>> input = {{2,1,3},{6,5,4},{7,8,9}};
    cout << Solution().minFallingPathSum(input);
}

/*
 Main idea

 Починаємо ітерацію з першого рядка, а не 0
 Для кожного елемента вибираємо мінімум, що
 він може отримати з jdx, jdx - 1, jdx + 1.

 { Ідея в тому, щоб для кожної клітинки вибирати
 мінімальне значення, яке вона може отримати.
 Таким чином з просуванням рядка кожна клітинка
 буде залишатись настільки мінімальною, наскільки
 це можливо. }

 Додаємо до цього елемента це значення, таким
 чином створюємо мінімальний шлях. У кінці
 проходимось по останньому рядку й зберігаємо
 мінімальне значення. Повертаємо його.
 */
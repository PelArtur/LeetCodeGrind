/*
 https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=leetcode-75
 */

#include <vector>
#include <iostream>


/*
 Previous not working solution

 class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> startPointer = {height[0], 0};
        vector<int> endPointer = {height[1], 1};

        int areaWithStart = 0;
        int areaWithEnd = 0;
        int currentArea = min(height[0], height[1]) * 1;

        for(int idx = 2; idx < height.size(); ++idx){

            areaWithStart = min(height[idx], startPointer[0]) * (idx - startPointer[1]);
            areaWithEnd = min(height[idx], endPointer[0]) * (idx - endPointer[1]);

            if(areaWithStart > currentArea || areaWithEnd >> currentArea){
                if(areaWithStart - height[idx] > areaWithEnd){
                    endPointer = {height[idx], idx};
                    currentArea = areaWithStart;
                } else{
                    currentArea = areaWithEnd;
                    startPointer = endPointer;
                    endPointer = {height[idx], idx};
                }
            }
        }
        return currentArea;
    }
};
*/
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int start = 0;
        int end = height.size() - 1;

        int result = 0;

        while(start < end){
            result = max(result, min(height[start], height[end]) * (end - start));
            if(height[start] < height[end]){
                start++;
            } else{
                end--;
            }
        }
        return result;
    }
};

int main(){
    vector<int> input = {2,3,10,5,7,8,9};
    cout << Solution().maxArea(input);

    return 0;
}

/*
 Main idea:
 Насправді цей таск доволі зрозумілий, але я щось затупив
 і на годину застряг на ньому.
 Головна ідея: створюємо пойнтери на початок  і кінець відповідно.
 За одну ітерацію рухаємо лівий або правий пойнтер, за кожного руху
 порівнюємо площу води для цих пойнтерів з уже існуючою.
 Вибираємо як рухати наступним чином, якщо стовп правого пойнтера більший
 за лівий, рухаєм лівий, в іншому випадку правий.
 */
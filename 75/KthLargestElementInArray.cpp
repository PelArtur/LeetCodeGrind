/*

 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size()){
            return -1;
        }
        make_heap(nums.begin(), nums.end());
        while(k != 1){
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
            k--;
        }
        return nums[0];
    }
};

/*
 Робим maxheap з нашого масиву за o(n)
 Забираєм k-1 елементів зверху купи, і
 повертаємо елемент, що буде зверху.
 Кожного разу видаляємо елемент зверху
 який є максимумом, таким чином отримуєм
 максимальний елемент на k ітерації.
 */
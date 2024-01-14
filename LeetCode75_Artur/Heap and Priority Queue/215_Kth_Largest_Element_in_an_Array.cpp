/*
 https://leetcode.com/problems/kth-largest-element-in-an-array/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:

    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {3, 2, 1, 5, 6, 4};
    vector<int> test2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    cout << solution.findKthLargest(test1, 2) << endl;
    cout << solution.findKthLargest(test1, 1) << endl;
    cout << solution.findKthLargest(test1, 3) << endl;
    cout << solution.findKthLargest(test1, 5) << endl;

    cout << solution.findKthLargest(test2, 2) << endl;
    cout << solution.findKthLargest(test2, 1) << endl;
    cout << solution.findKthLargest(test2, 3) << endl;
    cout << solution.findKthLargest(test2, 5) << endl;

}

/*
 Main idea:
 Загалом для цього завдання є три алгоритми його розв'язку:
 - посортувати і вернути k-найбільший елемент — тут він
   реалізований вище;
 - через minheap — його детальний опис і реалізація буде в
   пайтонівському варіанті
 - QuickSelect — нижче написав свою реалізацію через quickselect,
   але з ним 40 тест не проходить по часу, навіть з рандомним
   півотом, оскільки там майже всі елементи повторюються і попадається
   випадок зі складність O(n^2).

 Також одна сторінка з рішень цієї задачі із поясненнями плюсів та мінусів
 цих підходів:

 https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/3906260/100-3-approaches-video-heap-quickselect-sorting/?envType=study-plan-v2&envId=leetcode-75

 class Solution
 {
 public:
    int partition(vector<int>& nums, int left, int right)
    {
        srand(time(0));
        int randPivot = rand() % (right - left + 1) + left;
        swap(nums[randPivot], nums[right]);

        int pivot = nums[right];
        int i = left;

        for(int j = left; j < right; ++j)
            if( nums[j] <= pivot )
                swap(nums[i++], nums[j]);

        swap(nums[i], nums[right]);
        return i;
    }

    int quickSelect(vector<int>& nums, int left, int right, int k)
    {
        if( left == right )
            return nums[right];

        int q = partition(nums, left, right);
        int i = q - left + 1;
        if (i == k)
            return nums[q];
        else if( k < i )
            return quickSelect(nums, left, q - 1, k);
        return quickSelect(nums, q + 1, right, k - i);
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        return quickSelect(nums, 0, (int) nums.size() - 1, (int) nums.size() - k + 1);
    }
 };
*/
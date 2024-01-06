/*
 https://leetcode.com/problems/maximum-profit-in-job-scheduling/?envType=daily-question&envId=2024-01-06
*/

#include <iostream>
#include <vector>

using namespace std;

struct work
{
    int startTime;
    int endTime;
    int profit;

    work(int startTime, int endTime, int profit)
    {
        this->startTime = startTime;
        this->endTime = endTime;
        this->profit = profit;
    }
};

class Solution
{
private:
    vector<work> works;
    vector<int> sortedEndTime;
    vector<int> dp;

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        works = {};
        works.reserve(startTime.size());
        for(int i = 0; i < startTime.size(); ++i)
            works.emplace_back(startTime[i], endTime[i], profit[i]);

        auto temp = vector<work>(startTime.size(), work(0, 0, 0));
        mergeSort(works, temp, 0, (int) startTime.size() - 1);

        sortedEndTime = {};
        for(auto workEndTime : works)
            sortedEndTime.push_back(workEndTime.endTime);

        dp = vector<int>(endTime.size(), 0);
        dp[0] = works[0].profit;

        for(int i = 1; i < works.size(); ++i)
        {
            int lowerBoundInd = lowerBound(works[i].startTime);
            dp[i] = max(dp[i-1], works[i].profit + (lowerBoundInd == -1 ? 0 : dp[lowerBoundInd]));
        }

        return dp[endTime.size()-1];
    }

    void merge(vector<work> &arr, vector<work> &temp, int left, int mid, int right)
    {
        int i = left, j = mid, k = left;

        while ((i <= mid - 1) && (j <= right))
        {
            if (arr[i].endTime <= arr[j].endTime)
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

        while (i <= mid - 1)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left; i <= right; i++)
            arr[i] = temp[i];
    }

    void mergeSort(vector<work> &arr, vector<work> &temp, int left, int right)
    {
        if (right > left)
        {
            int mid = (left + right) / 2;
            mergeSort(arr, temp, left, mid);
            mergeSort(arr, temp, mid + 1, right);
            merge(arr, temp, left, mid + 1, right);
        }
    }

    int lowerBound(int val)
    {
        if(sortedEndTime[0] > val)
            return -1;
        int l = 0;
        int r = (int) sortedEndTime.size() - 1;

        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (sortedEndTime[m] <= val)
                l = m + 1;
            else
                r = m;
        }

        return l - 1;
    }
};


int main()
{
    Solution solution;

    vector<vector<int>> test1 = {{1, 2, 3, 3}, {3, 4, 5, 6}, {50, 10, 40, 70}};
    vector<vector<int>> test2 = {{1, 2, 3, 4, 6}, {3, 5, 10, 6, 9}, {20, 20, 100, 70, 60}};
    vector<vector<int>> test3 = {{1, 1, 1}, {2, 3, 4}, {5, 6, 4}};
    vector<vector<int>> test4 = {{4, 2, 4, 8, 2}, {5, 5, 5, 10, 8}, {1, 2, 8, 10, 4}};
    vector<vector<int>> test5 = {{24,24,7,2,1,13,6,14,18,24}, {27,27,20,7,14,22,20,24,19,27}, {6,1,4,2,3,6,5,6,9,8}};

    cout << solution.jobScheduling(test1[0], test1[1], test1[2]) << endl;
    cout << solution.jobScheduling(test2[0], test2[1], test2[2]) << endl;
    cout << solution.jobScheduling(test3[0], test3[1], test3[2]) << endl;
    cout << solution.jobScheduling(test4[0], test4[1], test4[2]) << endl;
    cout << solution.jobScheduling(test5[0], test5[1], test5[2]) << endl;

    return 0;
}

/*
 Main idea:
 Відсортовуємо роботи за часом їх закінчення. В додатковий масив переносимо
 час закінчення всіх робіт уже у відсортованому в неспадайочому порядку.

 Створюємо динамічний масив, у якому зберігатиметься максимальна кількість
 профіту, якщо ми оберемо роботу за індексом і та вона буде останньою або
 оберемо варіант, який її перекриває, але там профіт вищий.

 Проходимось по кожній роботі, шукаємо останню можливу роботу, яку можна з
 нею об'єднати, ця робота має закінчуватись до початку виконання поточної.
 Перевіряємо чи група робіт на попередній ітерації є вигіднішою за новостворену.

 Час роботи O(nlogn):
 Найскладніша операція -> MergeSort за O(nlogn).
 Динаміка циклічно проходить за лінійний час, проте на кожній ітерації викликається
 lower_bound, який працює за logn, тому загальний час роботи динаміки також O(nlogn).

*/
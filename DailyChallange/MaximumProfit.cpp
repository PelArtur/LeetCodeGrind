/*
    Not working solution

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job{
    int start;
    int end;
    int profit;
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int result = 0;
        vector<Job> jobs (startTime.size());
        vector<int> dp(startTime.size());
        vector<int> closestTask(startTime.size());
        Job temp;
        for(int idx = 0; idx < startTime.size(); ++idx){
            temp.start = startTime[idx];
            temp.end = endTime[idx];
            temp.profit = profit[idx];
            jobs[idx] = temp;
        }

        sort(jobs.begin(), jobs.end(), [](Job a, Job b){
            return a.end < b.end;
        });

        closestTask[0] = 0;

        for(int idx = startTime.size() - 1; idx > 0; --idx){
            int k = idx;
            while(jobs[k].end > jobs[idx].start){
                --k;
            }
            if(k > 0){
                closestTask[idx] = k;
            } else {
                closestTask[idx] = 0;
            }
        }
        dp[0] = jobs[0].profit;

        for(int idx = 1; idx < startTime.size(); idx++){
            dp[idx] = max(jobs[idx].profit + (closestTask[idx] != -1 ? dp[closestTask[idx]] : 0), dp[idx-1]);
            result = max(result, dp[idx]);
        }

        return result;
    }
};
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int numJobs = profit.size(); // Number of jobs
        vector<tuple<int, int, int>> jobs(numJobs);

        for (int i = 0; i < numJobs; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());
        vector<int> dp(numJobs + 1);

        for (int i = 0; i < numJobs; ++i) {
            auto [endTime, startTime, profit] = jobs[i];

            int latestNonConflictJobIndex = upper_bound(jobs.begin(), jobs.begin() + i, startTime, [&](int time, const auto& job) -> bool {
                return time <get<0>(job);
            }) - jobs.begin();

            dp[i + 1] = max(dp[i], dp[latestNonConflictJobIndex] + profit);
        }

        return dp[numJobs];
    }
};

/*
 Main idea:

 Така ж ідея як у мене, тільки тут немає undefine behaviour на літкоді...
 Створюємо масив тюплів з значеннями нашої роботи. Сортуємо їх по закінченню.
 Далі логіка така: у набір тасків може бути включений перший таск або ні
 Якщо його вигідно включати, то наступним таском такий, що не конфліктує з
 першим. Якщо першого таску не буде в наборі, то ми одразу дивимось на таск після
 нього. Визначаєм ми чи буде таск у наборі чи ні в залежності, що буде вигідніше
 включити цей таск і таск, що з ним не конфліктує, чи не включати це дерево тасків
 і включити наступний.
 dp[i] - не включати поточний таск
 dp[latestNonConflictJobIndex] + profit - включати поточний таск
 */
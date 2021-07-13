#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param cost: the cost
     * @param val: the val
     * @return: the all cost
     */
    long long doingHomework(vector<int> &cost, vector<int> &val) {
        // Write your code here.
        vector<int> tasksSumTime;
        int sum = 0;
        for (int i = 0; i < cost.size(); ++i) {
            sum += cost[i];
            tasksSumTime.emplace_back(sum);
        }
        int totalTime = 0;
        for (int i = 0; i < val.size(); ++i) {
            totalTime += findClosestFloor(tasksSumTime, val[i]);
        }
        return totalTime;
    }

private:
    int findClosestFloor(const vector<int>& tasksSumTime, int freeTime) {
        int mid = 0;
        int left = 0;
        int right = tasksSumTime.size() - 1;
        while (left <= right)
        {
            mid = (right + left) / 2;
            if (freeTime < tasksSumTime[mid]) {
                // search left
                right = mid - 1;
            } else if (freeTime > tasksSumTime[mid]) {
                // search right
                left = mid + 1;
            } else {
                return freeTime;
            }
        }
        if (freeTime > tasksSumTime[mid]) {
            return tasksSumTime[mid];
        } 
        return mid - 1 >= 0 ? tasksSumTime[mid-1] : 0; 
    }
};


int main() {
    Solution s;
    vector<int> cost{3,7,3,2,5};
    vector<int> val{10,20,12,8,17,25};
    cout<<s.doingHomework(cost, val)<<endl;
}
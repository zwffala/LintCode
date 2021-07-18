#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prevMaxEndIndex = 0;
        return maxSubArrayHelper(nums, nums.size() - 1, prevMaxEndIndex);
    }
    
    int maxSubArrayHelper(const vector<int>& nums, int curIndex, int& prevMaxEndIndex) {
        if (curIndex == 0) {
            prevMaxEndIndex = 0;
            return nums[curIndex];
        }
        
        int prevMax = maxSubArrayHelper(nums, curIndex - 1, prevMaxEndIndex);
        cout<<"prevMaxEndIndex: "<<prevMaxEndIndex<<endl;
        int ans = prevMax;

        if (curIndex - prevMaxEndIndex == 1) {
            int curNumsTotalSum = prevMax + nums[curIndex];
            if (curNumsTotalSum > prevMax) {
                prevMaxEndIndex = curIndex;
                ans = curNumsTotalSum;
            }
        }

        if (ans < nums[curIndex]) {
            prevMaxEndIndex = curIndex;
            ans = nums[curIndex];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{-2,1,-3,4,-1,2,1};
    cout<<s.maxSubArray(nums);
}
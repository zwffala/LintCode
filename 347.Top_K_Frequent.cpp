#include<unordered_map>
#include<vector>
#include<queue>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numsCount;
        vector<int> ans;
        for (int num : nums) {
            numsCount[num] += 1;
        }
        
        auto comp = [&numsCount](const pair<int,int>& numCount1, const pair<int,int>& numCount2){return numCount1.second < numCount2.second;};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> kFrequent(comp);
        
        for (auto entry : numsCount) {
            kFrequent.emplace(entry);
        }
        
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(kFrequent.top().first);
            kFrequent.pop();
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums {1,2,3,3,6,1,4};
    auto ans = s.topKFrequent(nums, 2);
    for (const auto& i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
}
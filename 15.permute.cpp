#include<vector>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        if (nums.empty()) {
            return {};
        }

        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        vector<vector<int>> ans;
        vector<int> currentPermute;
        unordered_set<int> visited;
        dfs(sortedNums, currentPermute, visited, ans);
        return ans;
    }

private:
    void dfs(const vector<int>& sortedNums, vector<int>& currentPermute, unordered_set<int>& visited, vector<vector<int>>& ans) {
        if (currentPermute.size() == sortedNums.size()) {
            ans.emplace_back(currentPermute);
            return;
        }

        for (int i = 0; i < sortedNums.size(); ++i) {
            if (visited.count(sortedNums[i]) == 1) {
                continue;
            }
            visited.emplace(sortedNums[i]);
            currentPermute.emplace_back(sortedNums[i]);
            dfs(sortedNums, currentPermute, visited, ans);
            currentPermute.pop_back();
            visited.erase(sortedNums[i]);
        }
    }
};


int main() {
    Solution s;
    vector<int> nums{1,2,3};
    const auto ans = s.permute(nums);
    cout<<ans.size()<<endl;
    for (const auto& each : ans) {
        for (const auto& num : each) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
}
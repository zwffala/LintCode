#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        if (nums.empty()) {
            return {};
        }

        vector<vector<int>> ans;
        subsetsHelper(ans, nums, 0, {});
        return ans;
    }

private:
    void subsetsHelper(vector<vector<int>>& ans, const vector<int>& nums
        , int index, vector<int> subset) {
        if (index == nums.size()) {
            ans.emplace_back(subset);
            return;
        }

        subsetsHelper(ans, nums, index + 1, subset);
        subset.emplace_back(nums[index]);
        subsetsHelper(ans, nums, index + 1, subset);
        // restore
        subset.pop_back();
    }
};

int main() {
    Solution s;
    vector<int> v{0};
    const auto ans = s.subsets(v);
    for (const auto& subset : ans) {
        for (const auto& i : subset) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}
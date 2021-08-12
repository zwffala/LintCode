#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        vector<int> prefixSum{0};
        int sum = 0;
        for (const auto& num : nums) {
            sum += num;
            prefixSum.emplace_back(sum);
        }

        if (s > prefixSum[prefixSum.size() - 1] || nums.empty()) {
            return -1;
        }

        int minSize = INT_MAX;
        for (int i = 1; i < prefixSum.size(); ++i) {
            int minIndex = prefixSum.size();
            getFirstNoLess(prefixSum, s + prefixSum[i - 1], minIndex, 0, prefixSum.size() - 1);
            if (minIndex > 0 && minIndex < prefixSum.size()) {
                minSize = min(minSize, minIndex - i + 1);
            }
        }
        return minSize == INT_MAX ? -1 : minSize;
    }

private:

    // can be replaced by low_bound in C++20
    void getFirstNoLess(const vector<int>& prefixSum, const int target, int& minIndex, int left, int right) {
        if (left > right) {
            return;
        }

        int mid = (left + right) / 2;
        if (prefixSum[mid] >= target) {
            minIndex = min(minIndex, mid);
            getFirstNoLess(prefixSum, target, minIndex, left, mid - 1);
        } else {
            getFirstNoLess(prefixSum, target, minIndex, mid + 1, right);
        }
    }
};
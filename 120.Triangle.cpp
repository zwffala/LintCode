#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        for (int i = dp.size() - 2; i >= 0; --i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                dp[i][j] += min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution s;
    vector<vector<int>> tri{{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<s.minimumTotal(tri)<<endl;
}
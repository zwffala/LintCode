#include<vector>
#include<iostream>
using namespace std;

// MP[i][0] = max(MP[i-1][0], MP[i-1][1] + prices[i]);
// MP[i][1] = max(MP[i-1][1], MP[i-2][0] - prices[i]);

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size() == 1) {
            return 0;
        }

        vector<vector<int>> MP(prices.size(), vector<int>(2));
        MP[0][0] = 0;
        MP[0][1] = -prices[0];
        MP[1][0] = max(0, prices[1] - prices[0]);
        MP[1][1] = max(-prices[0], -prices[1]);

        for (int i = 2; i < prices.size(); ++i) {
            MP[i][0] = max(MP[i-1][0], MP[i-1][1] + prices[i]);
            MP[i][1] = max(MP[i-1][1], MP[i-2][0] - prices[i]);
        }

        for (int i = 0; i < prices.size(); ++i) {
            cout<<MP[i][0]<<" "<<MP[i][1]<<endl;
        }
        return MP[prices.size()-1][0];
    }
};

int main() {
    Solution s;
    vector<int> v{1,2,3,0,2};
    // v = {1};
    // v = {1,2,4};
    cout<<s.maxProfit(v)<<endl;
}
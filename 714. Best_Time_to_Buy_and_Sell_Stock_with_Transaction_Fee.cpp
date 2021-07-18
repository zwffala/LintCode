#include<vector>
using namespace std;
// MP[i][0] = max(MP[i-1][0], MP[i-1][1] + p[i] - fee)
// MP[i][1] = max(MP[i-1][1], MP[i-1][0] - p[i])

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 1) {
            return 0;
        }
        
        vector<vector<int>> MP(prices.size(), vector<int>(2));
        MP[0][0] = 0;
        MP[0][1] = -prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            MP[i][0] = max(MP[i-1][0], MP[i-1][1] + prices[i] - fee);
            MP[i][1] = max(MP[i-1][1], MP[i-1][0] - prices[i]);
        }
        
        return MP[prices.size()-1][0];
    }
};
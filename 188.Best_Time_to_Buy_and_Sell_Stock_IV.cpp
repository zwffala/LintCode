#include<vector>
#include<iostream>
using namespace std;

// MP[i][k] = max(MP[i-1][k], MP[i-1][k-1] + prices[i])
// ans = max(MP[n-1][k]) k in [0,K]
// the above dp is not correct. consider k = 2, v = {6,1,3,2,4,7}. (1,3) + (2,7). So cannot only consider previous day sell the stock. need to consider previous day hold stock.

// ++k when sell
// MP[i][k][0] = max(MP[i-1][k][0], MP[i-1][k-1][1] + p[i]])
// MP[i][k][1] = max(MP[i-1][k][1], MP[i-1][k][0] - p[i])  
// ans = max(MP[n-1][k][0]) k in [0,K]

// the above dp is not correct either. if we ++k when sell, then we can still buy when we reached K transactions. which is not correct.
// ++K when buy
// MP[i][k][0] = max(MP[i-1][k][0], MP[i-1][k][1] + p[i]])
// MP[i][k][1] = max(MP[i-1][k][1], MP[i-1][k-1][0] - p[i]) 

class Solution {
public:
    enum Status {
        SELL = 0,
        HOLD = 1
    };

    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        vector<vector<vector<long>>> maxProfits(prices.size(), vector<vector<long>>(k+1, vector<long>(2)));

        for (int numTransactions = 0; numTransactions <= k; ++numTransactions) {
            maxProfits[0][numTransactions][0] = 0;
            maxProfits[0][numTransactions][1] = -prices[0];
        }
        for (int i = 0; i < prices.size(); ++i) {
            maxProfits[i][0][SELL] = 0;
            maxProfits[i][0][HOLD] = -prices[i];
        }
        
        for (int i = 1; i < prices.size(); ++i) {
            for (int numTransactions = 1; numTransactions <= k; ++numTransactions) {
                maxProfits[i][numTransactions][SELL] = max(maxProfits[i-1][numTransactions][SELL], maxProfits[i-1][numTransactions][HOLD] + prices[i]);
                maxProfits[i][numTransactions][HOLD] = max(maxProfits[i-1][numTransactions][HOLD], maxProfits[i-1][numTransactions-1][SELL] - prices[i]);

                cout<<"i: "<<i<<" k: "<<numTransactions<<endl;
                cout<<"maxProfits[i-1][numTransactions][SELL]"<<maxProfits[i-1][numTransactions][SELL]<<endl;
                cout<<"maxProfits[i-1][numTransactions][HOLD]"<<maxProfits[i-1][numTransactions][HOLD]<<endl;
                cout<<"MP["<<i-1<<"]["<<numTransactions<<"]["<<SELL<<"]"<<maxProfits[i-1][numTransactions][SELL]<<endl;
                cout<<"MP["<<i-1<<"]["<<numTransactions<<"]["<<HOLD<<"]"<<maxProfits[i-1][numTransactions][HOLD]<<endl;
            }
        }

        long ans = 0;
        for (int numTransactions = 0; numTransactions <=k; ++numTransactions) {
            ans = max(ans, maxProfits[prices.size() - 1][numTransactions][SELL]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{2,4,1};
    int k = 2;

    v = {3,2,6,5,0,3};

    // v = {6,1,3,2,4,7};

    // v = {1,2,4};

    // v = {2,1,4,5,2,9,7};
    cout<<s.maxProfit(k, v)<<endl;
}
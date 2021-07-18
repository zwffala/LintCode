#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        vector<vector<vector<long>>> MP(prices.size(), vector<vector<long>>(3, vector<long>(2)));

        MP[0][1][0] = 0;
        MP[0][2][0] = 0;

        MP[0][1][1] = -prices[0];
        MP[0][2][1] = -prices[0];
        
        for (int i = 0; i < prices.size(); ++i) {
            MP[i][0][1] = INT_MIN;
            MP[i][0][0] = 0;
        }
        
        
        for (int i = 1; i < prices.size(); ++i) {
            for (int k = 1; k <=2; ++k) {
                MP[i][k][0] = max(MP[i-1][k][0], MP[i-1][k][1] + prices[i]);
                MP[i][k][1] = max(MP[i-1][k][1], MP[i-1][k-1][0] - prices[i]);

                cout<<"i: "<<i<<" k: "<<k<<endl;
                cout<<"MP[i-1][k][SOLD]"<<MP[i-1][k][0]<<endl;
                cout<<"MP[i-1][k][HOLD]"<<MP[i-1][k][1]<<endl;
                cout<<"MP["<<i-1<<"]["<<k<<"]["<<0<<"]"<<MP[i-1][k][0]<<endl;
                cout<<"MP["<<i-1<<"]["<<k<<"]["<<1<<"]"<<MP[i-1][k][1]<<endl;
            }
        }
        
        for (int i = 0; i < prices.size(); ++i) {
            for (int k = 0; k <=2; ++k) {
                cout<<MP[i][k][0]<<" ";
            }
            cout<<endl;
            for (int k = 0; k <=2; ++k) {
                cout<<MP[i][k][1]<<" ";
            }
            cout<<endl;
        }

        long ans = 0;
        for (int k = 0; k <=2; ++k) {
            ans = max(ans, MP[prices.size()-1][k][0]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{3,3,5,0,0,3,1,4};
    cout<<s.maxProfit(v)<<endl;
}
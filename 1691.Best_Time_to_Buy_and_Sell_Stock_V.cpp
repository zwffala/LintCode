#include<vector>
#include<queue>
#include<iostream>
using namespace std;


//MP[0][1] = -p[0]
//MP[0][j] = INT_MIN j in [2, n/2]

//MP[i][0] = 0

//MP[i][0] = max(MP[i-1][0], MP[i-1][1] + p[i])
//MP[i][j] = max(MP[i-1][j], MP[i-1][j-1] - p[i], MP[i-1][j+1] + a[i])
//要非常小心边界检测
// j in [0,n/2]
// ans = max(MP[n-1][0])

class Solution {
public:
    /**
     * @param a: the array a
     * @return: return the maximum profit
     */
    int getAns(vector<int> &a) {
        if (a.empty() || a.size() == 1) {
            return 0;
        }

        vector<vector<long>> MP(a.size(), vector<long>(a.size() / 2 + 1));
        for (int i = 0; i < a.size(); ++i) {
            MP[i][0] = 0;
        }
        MP[0][1] = -a[0];
        for (int j = 2; j <= a.size() / 2; ++j) {
            MP[0][j] = INT_MIN;
        }

        for (int i = 1; i < a.size(); ++i) {
            for(int j = 0; j <= a.size() / 2; ++j) {
                if (j == 0) {
                    MP[i][0] = max(MP[i-1][0], MP[i-1][1] + a[i]);
                    continue;
                }
                if (j == a.size() / 2) {
                    MP[i][j] = max(MP[i-1][j], MP[i-1][j-1] - a[i]);
                    continue;
                }
                long tmp = max(MP[i-1][j], MP[i-1][j-1] - a[i]);
                MP[i][j] = max(tmp, MP[i-1][j+1] + a[i]);
            }
        }

        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j <= a.size() / 2; ++j) {
                cout<<MP[i][j]<<" ";
            }
            cout<<endl;
        }

        return MP[a.size() - 1][0];
    }
};

int main() {
    Solution s;
    vector<int> v{1,2,10,9};
    cout<<s.getAns(v)<<endl;
}
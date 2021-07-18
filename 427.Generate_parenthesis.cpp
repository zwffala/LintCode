#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // write your code here
        if (n <= 0) {
            return {};
        }

        vector<string> ans;
        generateParenthesisHelper(ans, n, 0, "", 0, 0);
        return ans;
    }

    void generateParenthesisHelper(vector<string>& ans, const int n, int index, string tmp, int usedLeft, int usedRight) {
        if (index == 2*n) {
            ans.emplace_back(tmp);
            return;
        }

        if (usedLeft < n) {
            generateParenthesisHelper(ans, n, index + 1, tmp + "(", usedLeft + 1, usedRight);
        }
        
        if (usedLeft - usedRight > 0 && usedRight < n) {
            generateParenthesisHelper(ans, n, index + 1, tmp + ")", usedLeft, usedRight + 1);
        }
        return;
        
    }
};

int main() {
    Solution s;
    const auto ans = s.generateParenthesis(3);
    for (const auto& i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
}

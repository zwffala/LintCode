#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> stepsForStairs{0,1,2};
        auto ans =  climb_Stairs(n, stepsForStairs);
        for (auto i : stepsForStairs) {
            cout<<i<<" ";
        }
        cout<<endl;
        return ans;
    }

    int climb_Stairs(int step, vector<int>& stepsForEachStair) {
        if (step <= stepsForEachStair.size() - 1) {
            return stepsForEachStair[step];
        }
        stepsForEachStair.emplace_back(climb_Stairs(step-1, stepsForEachStair)
            + climb_Stairs(step-2, stepsForEachStair));
        return stepsForEachStair[step];
    }
};


// class Solution {
// public:
//     int climbStairs(int n) {
//         int memo[n + 1];
//         return climb_Stairs(0, n, memo);
//     }

//     int climb_Stairs(int i, int n, int memo[]) {
//         if (i > n) {
//             return 0;
//         }
//         if (i == n) {
//             return 1;
//         }
//         if (memo[i] > 0) {
//             return memo[i];
//         }
//         memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
//         return memo[i];
//     }
// };


// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <= 2) {
//             return n;
//         }
//         return climbStairs(n-1) + climbStairs(n-2);
//     }

// };

int main() {
    Solution s;
    vector<int> v(4);
    v[3] = 3;
    for (auto i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<s.climbStairs(5)<<endl;
}
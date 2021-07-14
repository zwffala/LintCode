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
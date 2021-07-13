#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int numOfMissings = nums[i] - prev -1;
            if (numOfMissings != 0) {
                int condition = k - numOfMissings;
                if (condition == 0) {
                    return nums[i]-1;
                } else if (condition < 0) {
                    return prev + k;
                } else {
                    k -= numOfMissings;
                }
            }
            prev = nums[i];
        }
        return prev + k;
    }
};

int main() {
    Solution s;
    vector<int> a{4,7,9,10};
    cout<<s.missingElement(a, 3)<<endl;
    cout<<3/2<<endl;
}
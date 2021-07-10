#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param arr: the distance between any two cities
     * @return: the minimum distance Alice needs to walk to complete the travel plan
     */
	int res = 100000;
    int travelPlan(vector<vector<int>> &arr) {
        // Write your code here.
		// backtracking 实现全排列
		// https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
		// Below link to understand the tree and when recursive pop, it pops to the nodes with more than one child.
		// https://www.youtube.com/watch?v=DKCbsiDBN6c&ab_channel=AbdulBari 
		
		int len = arr.size();
		vector<bool> used(len, false);
		// iterate all paths expect node 0
		dfs(arr, len, 1, used, 0, 0);
		return res;

    }

private:
	void dfs(const vector<vector<int>>& arr, int len, int depth, vector<bool>& used, int distance, int parent ) {
		if (depth == len) {
			distance += arr[parent][0];
			res = min(distance, res);
			return;
		}
		for (int i = 1; i < len; ++i) {
			if (!used[i]){
				used[i] = true;
				cout<<"before recursion"<<endl;
				dfs(arr, len, depth+1, used, distance + arr[parent][i], i);
				used[i] = false;
				cout<<"used["<<i<<"] = false"<<endl;
			}
		}
	}

};

int main() {
	Solution s;
	// vector<vector<int>> arr{{0,1,2},{1,0,2},{2,1,0}};
	// cout<<s.travelPlan(arr)<<endl;
	vector<vector<int>> arr = {{0,1256,1038,1899,1207},{562,0,107,622,10000},{603,496,0,1631,1599},{1147,1445,1078,0,1930},{764,1500,1108,1703,0}};
	cout<<s.travelPlan(arr)<<endl;
}
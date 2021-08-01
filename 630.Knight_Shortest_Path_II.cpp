#include<vector>
#include<utility>
#include<deque>
#include<unordered_set>
#include<iostream>
using namespace std;

// DP
// class Solution {
// public:
//     /**
//      * @param grid: a chessboard included 0 and 1
//      * @return: the shortest path
//      */
//     //  dp[i][j] = min (dp[i-1][j-2]+1, dp[i-2][j-1]+1) when grid[i][j] != 1
//     // get dp[n-1][m-1]
//     int shortestPath2(vector<vector<bool>> &grid) {
//         // write your code here
//         if (grid.empty()) {
//             return -1;
//         }
//         int n = grid.size();
//         int m = grid[0].size();
//         long dp[n][m];
//         dp[0][0] = 0;
//         dp[1][1] = INT_MAX;
//         for (int j = 1; j < m; ++j) {
//             dp[0][j] = INT_MAX;
//         }
//         for (int i = 1; i < n; ++i) {
//             dp[i][0] = INT_MAX;
//         }

//         for (int j = 1; j < m; ++j) {
//             for (int i = 0; i < n; ++i) {
//                 if (grid[i][j] == 1) {
//                     dp[i][j] = INT_MAX;
//                     continue;
//                 }
//                 int prevX1 = i - 1;
//                 int prevY1 = j - 2;
//                 long cost1 = prevX1 < 0 || prevY1 < 0 ? INT_MAX : dp[prevX1][prevY1] + 1;

//                 int prevX2 = i + 1;
//                 int prevY2 = j - 2;
//                 long cost2 = prevX2 > n - 1  || prevY2 < 0 ? INT_MAX : dp[prevX2][prevY2] + 1;

//                 int prevX3 = i - 2;
//                 int prevY3 = j - 1;
//                 long cost3 = prevX3 < 0 || prevY3 < 0 ? INT_MAX : dp[prevX3][prevY3] + 1;

//                 int prevX4 = i + 2;
//                 int prevY4 = j - 1;
//                 long cost4 = prevX4 > n - 1 || prevY4 < 0 ? INT_MAX : dp[prevX4][prevY4] + 1;

//                 long tmp = min(cost1, cost2);
//                 tmp = min(tmp, cost3);
//                 dp[i][j] = min(tmp, cost4);
//             }
//         }
        
//         return dp[n-1][m-1] >= INT_MAX ? -1 : dp[n-1][m-1];
//     }
// };

// BFS
class Solution {
public:
    /**
     * @param grid: a chessboard included 0 and 1
     * @return: the shortest path
     */
    int shortestPath2(vector<vector<bool>> &grid) {
        if (grid.empty()) {
            return -1;
        }

        vector<pair<int, int>> directions{{1, 2}, {-1, 2},{2, 1},{-2, 1}};
        deque<pair<int,int>> positions{{0,0}};
        // due to pair has not default hash func. Use vector here
        vector<pair<int,int>> visited{{0,0}};
        int n = grid.size();
        int m = grid[0].size();
        int level = -1;
        while (!positions.empty()) {
            ++level;
            int size = positions.size();
            for (int i = 0; i < size; ++i) {
                const auto& position = positions.front();
                if (position.first == n - 1 && position.second == m - 1) {
                    return level;
                }
                positions.pop_front();
                for (const auto& direction : directions) {
                    pair<int,int> newPosition(position.first + direction.first, position.second + direction.second);
                    if (newPosition.first >= 0 && newPosition.first < n && newPosition.second > position.second && newPosition.second < m && grid[newPosition.first][newPosition.second] == 0) {
                        if (find(visited.begin(), visited.end(), newPosition) == visited.end()) {
                            positions.emplace_back(newPosition);
                            visited.emplace_back(newPosition);
                        }
                    }
                }
            }
            
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<bool>> v{{0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
    // v = {{0,1,0},{0,0,1},{0,0,0}};
    v = {{0,0,0,0},{0,0,0,0},{0,1,0,0}};
    cout<<s.shortestPath2(v)<<endl;
}
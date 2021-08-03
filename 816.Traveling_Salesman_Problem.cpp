#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n: an integer,denote the number of cities
     * @param roads: a list of three-tuples,denote the road between cities
     * @return: return the minimum cost to travel all cities
     */
    int minCost(int n, vector<vector<int>> &roads) {
        // Write your code here
        if (roads.empty()) {
            return 0;
        }

        long minCost = INT_MAX;
        vector<bool> visited(n + 1, false);
        visited[1] = true;
        dfs(1, 1, 0, minCost, visited, roads, n);
        return minCost;
    }

private:
    void dfs(int prevCity, int numVisitedCities, long currentCost, long& minCost,
            vector<bool>& visited, const vector<vector<int>>& roads, int numCities) {
        if (currentCost > minCost) {
            return;
        }
        if (numVisitedCities == numCities) {
            minCost = currentCost;
            return;
        }

        for (int i = 1; i <= numCities; ++i) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            dfs(i, numVisitedCities + 1, currentCost + getTravelCost(prevCity, i, roads), minCost,visited, roads, numCities);
            visited[i] = false;
        }
    }

    int getTravelCost(int prevCity, int currentCity, const vector<vector<int>>& roads) {
        if (prevCity == 0) {
            return 0;
        }

        int prevToCurrent = INT_MAX;
        int currentToPrev = INT_MAX;
        for (const auto& cityCost : roads) {
            if (cityCost[0] == prevCity && cityCost[1] == currentCity) {
                prevToCurrent = cityCost[2];
                continue;
            }
            if (cityCost[0] == currentCity && cityCost[1] == prevCity) {
                currentToPrev = cityCost[2];
                continue;
            }
        }
        return min(prevToCurrent, currentToPrev);
    }
};

int main() {
    Solution s;
    vector<vector<int>> roads{{1,2,1},{2,3,8},{1,3,1}};
    cout<<s.minCost(3, roads)<<endl;
}
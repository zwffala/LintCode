#include<vector>
#include<iostream>
using namespace std;


// follow up
// 做所有点到其他点的路径集合
// 1. 还是用dfs求一个source到target的所有路径 O(2^n)
// 2. 对（source，target）组合。n*(n-1)

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if (graph.empty()) {
            return {{}};
        }
        
        vector<vector<int>> ans;
        vector<int> currentPath{0};
        vector<bool> visited(graph.size(), false);
        visited[0] = true;
        dfs(graph, 0, graph.size() - 1, currentPath, visited, ans);
        return ans;
    }
    
private:
    void dfs(const vector<vector<int>>& graph, int currentNode, const int target, 
             vector<int>& currentPath, vector<bool>& visited, vector<vector<int>>& ans) {
        
        if (currentPath[currentPath.size() - 1] == target) {
            ans.emplace_back(currentPath);
            return;
        }
        
        for (const auto node : graph[currentNode]) {
            if (visited[node]) {
                continue;
            }
            currentPath.emplace_back(node);
            visited[node] = true;
            dfs(graph, node, target, currentPath, visited, ans);
            visited[node] = false;
            currentPath.pop_back();
        }
    }
};
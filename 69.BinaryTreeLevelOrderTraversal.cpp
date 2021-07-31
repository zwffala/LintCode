#include<vector>
#include<deque>
#include<iostream>
using namespace std;

// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

// Dummy node
// class Solution {
// public:
//     /**
//      * @param root: A Tree
//      * @return: Level order a list of lists of integer
//      */
//     vector<vector<int>> levelOrder(TreeNode * root) {
//         // write your code here
//         if (root == nullptr) {
//             return {};
//         }
//         deque<const TreeNode* const> levelNodes{root, nullptr};
//         vector<int> levelNodesValue;
//         vector<vector<int>> ans;
//         while (!levelNodes.empty()) {
//             if (levelNodes.front() != nullptr) {
//                 const auto& node = levelNodes.front();
//                 levelNodesValue.emplace_back(node->val);
//                 if (node->left != nullptr) {
//                     levelNodes.emplace_back(node->left);
//                 }
//                 if (node->right != nullptr) {
//                     levelNodes.emplace_back(node->right);
//                 }
//                 levelNodes.pop_front();
//             } else {
//                 if (!levelNodesValue.empty()) {
//                     ans.emplace_back(levelNodesValue);
//                     levelNodesValue.clear();
//                     levelNodes.emplace_back(nullptr);
//                 }
//                 levelNodes.pop_front();
//             }
//         }
//         return ans;
//     }
// };

// 单数组
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode * root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> ans;
        vector<int> levelVals;
        deque<reference_wrapper<const TreeNode>> nodes{*root};
        while (!nodes.empty()) {
            int size = nodes.size();
            for (int i = 0; i < size; ++i) {
                const auto& node = nodes.front().get();
                levelVals.emplace_back(node.val);
                if (node.left != nullptr) {
                    nodes.emplace_back(*(node.left));
                }
                if (node.right != nullptr) {
                    nodes.emplace_back(*(node.right));
                }
                nodes.pop_front();
            }
            ans.emplace_back(levelVals);
            levelVals.clear();
        }
        return ans;
    }
};


int main () {
    Solution s;
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    const auto ans = s.levelOrder(&root);
    for (const auto& levelNodes : ans) {
        for_each(levelNodes.begin(), levelNodes.end(), [](const auto& val){ cout<<val<<" ";});
        cout<<endl;
    }
}
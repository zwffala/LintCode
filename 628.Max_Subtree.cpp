#include<climits>
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


 struct MaxSubtree {
     int max;
    TreeNode* node;
     MaxSubtree() : max(INT_MIN), node(nullptr) {}
     MaxSubtree(int val, TreeNode* node)
     : max(val)
     , node(node) {}
 };

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the maximum weight node
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        if (root == nullptr) {
            return root;
        }

        MaxSubtree maxSubtree;
        findMaxSubtree(root, maxSubtree);
        return maxSubtree.node;
    }

private:
    int findMaxSubtree(TreeNode* const node, MaxSubtree& maxSubtree) {
        if (node == nullptr) {
            return 0;
        }

        int leftSum = findMaxSubtree(node->left, maxSubtree);
        int rightSum = findMaxSubtree(node->right, maxSubtree);
        int current = leftSum + rightSum + node->val;
        if (current >= maxSubtree.max) {
            maxSubtree.max = current;
            maxSubtree.node = node;
        }
        return current;
        
    }
};

int main() {
    TreeNode root(1);
    TreeNode right(2);
    root.right = &right;
    Solution s;
    s.findSubtree(&root);
}
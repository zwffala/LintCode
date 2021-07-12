
#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode* successor = NULL;
    const TreeNode* target = NULL;
    bool foundTarget = false;
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        target = p;
        inorderTraverse(root);
        return successor;
    }
private:
    void inorderTraverse(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        if (successor) {
            return;
        }
        inorderTraverse(node->left);
        if (node == target) {
            foundTarget = true;
        } else {
            if (foundTarget) {
                successor = node;
                foundTarget = false;
                return;
            }
        }
        inorderTraverse(node->right);
    }
};

int main() {
    Solution s;
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    n4.left = &n3;
    n4.right = &n5;
    n3.left = &n2;
    n5.right = &n6;

    const auto p = s.inorderSuccessor(&n4, &n2);
    if (p) {
        cout<<p->val<<endl;
    }
}
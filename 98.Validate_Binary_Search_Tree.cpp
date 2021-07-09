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

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        // write your code here
		if (!root) {
			return true;
		}
		vector<int> valInTree;
		traverse(root, valInTree);
		for (int i = 0, j = 1; j < valInTree.size(); ++i, ++j) {
			if (valInTree[i]>=valInTree[j]) {
				return false;
			}
		}
		return true;
    }

	void traverse(TreeNode* root, vector<int>& valInTree) {
		if (root) {
			traverse(root->left, valInTree);
			valInTree.emplace_back(root->val);
			traverse(root->right, valInTree);
		}
	}
};

int main() {
	Solution s;
	// TreeNode n1(1);
	// TreeNode n3(3);
	// TreeNode n2(2);
	// n2.left = &n1;
	// n2.right = &n3;
	// cout<<s.isValidBST(&n2)<<endl;
	TreeNode n1(1);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	n5.left = &n1;
	n5.right = &n4;
	n4.left = &n3;
	n4.right = &n6;
	cout<<s.isValidBST(&n5)<<endl;
}
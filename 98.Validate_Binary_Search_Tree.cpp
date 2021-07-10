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

// 1. Using Recursion
// class Solution {
// public:
//     /**
//      * @param root: The root of binary tree.
//      * @return: True if the binary tree is BST, or false
//      */
//     bool isValidBST(TreeNode * root) {
//         // write your code here
// 		if (!root) {
// 			return true;
// 		}
// 		vector<int> valInTree;
// 		traverse(root, valInTree);
// 		for (int i = 0, j = 1; j < valInTree.size(); ++i, ++j) {
// 			if (valInTree[i]>=valInTree[j]) {
// 				return false;
// 			}
// 		}
// 		return true;
//     }

// 	void traverse(TreeNode* root, vector<int>& valInTree) {
// 		if (root) {
// 			traverse(root->left, valInTree);
// 			valInTree.emplace_back(root->val);
// 			traverse(root->right, valInTree);
// 		}
// 	}
// };

// class Solution {
// private:
//     long long  prev = static_cast<long long>(INT_MIN) - 1;
// public:
//     /**
//      * @param root: The root of binary tree.
//      * @return: True if the binary tree is BST, or false
//      */
//     bool isValidBST(TreeNode *root) {
//        if (root == NULL) {
// 		   return true;
// 	   }
// 	   if (!isValidBST(root->left)) {
// 		   return false;
// 	   }
// 	   if (root->val<=prev) {
// 		   return false;
// 	   }
// 	   prev = root->val;
// 	   return isValidBST(root->right);
//     }
// };

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
       return isValidBST(root, static_cast<long long>(INT_MIN)-1);
    }
private:
	bool isValidBST(TreeNode *node, long long prev) {
		if (node == NULL) {
		   return true;
		}
		if (!isValidBST(node->left, prev)) {
			return false;
		}
		if (node->val<=prev) {
			return false;
		}
		prev = node->val;
		return isValidBST(node->right, prev);
	}
};

// 2. Interative
// #include<queue>
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         deque<TreeNode*> stk;
// 		if (!root) {
// 			return true;
// 		}
// 		long long  prev = (long long) INT_MIN -1;
// 		auto node = root;
//         while (node != nullptr || !stk.empty()) {
//             while (node != nullptr) {
//                 stk.emplace_back(node);
//                 node = node->left;
//             }
//             node = stk.back();
// 			if (node->val<=prev) {
// 				return false;
// 			} else {
// 				prev = node->val;
// 				stk.pop_back();
// 			}
            
//             node = node->right;
//         }
//         return true;
//     }
// };


int main() {
	Solution s;
	TreeNode n1(1);
	TreeNode n1Again(1);
	n1.left = &n1Again;
	cout<<s.isValidBST(&n1)<<endl;
	// Solution s;
	// TreeNode n1(1);
	// TreeNode n2(2);
	// TreeNode n3(2);
	// n2.left = &n1;
	// n2.right = &n3;
	// cout<<s.isValidBST(&n2)<<endl;

	// TreeNode n1(1);
	// TreeNode n3(3);
	// TreeNode n4(4);
	// TreeNode n5(5);
	// TreeNode n6(6);
	// n5.left = &n1;
	// n5.right = &n4;
	// n4.left = &n3;
	// n4.right = &n6;
	// cout<<s.isValidBST(&n5)<<endl;
}
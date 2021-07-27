#include<vector>
#include<iostream>
using namespace std;

//  二分法
// class Solution {
// public:
//     /**
//      * @param A: An integer array
//      * @param queries: The query list
//      * @return: The number of element in the array that are smaller that the given integer
//      */
//     vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
//         // write your code here
//         if (queries.empty()) {
//             return {};
//         }

//         sort(A.begin(), A.end());

//         vector<int> ans;
//         for (const auto& query : queries) {
//             int count = 0;
//             findCountSmallerThanQuery(A, query, 0, A.size() - 1, count);
//             ans.emplace_back(count);
//         }
//         return ans;
//     }

// private:
//     void findCountSmallerThanQuery(const vector<int>& v, int query, int begin, int end, int& ans) {
//         if (begin == end) {
//             ans = v[begin] < query ? ans + 1 : ans;
//             return;
//         }

//         if (begin > end) {
//             return;
//         }

//         int mid = (begin + end) / 2;
//         if (v[mid] >= query) {
//             return findCountSmallerThanQuery(v, query, begin, mid - 1, ans);
//         }
//         if (v[mid] < query) {
//             ans = mid + 1;
//             return findCountSmallerThanQuery(v, query, mid + 1, end, ans);
//         }
//     }
// };

// prefix sum arrary
// class Solution {
// public:
//     /**
//      * @param A: An integer array
//      * @param queries: The query list
//      * @return: The number of element in the array that are smaller that the given integer
//      */
//     vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
//         int maxInA = 0;
//         for (int i = 0; i < A.size(); ++i) {
//             maxInA = max(maxInA, A[i]);
//         }
        
//         vector<int> countOfIndex(maxInA, 0);

//         for (const auto& num : A) {
//             ++countOfIndex[num];
//         }

//         vector<int> countSmallerThanIndex;
//         int sum = 0;
//         countSmallerThanIndex.emplace_back(sum);
//         for (const auto& count : countOfIndex) {
//             sum += count;
//             countSmallerThanIndex.emplace_back(sum);
//         }

//         vector<int> ans;
//         for (const auto& query : queries) {
//             query >= countSmallerThanIndex.size() ? ans.emplace_back(A.size()) : ans.emplace_back(countSmallerThanIndex[query]);
//         }
//         return ans;
//     }
// };


// Segment tree
// 249. Count of smaller numbers before itself
struct SegmentTreeNode {
    int start;
    int end;
    int count;
    unique_ptr<SegmentTreeNode> left;
    unique_ptr<SegmentTreeNode> right;
    SegmentTreeNode(int start, int end)
    : start(start)
    , end(end) 
    , count(0)
    {}
};

class SegmentTree {
public:
    SegmentTree(const vector<int>& A) {
        int maxNum = 0;
        for (int i = 0; i < A.size(); ++i) {
            maxNum = max(maxNum, A[i]);
        }
        mRoot = buildTree(0, maxNum);

        for (int i = 0; i < A.size(); ++i) {
            updateTree(mRoot.get(), A[i]);
        }
    }

    int query(int val) {
        return val == 0 ? 0 : query(mRoot.get(), 0, val - 1);
    }

private:

    int query(const SegmentTreeNode* const node, int start, int end) {
        if (node->start >= start && node->end <= end) {
            return node->count;
        }

        int mid = (node->start + node->end) / 2;
        if (mid >= end) {
            return query(node->left.get(), start, end);
        }
        if (mid < start) {
            return query(node->right.get(), start, end);
        }
        return query(node->left.get(), start, mid) + query(node->right.get(), mid + 1, end);

    }

    void updateTree(SegmentTreeNode* const node, int val) {
        if (node->start == node->end && node->start == val) {
            ++(node->count);
            return;
        }

        int mid = (node->start + node->end) / 2;
        if (val <= mid) {
            updateTree(node->left.get(), val);
        } else {
            updateTree(node->right.get(), val);
        }
        node->count = node->left->count + node->right->count;
        return;
    }

    unique_ptr<SegmentTreeNode> buildTree(int start, int end) {
        auto node = make_unique<SegmentTreeNode>(start, end);
        if (start == end) {
            return node;
        }

        int mid = (start + end) / 2;
        node->left = buildTree(start, mid);
        node->right = buildTree(mid + 1, end);
        return node;
    }

    unique_ptr<SegmentTreeNode> mRoot;
};

class Solution {
public:
    /**
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        SegmentTree tree(A);

        vector<int> ans;
        for_each(begin(queries), end(queries), [&ans, &tree](int query){ ans.emplace_back(tree.query(query)); });
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{1,2,3,4,5,6};
    vector<int> q{1,2,3,4};

    v = {};
    q = {86,59,39};
    const auto ans = s.countOfSmallerNumber(v, q);
    for (int i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
}
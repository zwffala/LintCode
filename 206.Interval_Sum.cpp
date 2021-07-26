#include<vector>
#include<memory>
#include<iostream>
using namespace std;


// Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};


// 前缀和
// class Solution {
// public:
//     /**
//      * @param A: An integer list
//      * @param queries: An query list
//      * @return: The result list
//      */
//     vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
//         // write your code here
//         vector<long long > sumIncludeAndBeforeIndex;
//         long long sum = 0;
//         for (int i = 0; i < A.size(); ++i) {
//             sum += A[i];
//             sumIncludeAndBeforeIndex.emplace_back(sum);
//         }

//         vector<long long> ans;
//         for (int i = 0; i < queries.size(); ++i) {
//             ans.emplace_back(getSum(queries[i].start, queries[i].end, sumIncludeAndBeforeIndex));
//         }
//         return ans;
//     }

// private:
//     long long getSum(int start, int end, const vector<long long>& sumIncludeAndBeforeIndex) {
//         return start == 0 ? sumIncludeAndBeforeIndex[end] : (sumIncludeAndBeforeIndex[end] - sumIncludeAndBeforeIndex[start - 1]);
//     }
// };


// Segment tree
struct SegmentTreeNode {
    int start;
    int end;
    long long sum;
    unique_ptr<SegmentTreeNode> left;
    unique_ptr<SegmentTreeNode> right;
    SegmentTreeNode(int start, int end)
    : start(start)
    , end(end)
    , sum(0)
    , left(nullptr)
    , right(nullptr) {}
};

class SegmentTree {
public:
    SegmentTree(const vector<int>& data) 
    : root(buildTree(data, 0, data.size() - 1))
    {}

    long long querySum(int start, int end) const {
        if (root == nullptr) {
            return LONG_MIN;
        }
        return querySum(root.get(), start, end);
    }
private:
    unique_ptr<SegmentTreeNode> buildTree(const vector<int>& data, int start, int end) {
        auto node = make_unique<SegmentTreeNode>(start, end);
        if (start == end) {
            node->sum = data[start];
            return node;
        }

        int mid = (start + end) / 2;
        node->left = buildTree(data, start, mid);
        node->right = buildTree(data, mid + 1, end);
        node->sum = node->left->sum + node->right->sum;
        return node;
    }

    long long querySum(const SegmentTreeNode* const node, int start, int end) const {
        if (node == nullptr) {
            return LONG_MIN;
        }
        if (node->start == node->end) {
            return node->sum;
        }
        
        int mid = (node->start + node->end) / 2;
        if (mid >= end) {
            return querySum(node->left.get(), start, end);
        }
        if (mid < start) {
            return querySum(node->right.get(), start, end);
        }
        return querySum(node->left.get(), start, mid) + querySum(node->right.get(), mid + 1, end);
    }

    unique_ptr<SegmentTreeNode> root;
};

class Solution {
public:
    /**
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        const auto tree = SegmentTree(A);
        vector<long long> ans;
        for (const auto i : queries) {
            ans.emplace_back(tree.querySum(i.start, i.end));
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> v{1,2,7,8,5};
    vector<Interval> interval{{0,4},{1,2},{2,4}};
    const auto ans = s.intervalSum(v, interval);
    for (const auto& i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;

    const auto node = SegmentTreeNode(1,2);
    const auto leftNode = node.left.get();
    if (!leftNode) {
        cout<<"ok"<<endl;
    }
}
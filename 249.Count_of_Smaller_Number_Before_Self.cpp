#include<vector>
#include<memory>
#include<iostream>
using namespace std;

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
    , left(nullptr)
    , right(nullptr) {}
};

class SegmentTree {
public:
    SegmentTree(int size)
    : mTreeEnd(size)
    , mRoot(buildTree(0, mTreeEnd))
    {}

    int query(int num) {
        modifyTree(mRoot.get(), 0, mTreeEnd, num);
        return num == 0 ? 0 : getCountOfSmallerNumber(mRoot.get(), 0, num - 1);
    }

private:
    int getCountOfSmallerNumber(const SegmentTreeNode* const node, int start, int end) const {
        if (node->start == start && node->end == end) {
            return node->count;
        }

        int mid = (node->start + node->end) / 2;
        if (mid >= end) {
            return getCountOfSmallerNumber(node->left.get(), start, end);
        }
        if (mid < start) {
            return getCountOfSmallerNumber(node->right.get(), start, end);
        }
        return getCountOfSmallerNumber(node->left.get(), start, mid) + getCountOfSmallerNumber(node->right.get(), mid + 1, end);
    }

    void modifyTree(SegmentTreeNode* const node, int start, int end, int val) {
        if (start == end) {
            ++node->count;
            return;
        }

        int mid = (start + end) / 2;
        if (val <= mid) {
            modifyTree(node->left.get(), start, mid, val);
        } else {
            modifyTree(node->right.get(), mid + 1, end, val);
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
        node->left = move(buildTree(start, mid));
        node->right = move(buildTree(mid + 1, end));
        return node;
    }

    int mTreeEnd;
    unique_ptr<SegmentTreeNode> mRoot;
};

class Solution {
public:
    /**
     * @param A: an integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        int maxNum = 0;
        for_each(begin(A), end(A), [&maxNum](int num){ maxNum = max(num, maxNum); });

        SegmentTree tree(maxNum);
        vector<int> ans;
        for_each(begin(A), end(A), [&ans, &tree](const auto& num){ ans.emplace_back(tree.query(num)); });
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{1,2,7,8,5};
    v = {7,8,2,1,3};
    v = {};
    v = {73,82,74,12,25,0,33,46,79,90,6,97,18,84,34,54,64,5,54,44,74,95,90,24,70,94,12,41,79,88,48,82,89,100,33,3,23,21,90,50,26,3,4,21,67,24,59,62,9,78,60,40,4,40,7,5,54,38,68,66};
    const auto ans = s.countOfSmallerNumberII(v);
    for_each(begin(ans), end(ans), [](const auto& num){ cout<<num<<" "; });
    cout<<endl;
}
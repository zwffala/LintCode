// Leetcode 
// -104 <= nums[i] <= 104

#include<vector>
#include<deque>
#include<memory>
#include<iostream>
using namespace std;

struct  SegmentTreeNode {
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
    SegmentTree(int start, int end) : mRoot(buildTree(start, end)) {}

    int query(int start, int end) {
        int ans =  query(mRoot.get(), start, end);
        end < start ? modify(mRoot.get(), start) : modify(mRoot.get(), end + 1);
        return ans;
    }

private:
    void modify(SegmentTreeNode* const node, int val) {
        if (node->start == node->end) {
            ++node->count;
            return;
        }

        int mid = floor((node->start + node->end) / 2.0);
        if (val <= mid) {
            modify(node->left.get(), val);
        } else {
            modify(node->right.get(), val);
        }
        node->count = node->left->count + node->right->count;
        return;
    }

    int query(const SegmentTreeNode* const node, int start, int end) const {
        if (end < start) {
            return 0;
        }
        if (node->start == start && node->end == end) {
            return node->count;
        }

        int mid = floor((node->start + node->end) / 2.0);
        if (mid < start) {
            return query(node->right.get(), start, end);
        }
        if (mid >= end) {
            return query(node->left.get(), start, end);
        }
        return query(node->left.get(), start, mid) + query(node->right.get(), mid + 1, end);
    }

    unique_ptr<SegmentTreeNode> buildTree(int start, int end) {
        auto node = move(make_unique<SegmentTreeNode>(start, end));
        if (start == end) {
            return node;
        }

        int mid = floor((start + end) / 2.0);
        node->left = move(buildTree(start, mid));
        node->right = move(buildTree(mid + 1, end));
        return node;
    }

    unique_ptr<SegmentTreeNode> mRoot;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for (const auto& num : nums) {
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }

        SegmentTree tree(minNum, maxNum);
        deque<int> ans;
        for_each(rbegin(nums), rend(nums), [&ans, &tree, minNum](int num){ ans.emplace_front(tree.query(minNum, num - 1)); });
        return vector<int>(ans.begin(), ans.end());
    }
};

int main() {
    Solution s;
    vector<int> v{-1, -2};
    const auto ans = s.countSmaller(v);
    for_each(begin(ans), end(ans), [](int num){ cout<<num<<" ";});

    // cout<<floor(3/2.0)<<endl;
    // cout<<floor(-1.5)<<endl;
    // cout<<floor(-3 / 2.0)<<endl;
    // cout<<int(-3 / 2.0)<<endl;
    
}
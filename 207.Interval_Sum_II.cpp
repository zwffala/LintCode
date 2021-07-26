#include<vector>
#include<memory>
#include<iostream>
using namespace std;

//前缀和
// class Solution {
// public:
//     /* you may need to use some attributes here */

//     /*
//     * @param A: An integer array
//     */
//     Solution(vector<int> A) {
//         // do intialization if necessary
//         long long sum = 0;
//         for (const auto item : A) {
//             sum += item;
//             mIntervalSum.emplace_back(sum);
//         }
//     }

//     /*
//      * @param start: An integer
//      * @param end: An integer
//      * @return: The sum from start to end
//      */
//     long long query(int start, int end) {
//         // write your code here
//         return start == 0 ? mIntervalSum[end] : (mIntervalSum[end] - mIntervalSum[start - 1]);
//     }

//     /*
//      * @param index: An integer
//      * @param value: An integer
//      * @return: nothing
//      */
//     void modify(int index, int value) {
//         // write your code here
//         int delta = value - query(index, index);
//         for (int i = index; i < mIntervalSum.size(); ++i) {
//             mIntervalSum[i] += delta;
//         }
//     }

// private:
//     vector<long long> mIntervalSum;
// };

//Segment tree
namespace IntervalSum {
    struct  SegmentTreeNode
    {
        int start;
        int end;
        int sum;
        unique_ptr<SegmentTreeNode> left;
        unique_ptr<SegmentTreeNode> right;
        
        SegmentTreeNode(int start, int end)
        : start(start)
        , end(end) {}
    };

    class SegmentTree {
    public:
        SegmentTree(const vector<int>& data) {
            if (data.empty()) {
                mRoot = nullptr;
            } else {
                mRoot = move(buildSegmentTree(data, 0, data.size() - 1));
            }
        }

        long long query(int start, int end) {
            return query(mRoot.get(), start, end);
        }

        void modify(int index, int value) {
            modify(mRoot.get(), index, value);
        }

    private:

        void modify(SegmentTreeNode* const node, int index, int value) {
            if (node == nullptr) {
                return;
            }
            if (index == node->start && index == node->end) {
                node->sum = value;
                return;
            }

            int mid = (node->start + node->end) / 2;
            if (index <= mid) {
                modify(node->left.get(), index, value);
            } else {
                modify(node->right.get(), index, value);
            }
            node->sum = node->left->sum + node->right->sum;
            return;
        }

        long long query(const SegmentTreeNode* const node, int start, int end) const {
            if (node == nullptr) {
                return LONG_MIN;
            }
            if (start == node->start && end == node->end) {
                return node->sum;
            }

            int mid = (node->start + node->end) / 2;
            if (mid < start) {
                return query(node->right.get(), start, end);
            }
            if (mid >= end) {
                return query(node->left.get(), start, end);
            }
            return query(node->left.get(), start, mid) + query(node->right.get(), mid + 1, end);
        }
        unique_ptr<SegmentTreeNode> buildSegmentTree(const vector<int>& data, int start, int end) {
            auto node = make_unique<SegmentTreeNode>(start, end);
            if (start == end) {
                node->sum = data[start];
                return node;
            }

            int mid = (start + end) / 2;
            node->left = buildSegmentTree(data, start, mid);
            node->right = buildSegmentTree(data, mid + 1, end);
            node->sum = node->left->sum + node->right->sum;
            return node;
        }
        unique_ptr<SegmentTreeNode> mRoot;
    };
}


class Solution {
public:
    /* you may need to use some attributes here */

    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) {
        // do intialization if necessary
       mTree = make_unique<IntervalSum::SegmentTree>(A);
    }

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        if (mTree == nullptr) {
            return LONG_MIN;
        }

        return mTree->query(start, end);
    }

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        // write your code here
       if (mTree != nullptr) {
         mTree->modify(index, value);
       }
    }

private:
    unique_ptr<IntervalSum::SegmentTree> mTree;
};

int main() {
    Solution s({1,2,7,8,5});
    cout<<s.query(0,2)<<endl;
    Solution s1({});
}
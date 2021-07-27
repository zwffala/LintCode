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
namespace {
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
}


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
        if (start == node->start && end == node->end) {
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
        const auto tree = move(SegmentTree(A));
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
    

    v = {7179,7180,7179,7181,7182,7184,7185,7186,7185,7187,7188,7187,7187,7186,7185,7186,7188,7187,7189,7190,7191,7193,7193,7193,7195,7196,7198,7200,7201,7202,7201,7203,7203,7205,7207,7209,7211,7211,7212,7212,7213,7214,7216,7215,7215,7215,7214,7216,7216,7218,7219,7221,7221,7220,7221,7223,7225,7225,7226,7225,7226,7228,7229,7230,7229,7229,7228,7230,7231,7233,7234,7234,7234,7233,7233,7235,7237,7236,7236,7238,7237,7239,7238,7238,7237,7237,7238,7240,7239,7239,7240,7242,7242,7243,7245,7245,7245,7246,7245,7244,7246,7248,7249,7251,7250,7252,7252,7254,7254,7255,7256,7258,7258,7257,7257,7256,7257,7256,7255,7256,7256,7257,7256,7257,7257,7257,7258,7257,7259,7258,7257,7259,7258,7259,7259,7261,7260,7259,7260,7260,7259,7258,7260,7260,7259,7258,7258,7258,7260,7262,7262,7263,7262,7264,7265,7267,7266,7265,7265,7266,7265,7267,7268,7267,7267,7268,7268,7267,7266,7268,7270,7270,7271,7270,7271,7271,7270,7270,7272,7271,7273,7273,7272,7272,7274,7275,7274,7275,7274,7274,7273,7272,7271,7272,7271,7270,7271,7272,7272,7273,7275,7274,7275,7274,7276,7276,7277,7276,7276,7278,7278,7278,7278,7277,7277,7277,7277,7278,7279,7281,7281,7282,7283,7282,7284,7286,7285,7285,7284,7285,7286,7285,7285,7285,7286,7286,7288,7289,7290,7289,7290,7290,7290,7289,7290,7290,7290,7291,7292,7292,7292,7292,7291,7291,7292,7294,7295,7296,7296,7298,7297,7297,7297,7297,7299,7298,7297,7296,7295,7296,7298,7297,7299,7298,7300,7301,7301,7300,7301,7303,7303,7304,7305,7305,7306,7306,7306,7308,7309,7308,7307,7308,7307,7308,7310,7311,7311,7310,7309,7308,7309,7311,7312,7311,7312,7312,7312,7314,7315,7316,7316,7316,7318,7317,7318,7319,7319,7319,7318,7319,7320,7319,7321,7322,7324,7323,7322,7324,7325,7325,7327,7327,7328,7328,7330,7330,7331,7331,7332,7332,7331,7330,7329,7329,7331,7331,7332,7333,7335,7334,7335,7337,7339,7339,7338,7338,7337,7336,7338,7337};
    interval = {{0, 100}, {1, 102}};

    const auto ans = s.intervalSum(v, interval);
    for (const auto& i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    // const auto node = SegmentTreeNode(1,2);
    // const auto leftNode = node.left.get();
    // if (!leftNode) {
    //     cout<<"ok"<<endl;
    // }
}
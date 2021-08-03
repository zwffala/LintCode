#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        // write your code here
        int n = A.size() + B.size();
        int mid1 = 0;
        int mid2 = 0;
        findKth((n - 1) / 2, A, B, mid1, mid2);
        if (n % 2 == 0) {
            return (mid1 + mid2) / 2.0;
        } else {
            return mid1;
        }
    }

private:
    void findKth(int k, const vector<int>& A, const vector<int>& B, int& mid1, int& mid2) {
        if (A.empty()) {
            mid1 = B[k];
            mid2 = getMid2(B, k + 1);
            return;
        }
        if (B.empty()) {
            mid1 = A[k];
            mid2 = getMid2(A, k + 1);
            return;
        }

        if (k == 0) {
            mid1 = min(A[0], B[0]);
            mid2 = A[0] <= B[0] ? min(getMid2(A, 1), getMid2(B, 0)) : min(getMid2(B, 1), getMid2(A, 0));
            return;
        }

        int indexA = 0;
        int indexB = 0;
        A[0] <= B[0] ? ++indexA : ++indexB;
        while (indexA + indexB <= k) {
            if (indexA >= A.size()) {
                mid1 = B[k - A.size()];
                mid2 = getMid2(B, k - A.size() + 1);
                return;
            }
            if (indexB >= B.size()) {
                mid1 = A[k - B.size()];
                mid2 = getMid2(A, k - B.size() + 1);
                return;
            }
            if (A[indexA] <= B[indexB]) {
                mid1 = A[indexA++];
                mid2 = indexA >= A.size() ? getMid2(B, indexB) : min(A[indexA], B[indexB]);
            } else {
                mid1 = B[indexB++];
                mid2 = indexB >= B.size() ? getMid2(A, indexA) : min(A[indexA], B[indexB]);
            }
        }
    }

    int getMid2(const vector<int>& v, int index) {
        return index >= v.size() ? INT_MAX : v[index];
    }
};

int main() {
    Solution s;
    vector<int> A{1,2,3,4,5,6};
    vector<int> B{2,3,4,5};
    cout<<s.findMedianSortedArrays(A,B)<<endl;

    A = {1,2,3};
    B = {4,5};
    cout<<s.findMedianSortedArrays(A,B)<<endl;

    A = {4,5};
    B = {1,2,3};
    cout<<s.findMedianSortedArrays(A,B)<<endl;

    A = {1,2,3};
    B = {};
    cout<<s.findMedianSortedArrays(A,B)<<endl;

    A = {3};
    B = {4};
    cout<<s.findMedianSortedArrays(A,B)<<endl;

}
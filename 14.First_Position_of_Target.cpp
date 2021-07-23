#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
   /**
    * @param nums: The integer array.
    * @param target: Target to find.
    * @return: The first position of target. Position starts from 0.
    */
   int binarySearch(vector<int> &nums, int target) {
       // write your code here
       if (nums.empty()) {
           return -1;
       }

       int targetIndex = INT_MAX;
       binarySearchHelper(nums, target, 0, nums.size() - 1, targetIndex);
       return targetIndex == INT_MAX ? -1 : targetIndex;
   }

private:
   void binarySearchHelper(const vector<int>& nums, int target, int start, int end, int& targetIndex) {
       if (start > end) {
           return;
       }
       if (start == end) {
           if (nums[start] == target) {
                targetIndex = min(targetIndex, start);
           }
           return;
       }

       int midIndex = (start + end) / 2;
       if (target == nums[midIndex]) {
           targetIndex = midIndex;
           return binarySearchHelper(nums, target, start, midIndex - 1, targetIndex);
       }
       if (target < nums[midIndex]) {
           return binarySearchHelper(nums, target, start, midIndex - 1, targetIndex);
       } else {
           return binarySearchHelper(nums, target, midIndex + 1, end, targetIndex);
       }
   }
};


// class Solution {
// public:
//     /**
//      * @param nums: The integer array.
//      * @param target: Target to find.
//      * @return: The first position of target. Position starts from 0.
//      */
//     int binarySearch(vector<int> &nums, int target) {
//         // write your code here
//         int firstTargetIndex = INT_MAX;
//         int start = 0;
//         int end = nums.size() - 1;
//         while (start <= end) {
//             int midIndex = (start + end) / 2;
//             if (target == nums[midIndex]) {
//                 firstTargetIndex = min(firstTargetIndex, midIndex);
//                 end = midIndex - 1;
//             }
//             if (target < nums[midIndex]) {
//                 end = midIndex - 1;
//             }
//             if (target > nums[midIndex]) {
//                 start = midIndex + 1;
//             }
//         }
//         return firstTargetIndex == INT_MAX ? -1 : firstTargetIndex;
//     }
// };

int main() {
    Solution s;
    vector<int> v{1,4,4,5,7,7,8,9,9,10};
    v = {1,1,2};
    cout<<s.binarySearch(v, 1)<<endl;
}
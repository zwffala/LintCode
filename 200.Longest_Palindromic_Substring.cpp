#include<string>
#include<iostream>
using namespace std;

// O(n^3)
// class Solution {
// public:
//     /**
//      * @param s: input string
//      * @return: a string as the longest palindromic substring
//      */
//     string longestPalindrome(string &s) {
//         // write your code here
//         if (s.empty() || s.size() == 1) {
//             return s;
//         }
//         string ans("");
//         for (int start = 0; start < s.size(); ++start) {
//             for (int end = s.size() -1; end > start; --end) {
//                 if (isPalindrome(s, start, end)) {
//                     string tmp(s, start, end-start+1);
//                     tmp.size() > ans.size() ? ans=tmp : ans;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }

//     bool isPalindrome(const string& s, int startPos, int endPos) const {
//         while (startPos < endPos) {
//             if (s[startPos++] != s[endPos--]) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// O(n^2)
class Solution {
public:
    /**
     * @param s: input string
     * @return: a string as the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        if (s.empty() || s.size() == 1) {
            return s;
        }
        string ans("");
        for (int i = 1; i < s.size(); ++i) {
            // odd
            string tmp = getPalindrome(s, i - 1, i + 1);
            tmp.size() > ans.size() ? ans = tmp : ans;

            // even
            if (s[i-1] == s[i]) {
                string tmp = getPalindrome(s, i - 1, i);
                tmp.size() > ans.size() ? ans = tmp : ans;
            }
        }
        return ans;
    }

    string getPalindrome(const string& s, int left, int right) {
        while (left >= 0 && right < s.size()) {
            if (s[left] == s[right]) {
                --left;
                ++right;
            } else {
                break;
            }
        }
        ++left;
        --right;
        return s.substr(left, right-left+1);
    }
};


int main() {
    Solution s;
    string ss("abcdzdcab");
    // ss = "caabaad";
    ss = "bb";
    cout<<s.longestPalindrome(ss)<<endl;
}
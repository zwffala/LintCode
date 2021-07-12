#include<string>
#include<iostream>
using namespace std;

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
        for (int start = 0; start < s.size(); ++start) {
            for (int end = s.size() -1; end > start; --end) {
                if (isPalindrome(s, start, end)) {
                    string tmp(s, start, end-start+1);
                    tmp.size() > ans.size() ? ans=tmp : ans;
                    break;
                }
            }
        }
        return ans;
    }

    bool isPalindrome(const string& s, int startPos, int endPos) const {
        while (startPos < endPos) {
            if (s[startPos++] != s[endPos--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    string ss("abcdzdcab");
    ss = "caabaad";
    cout<<s.longestPalindrome(ss)<<endl;
}
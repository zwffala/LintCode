#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        // Write your code here
		if (source == target || target.empty()) {
			return 0;
		}
		for (int i = 0; i < source.length(); ++i) {
			if (source[i] == target[0]) {
				int j = 1;
				for (; j < target.length(); ++j) {
					if (source[i+j] != target[j]) {
						break;
					}
				}
				if (j == target.length()) {
					return i;
				} else {
					j = 0;
				}

			}
		}
		return -1;
	}
};

int main() {
	Solution sl;
    // string s("source");
    // string t("rced");
	// cout<<sl.strStr(s,t)<<endl;
	// s = "abcdbce";
	// t = "bce";
	// cout<<sl.strStr(s,t)<<endl;
	// s = "abcdabcdefg";
	// t = "bcd";
	// cout<<sl.strStr(s,t)<<endl;
	string s("mississippi");
	string t("issip");
	cout<<sl.strStr(s,t)<<endl;
}
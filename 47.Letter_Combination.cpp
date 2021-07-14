#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here
        if (digits.empty() || digits == "") {
            return {};
        }
        const unordered_map<char, string> letterToStrings{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> selectFrom;
        for (const auto s : digits) {
            selectFrom.emplace_back(letterToStrings.at(s));
        }

        vector<string> ans{};
        getCombinations(selectFrom, digits.size(), 0, ans, "");
        return ans;
    }

    void getCombinations(const vector<string>& selectUnit, const int totalSelectNumber, int currentNumOfSelect, vector<string>& ans, string tmp) {
        if (currentNumOfSelect == totalSelectNumber) {
            ans.emplace_back(tmp);
            return;
        }
        // select one from slectUnit
        for (int i = 0; i < selectUnit[currentNumOfSelect].size(); ++i) {
            getCombinations(selectUnit, totalSelectNumber, currentNumOfSelect + 1, ans, tmp+selectUnit[currentNumOfSelect][i]);
        }
    }
};

int main() {
    Solution s;
    string ss("23");
    const auto ans = s.letterCombinations(ss);
    for (const auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
}
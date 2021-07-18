#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<deque>
#include<string>
#include<iostream>
using namespace std;

// class Solution {
// public:
//     /*
//      * @param s: A string
//      * @param wordDict: A set of words.
//      * @return: All possible sentences.
//      */
//     vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
//         // write your code here
//         if (s.empty() || wordDict.empty()) {
//             return {};
//         }
//         vector<string> ans{};
//         deque<string> foundWords{};
//         wordBreak(s, wordDict, ans, 0, foundWords);
//         return ans;
//     }

// private:
//     void wordBreak(const string& s, const unordered_set<string>& wordDict, vector<string>& ans, int startPoint, deque<string> foundWords) {
//         if (startPoint >= s.size()) {
//             if (!foundWords.empty()) {
//                 string tmp(foundWords[0]);
//                 for (int i = 1; i < foundWords.size(); ++i) {
//                     tmp += " ";
//                     tmp += foundWords[i];
//                 }
//                 ans.emplace_back(tmp);
//             }
//             return;
//         }

//         const vector<string> foundWordsSet = findWords(s, wordDict, startPoint);
//         if (foundWordsSet.empty()) {
//             return;
//         }

//         for (auto word : foundWordsSet) {
//             foundWords.emplace_back(word);
//             wordBreak(s, wordDict, ans, startPoint + word.size(), foundWords);
//             // clean up
//             foundWords.pop_back();
//         }
//     }
    
//     vector<string> findWords(const string& s, const unordered_set<string>& wordDict, int startPoint) {
//         vector<string> ans{};
//         for (const auto word : wordDict) {
//             if (word == "") {
//                 continue;
//             }
//             const auto pos = s.find(word, startPoint);
//             if (pos == startPoint) {
//                 ans.emplace_back(word);
//             }
//         }
//         return ans;
//     }
    
// };


class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        if (s.empty() || wordDict.empty()) {
            return {};
        }
        return wordBreakHelper(s, wordDict);
    }

private:
    // vector<string> wordBreakHelper(string s, const unordered_set<string>& wordDic) {
    //     if (s.empty()) {
    //         return {};
    //     }
    //     vector<string> ans;
    //     const auto& foundWords = findFirstWords(s, wordDic);
    //     for (const auto word : foundWords) {
    //         vector<string> subStrings = wordBreakHelper(s.substr(word.size()), wordDic);

    //         for (const auto& subString : subStrings) {
    //             string optionalSpace = subString.empty() ? "" : " ";
    //             ans.emplace_back(word + optionalSpace + subString);
    //         }
    //     }
    //     return ans;
    // }

    vector<string> wordBreakHelper(string s, const unordered_set<string>& wordDict) {
        vector<string> ans;
        if (s.empty()) {
            ans.emplace_back("");
            return ans;
        }

        const auto& foundWords = findFirstWords(s, wordDict);
        for (const auto& word : foundWords) {
            vector<string> subStrings = wordBreakHelper(s.substr(word.size()), wordDict);

            for (const auto& subString : subStrings) {
                string optionalSpace = subString.empty() ? "" : " ";
                ans.emplace_back(word + optionalSpace + subString);
            }
        }
        return ans;
    }

    vector<string> findFirstWords(const string& s, const unordered_set<string>& wordDict) {
        vector<string> ans;
        for (const auto word : wordDict) {
            if (word == "") {
                continue;
            }
            const auto pos = s.find(word);
            if (pos == 0) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    unordered_set<string> dict{"cat","cats","and","sand","dog"};
    string ss("catsanddog");

    ss = "pineapplepenapple";
    dict = { "apple","pen","applepen","pine","pineapple" };

    // ss = "aaaaaaa";
    // dict = {"aaaa","aa"};

    // ss = "catsandog";
    // dict = {"cats","dog","sand","and","cat"};

    // ss = "a";
    // dict = {""};
    const auto ans{s.wordBreak(ss, dict)};
    for (const auto& i : ans) {
        cout<<i<<endl;
    }

    vector<string> ms{"a", "b"};
    for (auto&& i : ms) {
        i += "1";
    }
    for (auto& i : ms) {
        i += "2";
    }
    for (auto i : ms) {
        i += "3";
    }
    for (const auto& i : ms) {
        cout<<i<<" ";
    }

}
#include<unordered_set>
#include<vector>
#include<deque>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        // write your code here
        if (s.empty() || s == "" || wordDict.empty()) {
            return {};
        }
        vector<string> ans{};
        deque<string> foundWords{};
        wordBreak(s, wordDict, ans, 0, foundWords);
        return ans;
    }

private:
    void wordBreak(const string& s, const unordered_set<string>& wordDict, vector<string>& ans, int startPoint, deque<string> foundWords) {
        if (startPoint >= s.size()) {
            if (!foundWords.empty()) {
                string tmp(foundWords[0]);
                for (int i = 1; i < foundWords.size(); ++i) {
                    tmp += " ";
                    tmp += foundWords[i];
                }
                ans.emplace_back(tmp);
            }
            return;
        }
        const unordered_set<string> foundWordsSet = findWords(s, wordDict, startPoint);
        if (foundWordsSet.empty()) {
            return;
        }
        for (auto word : foundWordsSet) {
            foundWords.emplace_back(word);
            wordBreak(s, wordDict, ans, startPoint + word.size(), foundWords);
            // clean up
            foundWords.pop_back();
        }
    }
    
    unordered_set<string> findWords(const string& s, const unordered_set<string>& wordDict, int startPoint) {
        unordered_set<string> ans{};
        for (const auto word : wordDict) {
            if (word == "") {
                continue;
            }
            const auto pos = s.find(word, startPoint);
            if (pos == startPoint) {
                ans.emplace(word);
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

    ss = "catsandog";
    dict = {"cats","dog","sand","and","cat"};

    ss = "a";
    dict = {""};
    const auto ans{s.wordBreak(ss, dict)};
    for (const auto& i : ans) {
        cout<<i<<endl;
    }
}
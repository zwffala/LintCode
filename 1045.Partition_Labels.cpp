#include<vector>
#include<string>
#include<unordered_map>
#include<deque>
#include<iostream>
using namespace std;

// class Solution {
// public:
//     /**
//      * @param S: a string
//      * @return: a list of integers representing the size of these parts
//      */
//     vector<int> partitionLabels(string &s) {
//         // Write your code here
//         if (s.empty()) {
//             return {};
//         }
//         if (s.size() == 1) {
//             return {1};
//         }

//         vector<int> ans;
//         unordered_map<char, int> charsInPartition;
//         deque<string> partitionChars;
//         deque<int> partitionStartPos;
//         for (int i = 0; i < s.size(); ++i) {
//             if (charsInPartition.find(s[i]) != charsInPartition.end()) {
//                 // find the char
//                 int sector = charsInPartition[s[i]];
//                 for (int i = partitionStartPos.size() - 1; i > sector; --i) {
//                     partitionStartPos.pop_back();
                    
//                     //add chars to the partition
//                     partitionChars[sector] += partitionChars[i];
//                     partitionChars.pop_back();
//                 }
//                 // update the map
//                 for (const auto ch : partitionChars.back()) {
//                     charsInPartition[ch] = sector;
//                 }

//             } else {
//                 partitionStartPos.emplace_back(i);
//                 charsInPartition[s[i]] = partitionStartPos.size() - 1;
//                 partitionChars.emplace_back(string(1, s[i]));
//             }
//         }

//         for (int i = 1; i < partitionStartPos.size(); ++i) {
//             ans.emplace_back(partitionStartPos[i]-partitionStartPos[i-1]);
//         }
//         ans.emplace_back(s.size() - partitionStartPos.back());
//         return ans;
//     }
// };

class Solution {
public:
    /**
     * @param S: a string
     * @return: a list of integers representing the size of these parts
     */
    vector<int> partitionLabels(string &s) {
        // Write your code here
        if (s.empty()) {
            return {};
        }
        if (s.size() == 1) {
            return {1};
        }

        unordered_map<char, int> charsRightMostPos;
        for (int i = 0; i < s.size(); ++i) {
            charsRightMostPos[s[i]] = i;
        }

        vector<int> ans;
        for (int i = 0; i < s.size();) {
            int startPos = i;
            int rightMostPos = charsRightMostPos[s[i]];
            for (int j = i + 1; j < rightMostPos; ++j) {
                rightMostPos = max(rightMostPos, charsRightMostPos[s[j]]);
            }
            int size = rightMostPos - startPos + 1;
            ans.emplace_back(size);
            i += size;
        }
        return ans;
    }
};


int main() {
    Solution s;
    string ss("abcab");
    ss = "ababcbacadefegdehijhklij";
    const auto v = s.partitionLabels(ss);
    for (const auto i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
}
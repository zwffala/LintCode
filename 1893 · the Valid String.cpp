#include<unordered_map>
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    /**
     * @param s: a string
     * @return: if valid return "YES" else return "NO"
     */
    string isValid(string &s) {
        // write your code here
        // 1. only remove, not adding
        // iterate the string and put each string in hash with appear times in value
        // all values shall be same or only one is different and it shall be bigger
        // ok: (2,1); (1,1,2)
        // !ok : (2,2,1) ; (2,2,1,1) ; 
        
        unordered_map<char, int> mAlphabetHashTable;
        for (const auto& ch : s) {
            mAlphabetHashTable[ch] += 1;
        }

        // int differenceCount = 0;
        // if no diffrenceCount, how to deal with (1,2,3) "abbccc"
        pair<int, int> firstValueCount( mAlphabetHashTable.begin()->second, 1);
        pair<int, int> anotherValueCount;
        for (auto it = ++mAlphabetHashTable.begin(); it != mAlphabetHashTable.end(); ++it) {
            if (it->second != firstValueCount.first) {
                if (anotherValueCount.first == 0) {
                    anotherValueCount = make_pair(it->second, 1);
                } else {
                    if (it->second != anotherValueCount.first) {
                        return "NO";
                    }
                    ++anotherValueCount.second;
                }
            } else {
                ++firstValueCount.second;
            }
        }
        // list all true
        // all has same value
        if (anotherValueCount.first == 0) {
            return "YES";
        }
        // alpha length difference is 1 ||  (1,1) appear
        // the one appear more, if is big: small one shall only appear once; if is small, the big one shall only appear once
        // if both appear the same times, they shall appear only once

        if (abs(firstValueCount.first - anotherValueCount.first) != 1) {
            const auto& onlyOneCharPair = make_pair(1,1);
            return firstValueCount == onlyOneCharPair || anotherValueCount == onlyOneCharPair ? "YES" : "NO";
        }
        if (firstValueCount.second > anotherValueCount.second) {
            return anotherValueCount.second == 1 ? "YES" : "NO";
        } else if (firstValueCount.second < anotherValueCount.second) {
            return firstValueCount.second == 1 ? "YES" : "NO";
        } else {
            return firstValueCount.second == 1 ? "YES" : "NO";
        }
        return "NO";
    }
};

int main() {
    Solution s;
    // string str("aabbc");
    // cout<<s.isValid(str)<<endl;
    // str = "abc";
    // cout<<s.isValid(str)<<endl;
    // str = "aab";
    // cout<<s.isValid(str)<<endl;
    // str = "abcc";
    // cout<<s.isValid(str)<<endl;
    // str = "aabbcd";
    // cout<<s.isValid(str)<<endl;
    // str = "abbccc";
    // cout<<s.isValid(str)<<endl;
    // string strA = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // string strB = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    // string strC = "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";
    // string strD = "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy";
    // string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyz";
    string str("aaaaz");
    cout<<s.isValid(str)<<endl;
}


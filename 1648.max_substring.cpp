#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param s: the matrix
     * @return: the last substring of s in lexicographical order
     */
    string maxSubstring(string &s) {
        // Write your code here.
        
        vector<int> largestCharIndices;
        char largestChar('a');
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] > largestChar) {
                largestChar = s[i];
                largestCharIndices.clear();
                largestCharIndices.push_back(i);
            } else if (s[i] == largestChar) {
                largestCharIndices.push_back(i);
            }
        }
        
        getLargestSubstringIndex(largestCharIndices, s, 1);

        return s.substr(largestCharIndices[0]);
        // string targetString(s.substr(index));
        // vector<string> subStrings = getSubStrings(targetString);

        // sort(subStrings.begin(), subStrings.end());
        // return subStrings.back();
    }

private:
    void getLargestSubstringIndex(vector<int>& largestCharIndices, const string& s, int offset) {
        if (largestCharIndices.size() == 1) {
            return;
        }

        char largestChar = s[largestCharIndices[0] + offset];
        for (int i = 1; i < largestCharIndices.size(); ++i) {
            if (s[largestCharIndices[i] + offset] > largestChar) {
                largestChar = s[largestCharIndices[i] + offset];
            }
        }
        for (auto it = largestCharIndices.begin(); it != largestCharIndices.end(); ) {
            if (*it + offset >= s.size()) {
                largestCharIndices.erase(it);
                continue;
            }
            if (s[*it + offset] < largestChar) {
                largestCharIndices.erase(it);
                continue;
            }
            ++it;
        }

        getLargestSubstringIndex(largestCharIndices, s, offset + 1);
    }

// private:
//     vector<string> getSubStrings(const string& s) {
//         vector<string> subStrings;
//         vector<string> prevSubStrings;
//         for (int i = 0; i < s.size(); ++i) {
//             for (int j = 0; j < prevSubStrings.size(); ++j) {
//                 prevSubStrings[j] += s[i];
//             }
//             prevSubStrings.emplace_back(string(1, s[i]));
//             subStrings.insert(subStrings.end(), prevSubStrings.begin(), prevSubStrings.end());
//         }
//         return subStrings;
//     }

    // void getSubStrings(const string& s, int index, vector<string> prevSubStrings, vector<string>& subStrings) {
    //     if (index == -1) {
    //         return;
    //     }

    //     for (int i = 0; i < prevSubStrings.size(); ++i) {
    //         string subString(1, s[index]);
    //         prevSubStrings[i] = s[index] + prevSubStrings[i];
    //     }
    //     prevSubStrings.emplace_back(string(1, s[index]));
    //     subStrings.insert(subStrings.end(), prevSubStrings.begin(), prevSubStrings.end());
    //     getSubStrings(s, index - 1, prevSubStrings, subStrings);
    // }
};

int main() {
    Solution s;
    string ss("abab");
    // ss = "baca";
    // ss = "hxmquuddnyukcdsmslgaafemtabehoiupixhqhsmzcceipeckontpogzmiukufkeqeldyhslyfelkcpxqrsoihyfzirucommupazfxtlnykynkpczyvjajkztuxsfobeakfdvrpgjtwsaaxfqhkiucakpwidbldxzbfliqtdyetgrqtdfnoyutimsyipwccnhgwaobeiqjajjzrnymtwpyuzecqjqlkttmuehezcqudaduasvnxcxgbczymuizoygxiklndmpwedezgdsfjqtdqrohuphfhegjsdworfbzvjgggyzcpreeereppxlvjrcqkyafoclcpkxeiooaspmtjbafbywyyxnudcfvvzyatmqgeqtemjmzrwiicdwqymfyhgydrbznjyqczjexdmugpniezwmndjricbmhaykbndcvreylyrrzfdafwasaopwjljsoyajavxepgsybbxqunpmqelyrmiizcnoqmyduuhmetuhfghhrsmwczkhcxnbdcehlyndsaffyenxvmghoscpvvekdxeirdlvpgwirvgyzregptbfjokmkzxjkpdcnbbmivgmtgcyhbrrjforzseapxeyizsimjpondfybxiufcppdzainioxyyxybbwbsngagebnphvspjbbkudvflatvwfdiyzvofresnovlyzicokdiarcmtsrknufpegkoqdisrrcvuyzztvqadrfkcbwzktsfkltrbufowyrmgryqldpbtsvjjpvarpteslhhyzuskpbweuvjyhmzwgptplvjspvugnysjplchmyyjgzehemkfqyeoiyvsisrpixwylfubwpwrmtxqgpujcfquaeujeyclplrpolrxdjfsxtxvcthymckpnaijctnorikdefqoinrdajffyjcijzijgldfygnddznbaxhkxbcusinoybficrhnipffvzhvlunruqdjrzuvgiuapdcoqfeajxoojmnbeoozjdqix";
    cout<<s.maxSubstring(ss)<<endl;
}
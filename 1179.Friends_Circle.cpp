#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<iostream>
using namespace std;

// class Solution {
// public:
//     /**
//      * @param M: a matrix
//      * @return: the total number of friend circles among all the students
//      */
//     int findCircleNum(vector<vector<int>> &M) {
//         // Write your code here
//         unordered_map<int, unordered_set<int>> friendsMap;
//         for (int i = 0; i < M.size(); ++i) {
//             unordered_set<int> friendsWithI;
//             for (int j = 0; j < M.size(); ++j) {
//                 if (M[i][j] == 1) {
//                     friendsWithI.emplace(j);
//                 }
//             }
//             friendsMap[i] = friendsWithI;
//         }

//         vector<vector<int>> friendsCircles;
//         // int friendCircles = 0;
//         unordered_set<int> isVisited;
//         deque<int> people;
//         for (int i = 0; i < friendsMap.size(); ++i) {
//             putPersonInQueue(i, people, isVisited);
//             putFriendsInQueue(i, people, isVisited, friendsMap);

//             vector<int> friendCircle;
//             while (!people.empty()) {    
//                 const auto& oneFriend = people.front();
//                 people.pop_front();
//                 friendCircle.emplace_back(oneFriend);
//                 putFriendsInQueue(oneFriend, people, isVisited, friendsMap);
                
//             }
//             if (!friendCircle.empty()) {
//                 friendsCircles.emplace_back(friendCircle);
//             }
//         }

//         return friendsCircles.size();
//     }

// private:
//     void putPersonInQueue(int person,
//                           deque<int>& deq,
//                           unordered_set<int>& visited) {
//         if (!visited.count(person)) {
//             deq.emplace_back(person);
//             visited.emplace(person);
//         }
//     }

//     void putFriendsInQueue(int person, deque<int>& deq, unordered_set<int>& visited,
//         const unordered_map<int,unordered_set<int>>& friendsMap) {
//         // const auto& friends = friendsMap[person];
//         const auto& friends = friendsMap.at(person);
//         for (const auto friendIndex : friends) {
//             putPersonInQueue(friendIndex, deq, visited);
//         }
//     }
// };

class Solution {
public:
    /**
     * @param M: a matrix
     * @return: the total number of friend circles among all the students
     */
    int findCircleNum(vector<vector<int>> &M) {
        // Write your code here
        deque<int> friends;
        unordered_set<int> visited;
        int friendsCircleNum = 0;
        for (int i = 0; i < M.size(); ++i) {
            putInFriends(i, visited, friends, M);
            bool hasFriends = false;    
            while (!friends.empty()) {
                hasFriends = true;
                int person = friends.front();
                friends.pop_front();
                putInFriends(person, visited, friends, M);
            }
            if (hasFriends) {
                ++friendsCircleNum;
                hasFriends = false;
            }
        }
        return friendsCircleNum;
    }

private:
    void putInFriends(int person, unordered_set<int>& visited, deque<int>& friends,
        const vector<vector<int>> &M) {
        if (!visited.count(person)) {
            friends.emplace_back(person);
            visited.emplace(person);
        }
        for (int j = 0; j < M[person].size(); ++j) {
            if (M[person][j] == 1) {
                if (!visited.count(j)) {
                    friends.emplace_back(j);
                    visited.emplace(j);
                }
            }
        }
    }
};

int main () {
    Solution s;
    vector<vector<int>> M{{1,1,0}, {1,1,1}, {0,1,1}};
    M = {{1,0,0},{0,1,0},{0,0,1}};
    cout<<s.findCircleNum(M)<<endl;
}
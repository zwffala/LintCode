
// Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */

	class Node {
    public:
		int time;
		bool isStart;
        Node(int time, bool isStart) : time(time), isStart(isStart) {}
        bool operator<(const Node& r) const {
            if (time == r.time) {
                return !isStart;
            } else {
                return time < r.time;
            }
        }
        bool operator>(const Node& r) const {
            if (time == r.time) {
                return isStart;
            } else {
                return time > r.time;
            }
        }
	};

    // class Compare{
    // public:
    //     bool operator()(const Node& l, const Node& r) {
    //         if (l.time == r.time){
    //             return l.isStart;
    //         } else {
    //             return l.time > r.time;
    //         }
    //     }
    // };

    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        // priority_queue<Node, vector<Node>, Compare> nodes;
        priority_queue<Node, vector<Node>, greater<Node>> nodes;
		for (const auto& airplane : airplanes) {
            nodes.push(Node(airplane.start, true));
            nodes.push(Node(airplane.end, false));
        }
        
        int count = 0;
        int ans = 0;
        while (!nodes.empty()) {
            if (nodes.top().isStart) {
                count++;
                ans = max(ans, count);
            } else {
                count--;
            }
            nodes.pop();
        }
        return ans;
    }
};

int main () {
    Solution s;
    vector<Interval> v{{1,2},{2,3}, {3,4}};
    // v = {{1,10},{2,3},{5,8},{4,7}};
    cout<<s.countOfAirplanes(v)<<endl;
}
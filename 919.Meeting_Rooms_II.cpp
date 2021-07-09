
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
#include<iostream>
using namespace std;
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
	class Meeting{
	public:
		int time;
		bool isStart;
		Meeting(int time, bool isStart) : time(time), isStart(isStart) {}
		bool operator< (const Meeting& r) const {
			if (time == r.time) {
				return !isStart;
			} else {
				return time < r.time;
			}
		}
	};
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
		vector<Meeting> meetings;
		for (const auto& i : intervals) {
			meetings.emplace_back(i.start, true);
			meetings.emplace_back(i.end, false);
		}
		sort(meetings.begin(), meetings.end());
		int count = 0;
		int res = 0;
		for (const auto& i : meetings) {
			if (i.isStart) {
				++count;
				res = max(count, res);
			} else {
				--count;
			}
		}
		return res;
    }
};

int main() {
	Solution s;
	vector<Interval> v{{0,30},{5,10},{15,20}};
	std::cout<<s.minMeetingRooms(v)<<endl;
}
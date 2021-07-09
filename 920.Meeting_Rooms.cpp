
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
     * @return: if a person could attend all meetings
     */
    class Meeting {
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
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        vector<Meeting> meetings;
        for (const auto interval : intervals) {
            meetings.emplace_back(interval.start, true);
            meetings.emplace_back(interval.end, false);
        }
        sort(meetings.begin(), meetings.end());
        int count = 0; 
        for (const auto meeting : meetings) {
            if (meeting.isStart) {
                count++;
                if (count > 1) {
                    return false;
                }
            } else {
                count--;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<Interval> v {{0,30},{5,10},{15,20}};//{{5,8},{8,15}};
    cout<<endl<<s.canAttendMeetings(v)<<endl;
}
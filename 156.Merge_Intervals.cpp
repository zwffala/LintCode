
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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
	static bool cmp (const Interval& l, const Interval& r) {
		return l.start < r.start;
	}

    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
		if (intervals.empty()) {
			return {};
		}
		// sort(intervals.begin(), intervals.end(), [](const Interval& l, const Interval& r){return l.start < r.start;});
		sort(intervals.begin(), intervals.end(), cmp);
		for(const auto& i : intervals) {
			cout<<"("<<i.start<<", "<<i.end<<") ";
		}
		cout<<endl;
		vector<Interval> res;
		int start = intervals[0].start;
		int end = intervals[0].end;
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i].start<=end) {
				end = max(end, intervals[i].end);
			} else {
				res.emplace_back(start, end);
				start = intervals[i].start;
				end = intervals[i].end;
			}
		}
		res.emplace_back(start, end);
		return res;
	}
};

int main() {
	Solution s;
	vector<Interval> v{{1,2},{2,3},{5,7},{6,8},{10,30},{14,15}, {31,33},{31,32}};
	auto res = s.merge(v);
	for (const auto& i : res) {
		cout<<"("<<i.start<<", "<<i.end<<") ";
	}
	cout<<endl;
	v = {};
	res = s.merge(v);
	cout<<res.size()<<endl;

	v = {{1,4},{0,2},{3,5}};
	res = s.merge(v);
	for (const auto& i : res) {
		cout<<"("<<i.start<<", "<<i.end<<") ";
	}
	cout<<endl;
}
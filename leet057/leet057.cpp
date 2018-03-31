/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> v;
        if (intervals.size() == 0) {
            v.push_back(newInterval);
            return v;
        }
        int i1 = -1, i2 = -1;
        for(int i = 0; i < intervals.size(); i ++) {
            int s = max(intervals[i].start, newInterval.start);
            int e = min(intervals[i].end, newInterval.end);
            if (s <= e) {
                if (i1 < 0) i1 = i;
                i2 = i;
            }
        }
        
        int first_s = min(intervals[i1].start, newInterval.start);
        int last_e = max(intervals[i2].end, newInterval.end);
        for(int i = 0; i < i1; i ++) {
            v.push_back(intervals[i]);
        }
        v.push_back(Interval(first_s, last_e));
        for(int i = i2 + 1; i < (int)intervals.size(); i ++) {
            v.push_back(intervals[i]);
        }
        sort(v.begin(), v.end(), [](const auto & a, const auto & b) {
            if (a.start == b.start) return a.end < b.end;
            return a.start < b.start;
        });
        return v;
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        
        int i = 0;
        for (; i < intervals.size(); i++) {
            if (newInterval.end < intervals[i].start) {
                break;
            } else if (newInterval.start > intervals[i].end) {
                res.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        
        res.push_back(newInterval);
        
        for (; i < intervals.size(); i++) {
            res.push_back(intervals[i]);
        }
        return res;
    }
};
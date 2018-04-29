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
        vector<Interval> result;
        int i = 0;
        for(; i < intervals.size() && intervals[i].start <= newInterval.start; ++i) {
            result.push_back(intervals[i]);
        }
        if (result.empty() || newInterval.start > result.back().end) {
            result.push_back(newInterval);
        } else if (newInterval.end > result.back().end) {
            result.back().end = newInterval.end;
        }
        for(; i < intervals.size(); ++i) {
            if (intervals[i].start > result.back().end) {
                result.push_back(intervals[i]);
            } else if (intervals[i].end > result.back().end) {
                result.back().end = intervals[i].end;
            }
        }
        return result;
    }
};
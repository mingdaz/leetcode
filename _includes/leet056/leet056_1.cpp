/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool sortbystart(const Interval &a,const Interval &b){
    return a.start<b.start;
}



class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),sortbystart);
        vector<Interval> res;
        for(auto intv:intervals){
            if(res.empty()||res.back().end<intv.start)
                res.push_back(intv);
            else if(intv.end>res.back().end){
                res.back().end = intv.end;
            }
        }
        return res;
    }
};

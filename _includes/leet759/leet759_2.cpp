/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#define II vector<Interval>::iterator
#define PII pair<II,II>

struct comparePII
{
  bool operator()(const PII& lhs, const PII& rhs) const
  {
    return lhs.first->start > rhs.first->start;
  }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        priority_queue<PII,vector<PII>,comparePII> pq;
        for(int i=0;i<schedule.size();i++){
            if(schedule[i].size())
                pq.push(PII(schedule[i].begin(),schedule[i].end()));
        }
        vector<Interval> res;
        int endtime = -1;
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            if(endtime == -1){
                endtime = p.first->end;
            }
            else{
                if(p.first->start>endtime)
                    res.push_back(Interval(endtime,p.first->start));
                if(p.first->end>endtime)
                    endtime = p.first->end;
            }
            p.first++;
            if(p.first!=p.second)
                pq.push(p);
        }
        return res;
    }
};
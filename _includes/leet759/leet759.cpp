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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> m = divide(schedule,0,schedule.size());
        vector<Interval> res;
        int start = m[0].end;
        for(int i=1;i<m.size();i++){
            res.push_back(Interval(start,m[i].start));
            start = m[i].end;
        }
        return res;
    }
private:
    vector<Interval> divide(vector<vector<Interval>>& schedule,int l, int r){
        if(r-l==1){
            return schedule[l];
        }
        else if(r-l==2){
            return merge(schedule[l],schedule[l+1]);
        }
        else{
            int mid = l+ (r-l)/2;
            return merge(divide(schedule,l,mid),divide(schedule,mid,r));
        }
    }   
    vector<Interval> merge(vector<Interval> a, vector<Interval> b){
        vector<Interval> res;
        int i=0,j=0;
        while(i<a.size()&&j<b.size()){
            if(a[i].start<b[j].start){
                if(res.empty()||a[i].start> res.back().end)
                    res.push_back(a[i]);
                else if(a[i].end> res.back().end)
                    res.back().end = a[i].end;
                i++;
            }
            else{
                if(res.empty()||b[j].start> res.back().end)
                    res.push_back(b[j]);
                else if(b[j].end> res.back().end)
                    res.back().end = b[j].end;
                j++;
            }
        }
        while(i<a.size()){
                if(res.empty()||a[i].start> res.back().end)
                    res.push_back(a[i]);
                else if(a[i].end> res.back().end)
                    res.back().end = a[i].end;
                i++;
            
        }
        while(j<b.size()){
                if(res.empty()||b[j].start> res.back().end)
                    res.push_back(b[j]);
                else if(b[j].end> res.back().end)
                    res.back().end = b[j].end;
                j++;
            
        }
        return res;
    }
    
};
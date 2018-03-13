class MyCalendarThree {
private:
    struct Range {
        int end;
        int cnt;
        Range(int e, int c) : end(e), cnt(c) {}
    };
    
	map<int, Range> m;
	int maxK;
	const int minPos = 0;
	const int maxPos = 1000000001;

public:
	MyCalendarThree() {
		m.emplace(minPos, Range(maxPos, 0));
		maxK = 0;
	}

	int book(int start, int end) {
		auto lb1 = prev(m.upper_bound(start));
		auto p1 = lb1->second;
		if (lb1->first < start) {
			lb1->second.end = start;
		    if(start < p1.end)
			      lb1 = m.emplace(start, move(p1)).first;
            else 
                  ++lb1;
		}

		auto lb2 = prev(m.upper_bound(end));
		auto p2 = lb2->second;
		if (lb2->first < end) {
			lb2->second.end = end;
		    if(p2.end > end)
			      lb2 = m.emplace(end, move(p2)).first;
            else
                  ++lb2;
		}
        
        for_each(lb1, lb2, [this] (pair<const int, Range>& p) {
            maxK = max(maxK, ++p.second.cnt);
        });
        
		return maxK;
	}
}; 

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
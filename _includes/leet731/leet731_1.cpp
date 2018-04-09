class MyCalendarTwo {
public:
    MyCalendarTwo() {
        map1.insert({-20,-10});
    }
    
    bool book(int start, int end) {

        if(!map2.empty()) {
            auto it2 = prev(map2.lower_bound(end), 1);
            if(it2 != map2.end() && it2->first < end && it2->second > start) { return false; }
        }        
        auto it1 = prev(map1.lower_bound(end), 1);
        if(it1 == map1.end()) { map1.insert({start, end}); return true; }
        while(it1->first < end && it1->second > start) {            
            if(min(end, it1->second) > max(start, it1->first)) map2.insert({max(start, it1->first), min(end, it1->second)});
            if(it1->second != end) map1.insert({min(end, it1->second), max(end, it1->second)});
            end = it1->first;
            it1--;
        }       
        map1.insert({start, end}); 
        return true;      
    }
private:
    map<int,int> map1, map2;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */

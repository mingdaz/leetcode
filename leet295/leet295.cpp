class MedianFinder {
public:
    struct mincompare{
        bool operator()(const int& a,const int& b){
            return a>b;
        }
    };
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(min_heap.size()<max_heap.size()){
            if(num>=max_heap.top()){
                min_heap.push(num);
            }
            else{
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
        }
        else if(min_heap.size()>max_heap.size()){
            if(num<=min_heap.top()){
                max_heap.push(num);
            }
            else{
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
        }
        else if(min_heap.empty()||num>=min_heap.top()){
            min_heap.push(num);   
        }
        else{
            max_heap.push(num);
        }
    }
    
    double findMedian() {
        if(min_heap.size()<max_heap.size()){
            return max_heap.top();
        }
        else if(min_heap.size()>max_heap.size()){
            return min_heap.top();
        }
        else{
            return (min_heap.top()+max_heap.top())/2.0;
        }
    }
private:
    priority_queue<int,vector<int>,mincompare> min_heap;
    priority_queue<int> max_heap;
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
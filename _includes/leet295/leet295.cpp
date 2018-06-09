class MedianFinder {
public:
    // struct mycompare{
    //     bool operator()(const int& a, const int& b){
    //         return a>b;
    //     }    
    // };
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minheap.empty())
            minheap.push(num);
        else if(minheap.size()==maxheap.size()){
            if(num<maxheap.top()){
                maxheap.push(num);
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            else
                minheap.push(num);
        }
        else if(minheap.size()>maxheap.size()){
            if(num<=minheap.top()){
                maxheap.push(num);
            }
            else{
                minheap.push(num);
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size())
            return (minheap.top() + maxheap.top())/2.0;
        else
            return minheap.top();
    }
    
private:
    priority_queue<int,vector<int>,greater<int>> minheap;
    priority_queue<int> maxheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
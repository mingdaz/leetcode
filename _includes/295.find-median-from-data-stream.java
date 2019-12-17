/*
 * @lc app=leetcode id=295 lang=java
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (40.02%)
 * Likes:    1684
 * Dislikes: 33
 * Total Accepted:    146.8K
 * Total Submissions: 366.1K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 * 
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
 * 
 * 
 */

// @lc code=start
class MedianFinder {

    PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a,b)->(b-a));
    
    /** initialize your data structure here. */
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        if(maxHeap.size()==0 || num < maxHeap.peek()){
            maxHeap.offer(num);        
        } else {
            minHeap.offer(num);
        }
        while(minHeap.size()>maxHeap.size() ){
            maxHeap.offer(minHeap.poll());
        }
        if(maxHeap.size()-minHeap.size()>1){
            minHeap.offer(maxHeap.poll());
        }
    }
    
    public double findMedian() {
        if(maxHeap.size()!=minHeap.size()){
            return maxHeap.peek();
        }
        return (maxHeap.peek() + minHeap.peek())/2.0;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
// @lc code=end
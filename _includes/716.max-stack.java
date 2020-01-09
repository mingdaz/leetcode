/*
 * @lc app=leetcode id=716 lang=java
 *
 * [716] Max Stack
 *
 * https://leetcode.com/problems/max-stack/description/
 *
 * algorithms
 * Easy (41.59%)
 * Likes:    539
 * Dislikes: 96
 * Total Accepted:    41.1K
 * Total Submissions: 98.3K
 * Testcase Example:  '["MaxStack","push","push","push","top","popMax","top","peekMax","pop","top"]\n' +
  '[[],[5],[1],[5],[],[],[],[],[],[]]'
 *
 * Design a max stack that supports push, pop, top, peekMax and popMax.
 * 
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Remove the element on top of the stack and return it.
 * top() -- Get the element on the top.
 * peekMax() -- Retrieve the maximum element in the stack.
 * popMax() -- Retrieve the maximum element in the stack, and remove it. If you
 * find more than one maximum elements, only remove the top-most one.
 * 
 * 
 * 
 * Example 1:
 * 
 * MaxStack stack = new MaxStack();
 * stack.push(5); 
 * stack.push(1);
 * stack.push(5);
 * stack.top(); -> 5
 * stack.popMax(); -> 5
 * stack.top(); -> 1
 * stack.peekMax(); -> 5
 * stack.pop(); -> 1
 * stack.top(); -> 5
 * 
 * 
 * 
 * Note:
 * 
 * -1e7 
 * Number of operations won't exceed 10000.
 * The last four operations won't be called when stack is empty.
 * 
 * 
 */

// @lc code=start
class MaxStack {
    Node head;
    Node tail;
    TreeMap<Integer, LinkedList<Node>> map;
    /** initialize your data structure here. */
    public MaxStack() {
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
        map = new TreeMap<>();
    }
    
    public void push(int x) {
        Node cur = new Node(x);
        Node curtail = tail.prev;
        curtail.next = cur;
        cur.prev = curtail;
        cur.next = tail;
        tail.prev = cur;
        if(!map.containsKey(x)){
            map.put(x, new LinkedList<>());
        }
        map.get(x).addFirst(cur);
    }
    
    public int pop() {
        Node top = tail.prev;
        if(top==head) return Integer.MIN_VALUE;
        top.prev.next = tail;
        tail.prev = top.prev;
        LinkedList<Node> list = map.get(top.val);
        if(list.size()==1){
            map.remove(top.val);
        } else {
            list.removeFirst();
        }
        return top.val;
    }
    
    public int top() {
        return tail.prev.val;
    }
    
    public int peekMax() {
        return map.lastKey();
    }
    
    public int popMax() {
        LinkedList<Node> list = map.lastEntry().getValue();
        Node top = list.pollFirst();
        if(list.size()==0){
            map.pollLastEntry();
        } 
        top.prev.next = top.next;
        top.next.prev = top.prev;
        return top.val;
    }
}

class Node{
    int val;
    Node prev;
    Node next;
    Node(int val){
        this.val = val;
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
// @lc code=end


/*
 * @lc app=leetcode id=23 lang=java
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (37.23%)
 * Likes:    3344
 * Dislikes: 220
 * Total Accepted:    504.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0) return null;
        return merge(lists, 0, lists.length-1);
    }

    private ListNode merge(ListNode[] lists, int start, int end){
        if(end==start){
            return lists[start];
        }
        int mid = (start+end)/2;
        return merge2Lists(merge(lists, start, mid), merge(lists, mid+1, end));
    }

    private ListNode merge2Lists(ListNode a, ListNode b){
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        while(a!=null && b!=null){
            if(a.val > b.val){
                cur.next = b;
                b = b.next;
            } else {
                cur.next = a;
                a = a.next;
            }
            cur = cur.next;
        }
        while(a!=null){
            cur.next = a;
            a = a.next;
            cur = cur.next;    
        }
        while(b!=null){
            cur.next = b;
            b = b.next;
            cur = cur.next;    
        }
        return dummy.next;
    }
}
// @lc code=end
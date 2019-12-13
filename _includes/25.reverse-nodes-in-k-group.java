/*
 * @lc app=leetcode id=25 lang=java
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (38.78%)
 * Likes:    1559
 * Dislikes: 306
 * Total Accepted:    221.3K
 * Total Submissions: 570.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null||k==1) return head; 
        int cnt = 1;
        ListNode tail = head;
        while(tail!=null && cnt <k){
            tail = tail.next;
            cnt++;
        }
        if(tail!=null){
            ListNode nexthead = tail.next;
            tail.next = null;
            nexthead = reverseKGroup(nexthead, k);
            ListNode dummy = new ListNode(0);
            ListNode cur = head;
            dummy.next = cur;
            while(cur.next != null){
                ListNode next = cur.next;
                cur.next = next.next;
                next.next = dummy.next;
                dummy.next = next;
            }
            cur.next = nexthead;
            return dummy.next;         
        } else {
            return head;
        }
    }
}
// @lc code=end


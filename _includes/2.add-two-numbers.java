import java.util.List;

/*
 * @lc app=leetcode id=2 lang=java
 *
 * [2] Add Two Numbers
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        int carry = 0;
        while(l1!=null && l2!=null){
            int sum = l1.val + l2.val + carry;
            int val = sum % 10;
            carry = sum / 10;

            ListNode node = new ListNode(val);
            cur.next = node;
            cur = node;
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1!=null){
            int sum = l1.val + carry;
            int val = sum % 10;
            carry = sum / 10;

            ListNode node = new ListNode(val);
            cur.next = node;
            cur = node;
            l1 = l1.next;
        }
        while(l2!=null){
            int sum = l2.val + carry;
            int val = sum % 10;
            carry = sum / 10;

            ListNode node = new ListNode(val);
            cur.next = node;
            cur = node;
            l2 = l2.next;
        }
        if(carry>0){
            ListNode node = new ListNode(carry);
            cur.next = node;
        }
        return dummy.next;
    }
}
// @lc code=end


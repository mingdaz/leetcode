/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        int carry = helper(head);
        ListNode* ret;
        if(carry){
            ret = new ListNode(1);  
            ret -> next = head;
        } 
        else {
            ret = head;
        }
        return ret;
    }
    
    int helper(ListNode* root){
        if(!root) return 1;
        int carry = helper(root->next);
        if(carry){
            int sum = root->val + carry;
            root->val = sum%10;
            carry = sum/10;
        }
        return carry;
    }
};
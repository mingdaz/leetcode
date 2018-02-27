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
        if(!head) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        p->next = NULL;
        while(q){
            head = q->next;
            q->next = p;
            p = q;
            q = head;
        }
        int carry = 1;
        q = p->next;
        p->next = NULL;
        while(q||carry){
            if(carry){
                int sum = p->val + carry;
                p->val = sum%10;
                carry = sum/10;             
            }
            if(q){
                head = q->next;
                q->next = p;
                p = q;
                q = head;
            }
            else if(carry){
                q = new ListNode(1);
                q->next = p;
                p = q;
                break;
            }
        }
        return p;
    }
};
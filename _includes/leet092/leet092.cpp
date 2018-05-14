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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        for(int i=1;i<m;i++){
            p = p->next;
        }
        ListNode* pm = p->next;
        for(int i=m;i<n;i++){
            ListNode* tmp = pm->next;
            pm->next = tmp->next;
            tmp->next = p->next;
            p->next = tmp;
        }
        return dummy.next;
    }
};
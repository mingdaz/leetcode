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
    ListNode* reverseList(ListNode* head) {
        ListNode* rh = NULL, *tmp;
        while(head){
            tmp = head->next;
            head->next = rh;
            rh = head;
            head = tmp;
        }
        return rh;
    }
};
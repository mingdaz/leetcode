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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* res;
    int len;
    Solution(ListNode* head) {
        res = head;
        ListNode* count_head = head;
        int count = 0;
        while(count_head)
        {
            count++;
            count_head = count_head->next;
        }
        len = count;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int tem = rand()%len;
        ListNode* get = res;
        for(int i=0;i<tem; i++)
        {
            get = get->next;
        }
        return get->val;
    }
};

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
    struct CompareListNode {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        
        if (pq.empty()) {
            return NULL;
        }
        
        ListNode dummy(0);
        ListNode* current = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            current->next = node;
            current = current->next;
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy.next;
    }
};

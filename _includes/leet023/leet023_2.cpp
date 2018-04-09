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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return helper(lists,0,n);
    }
    ListNode* helper(vector<ListNode*>& lists,int a, int b){
        int len = b-a;
        if(len==0) return NULL;
        if(len==1) return lists[a];
        if(len==2) return merge2lists(lists[a],lists[a+1]);
        int mid = a + len/2;
        return merge2lists(helper(lists,a,mid),helper(lists,mid,b));
    }
    ListNode* merge2lists(ListNode* a, ListNode* b){
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while(a&&b){
            if(a->val>b->val){
                cur->next = b;
                b = b->next;
            }
            else{
                cur->next = a;
                a = a->next;
            }
            cur = cur->next;
        }
        if(a) cur->next = a;
        else cur->next = b;
        return dummy.next;
    }
};
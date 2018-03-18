class LRUCache {
struct ListNode {
     int val;
     int key;
     ListNode *prev;
     ListNode *next;
     ListNode(int x,int y) : key(x),val(y), next(NULL), prev(NULL) {}
};
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(dict[key]==NULL) return -1;
        ListNode* tmp = dict[key];
        int ret = tmp->val;
        ListNode* prev = tmp->prev;
        ListNode* next = tmp->next;
        if(prev==NULL) return ret;
        prev->next = next;
        if(next!=NULL) next->prev = prev;
        else tail = prev;
        head->prev = tmp;
        tmp->prev = NULL;
        tmp->next = head;
        head = tmp;
        return ret;
    }
    
    void put(int key, int value) {
        ListNode* tmp;
        if(dict[key]==NULL){
            tmp = new ListNode(key,value);
            dict[key] = tmp;
            if(head==NULL){
                head = tmp;
                tail = tmp; cap--;
                return;
            }
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
            if(cap==0){
                tmp = tail;
                dict[tail->key] = NULL;
                tail = tail->prev;
                tail->next = NULL;
                tmp->prev = NULL;
                // free(tmp);
            }
            else{
                cap--;
            }
        } 
        else{
            tmp = dict[key];
            tmp->val = value;
            ListNode* prev = tmp->prev;
            ListNode* next = tmp->next;
            if(prev==NULL) return;
            prev->next = next;
            if(next!=NULL) next->prev = prev;
            else tail = prev;
            head->prev = tmp;
            tmp->prev = NULL;
            tmp->next = head;
            head = tmp;
        }
    }

private:
    unordered_map<int,ListNode*> dict;
    ListNode* head;
    ListNode* tail;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
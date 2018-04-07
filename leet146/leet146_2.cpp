class Node {
public:
    Node* prev;
    Node* next;
    int val;
    int key;
    Node(Node* prev, int key, int val) {
        this->next = NULL;
        this->prev = prev;
        this->val = val;
        this->key = key;
    }
};

class LRUCache {
public:
    int capacity;
    int iter;
    unordered_map<int, Node*> store;
    Node* head;
    Node* tail;
    
    LRUCache(int capacity) {
        iter = 0;
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }
    
    void move2Tail(Node* temp) {
        if (temp == tail)
            return;
        else if (temp == head) {
            tail->next = temp;
            temp->prev = tail;
            head = head->next;
            tail = tail->next;
            tail->next = NULL;
            head->prev = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }
    }
    
    int get(int key) {
        if (store.find(key) != store.end() && store[key] != NULL) {
            Node* temp = store[key];
            move2Tail(temp);
            return store[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (store[key] != NULL) {
                store[key]->val = value;
                move2Tail(store[key]);
        }
        else if (iter < capacity) {
            iter++;
            Node* temp = new Node(tail, key, value);
            store[key] = temp;
            if (head == NULL) {
                head = temp;
                tail = head;
            }
            else {
                tail->next = temp;
                tail = temp;
            } 
            
        }
        else {
//             evict
            store[head->key] = NULL;
            store[key] = head;
            head->key = key;
            head->val = value;
            move2Tail(head);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
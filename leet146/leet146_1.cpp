class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;
        
        Node(int newKey, int newValue) : key(newKey), value(newValue), next(nullptr), prev(nullptr) {  
        }
    };
    
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    int capacity;
    int size;
    
    LRUCache(int newCapacity) : capacity(newCapacity), size(0) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        tail->next = head;
        head->prev = tail;
    }
    
    int get(int key) {
        if (map.count(key) > 0) {
            return getNodeValue(map.at(key));
        }
        return -1;
    }
    

    void put(int key, int value) {
        if (map.count(key) > 0) {
            Node* node = map.at(key);
            detachNode(node);            
            insertIntoFrontOfList(node);
            node->value = value;
            
            return;
        }

        Node* node = new Node(key, value);
        insertIntoFrontOfList(node);
        map.insert(make_pair(key, node));
        
        if (++size > capacity) {
            removeLeastRecentlyUsed();
        }
    }
    
private:
    // moves the node to the front of the list, then returns its value
    int getNodeValue(Node* node) {
        detachNode(node);
        insertIntoFrontOfList(node);

        return node->value;
    }
    
    void detachNode(Node* node) {
        Node* beforeNode = node->prev;
        Node* afterNode = node->next;
        beforeNode->next = afterNode;
        afterNode->prev = beforeNode;
    }

    void insertIntoFrontOfList(Node* node) {
        Node* beforeHead = head->prev;
        head->prev = node;
        node->prev = beforeHead;
        node->next = head;
        beforeHead->next = node;
    }

    // removes the last element, this function requires size > 0;
    void removeLeastRecentlyUsed() {
        Node* lastElement = tail->next;
        detachNode(lastElement);
        map.erase(lastElement->key);

        delete lastElement;       
        size--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
class LFUCache {
    struct Node {
        int count;
        int val;
        int key;
        
        list<int>::iterator it;
        
        Node(int k, int v) {
            count = 0;
            val = v;
            key = k;
        }
    };
    
    unordered_map<int, Node> index_;
    unordered_map<int, list<int>> count_;
    int size_;
    int capacity_;
    int small_;
    
    void raise(Node &cur) {
        auto &from = count_[cur.count];
        auto &to = count_[cur.count + 1];
        to.splice(to.begin(), from, cur.it);
        
        if (from.empty()) {
            count_.erase(cur.count);
            if (small_ == cur.count) {
                ++small_;
            }
        }
        
        ++cur.count;
    }
    
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
        size_ = 0;
        small_ = 0;
    }
    
    int get(int key) {
        auto it = index_.find(key);
        if (it == index_.end()) {
            return -1;
        }
        
        auto &cur = it->second;
        raise(cur);
        
        return cur.val;
    }
    
    void put(int key, int value) {
        if (capacity_ == 0) {
            return;
        }
        
        auto it = index_.find(key);
        if (it != index_.end()) {
            auto &cur = it->second;
            cur.val = value;
            raise(cur);
            return;
        }
        
        auto &cur = index_.emplace(key, Node(key, value)).first->second;
        ++size_;
        
        if (size_ > capacity_) {
            auto &head = count_[small_];
            auto first = head.back();
            head.pop_back();
            
            index_.erase(first);

            if (head.empty()) {
                count_.erase(small_);
            }
            --size_;
        }
        
        small_ = min(small_, cur.count);
        auto &head = count_[cur.count];
        head.push_front(key);
        cur.it = head.begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
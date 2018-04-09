class LRUCache {
    int _capacity;
    list<pair<int, int>> _list;                             // key, value
    unordered_map<int, list<pair<int,int>>::iterator> _map; // key, iterator of list(key,value)
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        // unordered_map<int, list<pair<int,int>>::iterator>::iterator it = _map.find(key);
        auto it = _map.find(key);
        if(it != _map.end()){//if existed, reorder
            _list.splice(_list.begin(), _list, it->second);//moving (1)it in (2)_list to (3)_list.begin()
            return it->second->second;
        }
        else {//not existed
            return -1;
        }
    }
    
    void put(int key, int value) {
        // unordered_map<int, list<pair<int,int>>::iterator>::iterator it = _map.find(key);
        auto it = _map.find(key);
        if(it != _map.end()){//existed
            it->second->second = value;//change value
            _list.splice(_list.begin(), _list, it->second);//reorder
        }
        else {//not existied
            //add it in
            pair<int,int> newNode(key, value);
            _list.push_front(newNode);
            _map[key] = _list.begin();
            //handle overlength
            if(_list.size() > _capacity){
                _map.erase(_list.back().first);//_list.end()->first
                _list.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
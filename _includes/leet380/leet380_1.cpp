class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand (time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(HashMap.find(val)!=HashMap.end()) return false;
        data.push_back(val);
        HashMap[val] = data.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(HashMap.find(val)==HashMap.end()) return false;
        swap(data[HashMap[val]],data[data.size()-1]);
        HashMap[data[HashMap[val]]] = HashMap[val];
        HashMap.erase(val);
        data.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = data.size();
        n = rand() % n;
        return data[n];
    }
private:
    unordered_map<int,int> HashMap;
    vector<int> data;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

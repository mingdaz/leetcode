class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        pool = vector<char>(maxNumbers,1);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        for(int i=0;i<pool.size();i++){
            if(pool[i]){
                pool[i] = 0;
                return i;
            }
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return pool[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        pool[number] = 1;
    }
private:
    vector<char> pool;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

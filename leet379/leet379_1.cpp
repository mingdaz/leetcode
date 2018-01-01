class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers)
        : lst(vector<int>(maxNumbers)), marked(vector<int>(maxNumbers, 1)), idx(maxNumbers - 1) {
        iota(lst.begin(), lst.end(), 0);
    }    
    int get() {
        if (idx < 0) return -1;
        int ret = lst[idx--];
        marked[ret] = 0;
        return ret;
    }
    bool check(int number) {
        return marked[number];
    }
    void release(int number) {
        if (!marked[number]) {
            lst[++idx] = number;
            marked[number] = 1;
        }
    }
private:
    vector<int> lst;
    vector<int> marked;
    int idx;
};

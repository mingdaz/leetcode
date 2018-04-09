// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:    
    int cache;
    bool has_cache;
    
public:    
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    has_cache = false;
        
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!has_cache) {
            cache = Iterator::next();
            has_cache = true;
        };
        return cache;        
	}
    

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ret;
	    if (has_cache)  {
            ret = cache;
            has_cache = false;
        }
        else {
            ret = Iterator::next();
        };
        return ret;
	}

	bool hasNext() const {
	    return (has_cache || Iterator::hasNext());
	}
};
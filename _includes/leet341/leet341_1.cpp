/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
typedef vector<NestedInteger>::iterator NII; 
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        head = nestedList.begin();
        tail = nestedList.end();
        move();
    }

    int next() {
        int res = head->getInteger();
        head++;
        move();
        return res;
    }

    bool hasNext() {
        return !S.empty()||head!=tail;
    }
private:
    void move(){
        while(true){
            while(head!=tail&&!head->isInteger()){
                NII th = head->getList().begin();
                NII tt = head->getList().end();
                head++;
                if(head!=tail)
                    S.push(pair<NII,NII>(head,tail));
                head = th;
                tail = tt;
            }
            while(head==tail&&!S.empty()){
                auto p = S.top();
                S.pop();
                head = p.first;
                tail = p.second;
            }
            if(head==tail||head->isInteger())
                break;
        }

    }
    NII head,tail;
    stack<pair<NII,NII>> S;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
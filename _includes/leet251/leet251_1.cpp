class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        head = vec2d.begin();
        tail = vec2d.end();
        if(head!=tail){
            cur = (*head).begin();
            move();
        }    
    }

    int next() {
        int ret = *cur;
        cur++;
        move();
        return ret;
    }

    bool hasNext() {
        return head!=tail;
    }
private:
    void move(){
        while(head!=tail&&cur==(*head).end() ){
            head++;
            cur = (*head).begin();
        }
    }
    vector<vector<int>>::iterator head,tail;
    vector<int>::iterator cur;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
class Vector2D {
private: 
    vector<vector<int>>::iterator it;
    vector<vector<int>>::iterator tail;
    vector<int>::iterator cur_it;
    bool isempty = false;
    
public:
    
    Vector2D(vector<vector<int>>& vec2d) {
        if(vec2d.empty()) isempty = true;
        else{
            it = vec2d.begin();
            tail = vec2d.end();
            cur_it = it->begin();    
        }
    }

    int next() {
        int res = *cur_it;
        ++cur_it;
        return res;
    }

    bool hasNext() {
        if(isempty) return false;
        if(cur_it==it->end()){
            ++it;
            while(it!=tail&&it->empty()) ++it;
            if(it!=tail) cur_it = it->begin();
            else return false;
        } 
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

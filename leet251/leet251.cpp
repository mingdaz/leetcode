class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        if(vec2d.empty()) empty=true;
        else{
    	    rowend = vec2d.end();
		    row = vec2d.begin();
		    while(row->empty()&&row!=rowend) ++row;
		    if(row!=rowend) col = row->begin();
        }
	} 
    

    int next() {
        int res = *col;
		++col;
		if(col==row->end()){
			while((++row)->empty()&&row!=rowend);
		    if(row!=rowend) col = row->begin();
		}
		return res;
    }

    bool hasNext() {
        if(empty) return false;
        return row!=rowend;
    }
    bool empty = false;
	vector<vector<int>>::iterator rowend;
	vector<vector<int>>::iterator row;
	vector<int>::iterator col;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */


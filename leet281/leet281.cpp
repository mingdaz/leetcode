
class ZigzagIterator {
private:
	queue<pair<int,int>> q;
vector<vector<int>> data;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size()>0)
	        q.push(make_pair(0,0));
	    if(v2.size()>0)
		    q.push(make_pair(1,0));
	data.push_back(v1);
	data.push_back(v2);
	
    }

    int next() {
	pair<int,int>& curr = q.front();
	int val = data[curr.first][curr.second];
	if(curr.second+1<data[curr.first].size()){
		++curr.second;
		q.push(curr);
}

	q.pop();
	return val;
         }

    bool hasNext() {
        	return !q.empty();
    }
};

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * }; * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        // write your code here
        vector<pair<double,Point>> dist;
        dist.resize(points.size());
        for(int i=0;i<points.size();i++){
        	dist[i].first = pow(points[i].x - origin.x,2) + pow(points[i].y - origin.y,2);
        	dist[i].second = points[i]; 
        }
        quickselect(dist,k,0, dist.size()-1);
        sort(dist.begin(),dist.begin()+k,[](const pair<double,Point>& a,const pair<double,Point>& b){return a.first<b.first||(a.first==b.first&&a.second.x<b.second.x);});
        vector<Point> res;
        for(int i=0;i<k;i++){
        	res.push_back(dist[i].second);
        }
        return res;
    }
private:
	void quickselect(vector<pair<double,Point>>& dist, int k, int l, int r){
	    if(k>r-l+1||k<1) return;
		int idx = partition(dist,l,r);
		if(idx - l==k-1) return;
		if(idx - l>k-1){
			quickselect(dist,k,l,idx-1);
		}
		else
			quickselect(dist,k-idx+l-1,idx+1,r);
	}
	int partition(vector<pair<double,Point>>& dist, int l, int r){
		double x = dist[r].first;
		int i = l;
		for(int j=l;j<r;j++){
			if(dist[j].first <= x){
				swap(dist[i],dist[j]);
				i++;
			}
		}
		swap(dist[i],dist[r]);
		return i;
	}
};

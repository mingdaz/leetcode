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
	struct compare
	{
		bool operator()(const pair<double,Point>& a,const pair<double,Point>& b){
			return a.first<b.first||
        	(a.first==b.first&&a.second.x<b.second.x)||
        	(a.first==b.first&&a.second.x==b.second.x&&a.second.y<b.second.y);
        }
	};
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
        priority_queue<pair<double,Point>,vector<pair<double,Point>>,compare> maxHeap;
        for(int i=0;i<k;i++){
        	maxHeap.push_back(dist[i]);
        }
        for(int i=k;i<dist.size();i++){
        	maxHeap.push_back(dist[i]);
        	maxHeap.pop();
        }
        vector<Point> res;
        res.resize(k);
        for(int i=0;i<k;i++){
        	res[k-i-1]== maxHeap.top().second;
        	maxHeap.pop();
        }

        return res;
    }
};

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        if(points.size()<4)return points;
        //first find the lowest points
        int len=points.size();
        vector<Point> res;
        int idx=0;
        int lowy=INT_MAX;
        int leftx=INT_MAX;
        for(int i=0;i<len;i++){
            if(points[i].y<lowy){
                idx=i;
                lowy=points[i].y;
                leftx=points[i].x;
            }else if(points[i].y==lowy&&points[i].x<leftx){
                idx=i;
                leftx=points[i].x;
            }
        }
        int inext=-1;
        int icur=idx;
        while(inext!=idx){
            inext=FindNext(points,icur,res);
            icur=inext;
        }
        return res;
    }
    int FindNext(vector<Point>& points,int icur,vector<Point>& res){
        int inext=icur==0? 1:0;
        int dx=points[inext].x-points[icur].x;
        int dy=points[inext].y-points[icur].y;
        for(int i=0;i<points.size();i++){
            if(i==icur||i==inext)continue;
            int dx2=points[i].x-points[icur].x;
            int dy2=points[i].y-points[icur].y;
            if(dx*dy2-dx2*dy<0){
                inext=i;
                dx=dx2;
                dy=dy2;
            }
        }
        vector<Point> possibles;
        for(int i=0;i<points.size();i++){
            if(i==icur)continue;
            int dx2=points[i].x-points[icur].x;
            int dy2=points[i].y-points[icur].y;
            if(dx*dy2-dx2*dy==0){
                possibles.push_back(points[i]);
                if(abs(dx2)>abs(dx)||abs(dy2)>abs(dy))inext=i;
            }
        }
        for(Point p : possibles)res.push_back(p);
        return inext;
    }
};


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include <algorithm>
#include <sstream>
#include <functional>
#include <bitset>
#include <numeric>
#include <cmath>

using namespace std;

/*
struct Point 
{
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};
*/

class Solution
{
public:
    vector<Point> outerTrees(vector<Point>& points) 
    {
        vector<Point> res;
        Point first = points[0];
        int firstIdx = 0, n = points.size();
        for (int i = 1; i < n; ++i) 
        {
            if (points[i].x < first.x) 
            {
                first = points[i];
                firstIdx = i;
            }
        }
        res.push_back(first);

        Point cur = first;
        int curIdx = firstIdx;
        while (true) 
        {
            Point next = points[0];
            int nextIdx = 0;
            for (int i = 1; i < n; ++i)
            {
                if (i == curIdx) continue;
                int cross = crossProduct(cur, points[i], next);
                if (nextIdx == curIdx || cross > 0 || (cross == 0 && dist(points[i], cur) > dist(next, cur)))
                {
                    next = points[i];
                    nextIdx = i;
                }
            }
            for (int i = 0; i < n; ++i) 
            {
                if (i == curIdx) continue;
                int cross = crossProduct(cur, points[i], next);
                if (cross == 0)
                {
                    if (check(res, points[i])) res.push_back(points[i]);
                }
            }
            cur = next;
            curIdx = nextIdx;
            if (curIdx == firstIdx) 
                break;
        }
        return res;
    }

    int crossProduct(Point A, Point B, Point C)
    {
        int BAx = A.x - B.x;
        int BAy = A.y - B.y;
        int BCx = C.x - B.x;
        int BCy = C.y - B.y;
        return BAx * BCy - BAy * BCx;
    }

    int dist(Point A, Point B)
    {
        return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
    }

    bool check(vector<Point>& res, Point p)
    {
        for (Point r : res) 
        {
            if (r.x == p.x && r.y == p.y)
                return false;
        }
        return true;
    }
};
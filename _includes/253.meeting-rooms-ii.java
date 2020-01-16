/*
 * @lc app=leetcode id=253 lang=java
 *
 * [253] Meeting Rooms II
 *
 * https://leetcode.com/problems/meeting-rooms-ii/description/
 *
 * algorithms
 * Medium (44.43%)
 * Likes:    2058
 * Dislikes: 31
 * Total Accepted:    226.6K
 * Total Submissions: 509.6K
 * Testcase Example:  '[[0,30],[5,10],[15,20]]'
 *
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
 * required.
 * 
 * Example 1:
 * 
 * 
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 * 
 * Example 2:
 * 
 * 
 * Input: [[7,10],[2,4]]
 * Output: 1
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
// Solution I
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        if(n==0) return 0;
        int cnt = 0;
        int res = 0;
        // TimeStamp, isStart
        Point[] A = new Point[2*n];
        int i=0;
        for(int[] intv: intervals){
            A[i++] = new Point(intv[0], true);
            A[i++] = new Point(intv[1], false);
        }
        Arrays.sort(A,new Cmp());
        for(Point p: A){
            if(p.isStart){
                cnt++;
                if(cnt > res) res = cnt;
            }
            else cnt--;
        }
        return res;
    }
}
class Point{
    int ts;
    boolean isStart;
    Point(int ts, boolean isStart){
        this.ts = ts;
        this.isStart = isStart;
    }
}

class Cmp implements Comparator<Point> {
    public int compare(Point a, Point b){
        if(a.ts==b.ts){
            if(a.isStart==b.isStart) return 0;
            if(!a.isStart) return -1;
            return 1;
        }
        return Integer.compare(a.ts, b.ts);
    }
}
// Solution II
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        if(n==0) return 0;
        int cnt = 0;
        int res = 0;
        // TimeStamp, isStart
        int[] start = new int[n];
        int[] end = new int[n];
        for(int i=0;i<intervals.length;i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        Arrays.sort(start);
        Arrays.sort(end);
        
        for(int i=0,j=0;i<n;){
            if(start[i]<end[j]){
                cnt++;
                i++;
                if(cnt > res) res = cnt;
            } else {
                cnt--;
                j++;
            }
        }
        return res;
    }
}
// @lc code=end


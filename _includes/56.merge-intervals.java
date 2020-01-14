import java.util.Comparator;
import java.util.LinkedList;

/*
 * @lc app=leetcode id=56 lang=java
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (37.61%)
 * Likes:    3048
 * Dislikes: 236
 * Total Accepted:    475.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length==0) return new int[0][];
        Arrays.sort(intervals, new Cmp());
        LinkedList<int[]> res = new LinkedList<>();
        res.add(intervals[0]);
        for(int i=1;i<intervals.length;i++){
            if(intervals[i][0]<=res.getLast()[1]){
                if(intervals[i][1] > res.getLast()[1]){
                    res.getLast()[1] = intervals[i][1];
                }
            } else {
                res.add(intervals[i]);
            }
        }
        int[][] resA = new int[res.size()][2];
        return res.toArray(resA);        
    }
}

class Cmp implements Comparator<int[]> {
    public int compare(int[] a, int[] b){
        return Integer.compare(a[0], b[0]);
    }
}

// @lc code=end


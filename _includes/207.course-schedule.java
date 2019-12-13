import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode id=207 lang=java
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (40.12%)
 * Likes:    2520
 * Dislikes: 128
 * Total Accepted:    292.9K
 * Total Submissions: 729.9K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] outdegree = new int[numCourses];
        List<Integer>[] adjacent = new ArrayList[numCourses];
        for(int i=0;i<prerequisites.length;i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            if(adjacent[b]==null){
                adjacent[b] = new ArrayList<>();
            }
            adjacent[b].add(a);
            outdegree[a]++;
        }
        Queue<Integer> q = new LinkedList<>();

        for(int i=0;i<numCourses;i++){
            if(outdegree[i]==0)
                q.add(i);
        }
        int count = 0;
        while(q.size()>0){
            int i = q.poll();
            if(adjacent[i] != null){                    
                for(int j:adjacent[i]){
                    if(--outdegree[j]==0){
                        q.offer(j);
                    }
                }
            } 
            count++;
        }
        return count==numCourses;
    }
}
// @lc code=end


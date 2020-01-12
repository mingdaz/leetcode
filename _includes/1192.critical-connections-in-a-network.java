import java.util.Arrays;

/*
 * @lc app=leetcode id=1192 lang=java
 *
 * [1192] Critical Connections in a Network
 *
 * https://leetcode.com/problems/critical-connections-in-a-network/description/
 *
 * algorithms
 * Hard (48.98%)
 * Likes:    479
 * Dislikes: 40
 * Total Accepted:    23.3K
 * Total Submissions: 47.8K
 * Testcase Example:  '4\n[[0,1],[1,2],[2,0],[1,3]]'
 *
 * There are n servers numbered from 0 to n-1 connected by undirected
 * server-to-server connections forming a network where connections[i] = [a, b]
 * represents a connection between servers a and b. Any server can reach any
 * other server directly or indirectly through the network.
 * 
 * A critical connection is a connection that, if removed, will make some
 * server unable to reach some other server.
 * 
 * Return all critical connections in the network in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
 * Output: [[1,3]]
 * Explanation: [[3,1]] is also accepted.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * n-1 <= connections.length <= 10^5
 * connections[i][0] != connections[i][1]
 * There are no repeated connections.
 * 
 * 
 */

// @lc code=start
// Based on GeeksForGeeks
class Solution {
    int time = 0;
    int[] low;
    int[] disc;
    int[] parent;
    boolean[] vis;
    List<Integer>[] graph;
    List<List<Integer>> res;
        

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        res = new ArrayList<>();
        graph = new List[n];
        for(int i=0;i<n;i++){
            graph[i] = new LinkedList<>();
        }
        
        for(List<Integer> conn: connections){
            int s = conn.get(0);
            int t = conn.get(1);
            graph[s].add(t);
            graph[t].add(s);
        }
        
        low = new int[n];
        disc = new int[n];
        parent = new int[n];
        vis = new boolean[n];
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bridge(i);
            }
        }
        return res;
    }
    
    private void bridge(int cur){
        vis[cur] = true;
        disc[cur] = low[cur] = ++time;
        for(int next: graph[cur]){
            if(!vis[next]){
                parent[next] = cur;
                bridge(next);
                if(low[next] < low[cur]) low[cur] = low[next];
                if(low[next] > disc[cur])
                    res.add(Arrays.asList(cur, next));
            } else if(next!=parent[cur]){
                low[cur] = Math.min(low[cur], disc[next]);
            }
        }
    }
}


// Fastest Solution, Graph is represented in Forward Star data structure
class Solution {
    int edgeIndex = 0;
    int[] to;
    int[] next;
    int[] head;
    int[] low;
    int[] disc;
    int time = -1;
    List<List<Integer>> res = new ArrayList<>();
    private void addEdge(int u, int v) {
        to[edgeIndex] = v;
        next[edgeIndex] = head[u];
        head[u] = edgeIndex ++;
    }
    
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        low = new int[n];
        disc = new int[n];
        int m = connections.size();
        to = new int[m * 2];
        head = new int[n];
        next = new int[m * 2];
        Arrays.fill(head, -1);
        Arrays.fill(next, -1);
        Arrays.fill(low, -1);
        Arrays.fill(disc, -1);
        
        for (List<Integer> edge : connections) {
            int u = edge.get(0);
            int v = edge.get(1); 
            addEdge(u, v);
            addEdge(v, u);
        }
        
        dfs(1, -1);
        return res;
    }
    private void dfs(int node, int parent) {
        if (disc[node] != -1) {
            return;
        }
        low[node] = disc[node] = ++ time;
        for (int edge = head[node]; edge != -1; edge = next[edge]) {
            int next = to[edge];
            if (disc[next] == -1) {
                dfs(next, node);
                low[node] = Math.min(low[node], low[next]);
                if (low[next] > disc[node]) {
                    res.add(Arrays.asList(node, next));
                }
            } else if (next != parent) {
                low[node] = Math.min(low[node], disc[next]);
            }
        }
    }
}

// @lc code=end


/*
 * @lc app=leetcode id=1320 lang=java
 *
 * [1320] Minimum Distance to Type a Word Using Two Fingers
 *
 * https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/
 *
 * algorithms
 * Hard (44.39%)
 * Likes:    80
 * Dislikes: 3
 * Total Accepted:    1.8K
 * Total Submissions: 4.2K
 * Testcase Example:  '"CAKE"'
 *
 * 
 * 
 * You have a keyboard layout as shown above in the XY plane, where each
 * English uppercase letter is located at some coordinate, for example, the
 * letter A is located at coordinate (0,0), the letter B is located at
 * coordinate (0,1), the letter P is located at coordinate (2,3) and the letter
 * Z is located at coordinate (4,1).
 * 
 * Given the string word, return the minimum total distance to type such string
 * using only two fingers. The distance between coordinates (x1,y1) and (x2,y2)
 * is |x1 - x2| + |y1 - y2|. 
 * 
 * Note that the initial positions of your two fingers are considered free so
 * don't count towards your total distance, also your two fingers do not have
 * to start at the first letter or the first two letters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word = "CAKE"
 * Output: 3
 * Explanation: 
 * Using two fingers, one optimal way to type "CAKE" is: 
 * Finger 1 on letter 'C' -> cost = 0 
 * Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
 * Finger 2 on letter 'K' -> cost = 0 
 * Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
 * Total distance = 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word = "HAPPY"
 * Output: 6
 * Explanation: 
 * Using two fingers, one optimal way to type "HAPPY" is:
 * Finger 1 on letter 'H' -> cost = 0
 * Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
 * Finger 2 on letter 'P' -> cost = 0
 * Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
 * Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
 * Total distance = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word = "NEW"
 * Output: 3
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: word = "YEAR"
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= word.length <= 300
 * Each word[i] is an English uppercase letter.
 * 
 */

// @lc code=start
// Solution 1
class Solution {

    public int minimumDistance(String word) {
        if(word.length()<3) return 0;
        int n = word.length();
        int[][] board = new int[26][2];
        for (int i = 0; i < 26; i++) {
            board[i][0] = i / 6;
            board[i][1] = i % 6;
        }
        int[][] dis = new int[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dis[i][j] = Math.abs(board[i][0] - board[j][0]) + Math.abs(board[i][1] - board[j][1]);
            }
        }

        int[][][] dp = new int[n+1][26][26];
        char[] s = word.toCharArray();
        for(int i=0;i<n+1;i++){
            for(int j=0;j<26;j++){
                Arrays.fill(dp[i][j], Integer.MAX_VALUE);
            }
        }
        int first = s[0] - 'A';
        for(int i=0;i<26;i++){
            dp[1][i][first] = 0;
            dp[1][first][i] = 0;
        }


        for(int i=1;i<n;i++){
            int t = s[i] - 'A';
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(dp[i][j][k]!= Integer.MAX_VALUE){
                        dp[i+1][t][k] = Math.min(dp[i+1][t][k], dp[i][j][k] + dis[j][t]);
                        dp[i+1][j][t] = Math.min(dp[i+1][j][t], dp[i][j][k] + dis[k][t]);
                    }
                }
            }
        }
        int res = Integer.MAX_VALUE;
        int last = s[n-1] - 'A';
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){
                res = Math.min(res, Math.min(dp[n][last][k],dp[n][j][last]));    
            }
        }
        return res;
    }
}

// Solution 2
class Solution {
    public int minimumDistance(String word) {
        int[][] board = new int[26][2];
        for (int i = 0; i < 26; i++) {
            board[i][0] = i / 6;
            board[i][1] = i % 6;
        }
        int[][] dist = new int[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dist[i][j] = Math.abs(board[i][0] - board[j][0]) + Math.abs(board[i][1] - board[j][1]);
            }
        }
        char[] cs = word.toCharArray();
        int[][] dp = new int[cs.length + 1][cs.length + 1];
        for (int[] d : dp) Arrays.fill(d, 0);
        for (int j = 1; j <= cs.length; j++) {
            for (int i = 0; i < j; i++) {
                if (i == 0) {
                    if (j != 1) {
                        dp[i][j] = dp[i][j - 1] + dist[cs[j - 1] - 'A'][cs[j - 2] - 'A'];
                    }
                    continue;
                }
                if (i == 1 && j == 2) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i + 1 == j) {
                    int min = Integer.MAX_VALUE;
                    for (int p = 1; p <= i - 1; p++) {
                        min = Math.min(min, dp[p][i] + dist[cs[p - 1] - 'A'][cs[j - 1] - 'A']);
                    }
                    min = Math.min(min, dp[0][i]);
                    dp[i][j] = min;
                }
                else {
                    dp[i][j] = dp[i][j - 1] + dist[cs[j - 1] - 'A'][cs[j - 2] - 'A'];
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < cs.length; i++) {
            res = Math.min(dp[i][cs.length], res);
        }
        return res;
    }
}
// @lc code=end


/*
 * @lc app=leetcode id=289 lang=java
 *
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (50.27%)
 * Likes:    1328
 * Dislikes: 235
 * Total Accepted:    148.9K
 * Total Submissions: 295.7K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 * 
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 * 
 * 
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 * 
 * 
 * Write a function to compute the next state (after one update) of the board
 * given its current state. The next state is created by applying the above
 * rules simultaneously to every cell in the current state, where births and
 * deaths occur simultaneously.
 * 
 * Example:
 * 
 * 
 * Input: 
 * [
 * [0,1,0],
 * [0,0,1],
 * [1,1,1],
 * [0,0,0]
 * ]
 * Output: 
 * [
 * [0,0,0],
 * [1,0,1],
 * [0,1,1],
 * [0,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 * 
 * 
 */

// @lc code=start
class Solution {

    int[] dx = {0,0,1,-1,1,-1,1,-1};
    int[] dy = {1,-1,0,0,1,-1,-1,1};

    public void gameOfLife(int[][] board) {
        int m = board.length;
        if(m==0) return;
        int n = board[0].length;
        if(n==0) return;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int neighbors = 0;
                for(int k=0;k<8;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x>=0 && x<m && y>=0 && y<n){
                        if((board[x][y] & 1)==1)
                            neighbors++;
                    }
                }
                if(board[i][j]==1&&neighbors==2){
                    // do nothing die in next round;
                    board[i][j] |= 2;
                } else if( neighbors==3){
                    board[i][j] |= 2;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] = (board[i][j] >> 1);
            }
        }
    }
}
// @lc code=end


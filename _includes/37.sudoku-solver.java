/*
 * @lc app=leetcode id=37 lang=java
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (39.85%)
 * Likes:    1246
 * Dislikes: 77
 * Total Accepted:    155.1K
 * Total Submissions: 388.7K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */

// @lc code=start
class Solution {
    // box size
    int n = 3;
    // row size
    int N = n * n;
  
    int [][] rows = new int[N][N + 1];
    int [][] columns = new int[N][N + 1];
    int [][] boxes = new int[N][N + 1];
  
    char[][] board;
  
    boolean sudokuSolved = false;
  
    public boolean couldPlace(int d, int row, int col) {
      /*
      Check if one could place a number d in (row, col) cell
      */
      int idx = (row / n ) * n + col / n;
      return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
    }
  
    public void placeNumber(int d, int row, int col) {
      /*
      Place a number d in (row, col) cell
      */
      int idx = (row / n ) * n + col / n;
  
      rows[row][d]++;
      columns[col][d]++;
      boxes[idx][d]++;
      board[row][col] = (char)(d + '0');
    }
  
    public void removeNumber(int d, int row, int col) {
      /*
      Remove a number which didn't lead to a solution
      */
      int idx = (row / n ) * n + col / n;
      rows[row][d]--;
      columns[col][d]--;
      boxes[idx][d]--;
      board[row][col] = '.';
    }
  
    public void placeNextNumbers(int row, int col) {
      /*
      Call backtrack function in recursion
      to continue to place numbers
      till the moment we have a solution
      */
      // if we're in the last cell
      // that means we have the solution
      if ((col == N - 1) && (row == N - 1)) {
        sudokuSolved = true;
      }
      // if not yet
      else {
        // if we're in the end of the row
        // go to the next row
        if (col == N - 1) backtrack(row + 1, 0);
          // go to the next column
        else backtrack(row, col + 1);
      }
    }
  
    public void backtrack(int row, int col) {
      /*
      Backtracking
      */
      // if the cell is empty
      if (board[row][col] == '.') {
        // iterate over all numbers from 1 to 9
        for (int d = 1; d < 10; d++) {
          if (couldPlace(d, row, col)) {
            placeNumber(d, row, col);
            placeNextNumbers(row, col);
            // if sudoku is solved, there is no need to backtrack
            // since the single unique solution is promised
            if (!sudokuSolved) removeNumber(d, row, col);
          }
        }
      }
      else placeNextNumbers(row, col);
    }
  
    public void solveSudoku(char[][] board) {
      this.board = board;
  
      // init rows, columns and boxes
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          char num = board[i][j];
          if (num != '.') {
            int d = Character.getNumericValue(num);
            placeNumber(d, i, j);
          }
        }
      }
      backtrack(0, 0);
    }
  }
// @lc code=end


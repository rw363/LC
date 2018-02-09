/*
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (37.24%)
 * Total Accepted:    61.9K
 * Total Submissions: 166.3K
 * Testcase Example:  '[[]]'
 *
 * 
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 * 
 * 
 * 
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 * 
 * 
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
 * 
 * 
 * Write a function to compute the next state (after one update) of the board
 * given its current state.
 * 
 * 
 * Follow up: 
 * 
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int neighbors(vector<vector<int>> &board, int i, int j)
    {
        int count = 0;
        int n = board.size();
        int m = board[0].size();
        for (int y = max(0, i - 1); y < min(n, i + 2); y++)
        {
            for (int x = max(0, j - 1); x < min(m, j + 2); x++)
            {
                if (y == i && x == j) continue;
                if (board[y][x] & 1 == 1) count++;
            }
        }
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        // store the current bit in LSB, next gen in the 2nd bit
        // >> all the board to jump to the next gen
        // rules:
        //      1) dead + 3 neightbors -> live
        //      2) live + 2 || 3 neghbors -> live
        
        int n = board.size();
        int m = board[0].size();
        
        // apply the rule
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j++)
            {
                // first calculate the neighbors and apply rules
                int count = neighbors(board, i, j);
                // apply rules 1
                if ((board[i][j] & 1) == 0 && count == 3) board[i][j] |= 2;
                else if ((board[i][j] & 1) == 1 && (count == 2 || count == 3 )) board[i][j] |= 2;
            }
        }

        // regen
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] >>= 1;
            }
        }
        
    }
};

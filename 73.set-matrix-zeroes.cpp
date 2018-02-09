/*
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (36.41%)
 * Total Accepted:    129K
 * Total Submissions: 354.3K
 * Testcase Example:  '[[0]]'
 *
 * 
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in place.
 * 
 * 
 * click to show follow up.
 * 
 * Follow up:
 * 
 * 
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 * 
 * 
 */using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 1) round, check which col or row shall be set to zero, save the info in col 0 and row 0
        // use col 0 to track if the row i shall be set to 0: if (matrix[i][0] == 0) col0 = true;
        // then would need a variable col0 to track if col 0 shall be set to 0 
        // if matrix[i][j] == 0, set matrix[0][j] = matrix[i][0] = 0;
        // 2) round, clear col and row as marked, from the right & bottom
        // if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
        // then check if clear the 1st col if (col0) matrix[i][0] = 0;

        
        int rown = matrix.size();
        int coln = matrix[0].size();
        
        bool col0 = false;
        
        for (int i = 0; i < rown; i++)
        {
            // check the first col
            if (matrix[i][0] == 0) col0 = true;
            // first col is already handled
            for (int j = 1; j < coln; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // mark in first row and first col
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        // now clear the matrix
        for (int i = rown - 1; i >= 0; i--)
        {
            for (int j = coln - 1; j >=1; j--)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
            if (col0) matrix[i][0] = 0;
        }
    }
};

/*

 * [463] Island Perimeter

 *

 * https://leetcode.com/problems/island-perimeter/description/

 *

 * algorithms

 * Easy (57.73%)

 * Total Accepted:    70.7K

 * Total Submissions: 122.5K

 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'

 *

 * You are given a map in form of a two-dimensional integer grid where 1

 * represents land and 0 represents water. Grid cells are connected

 * horizontally/vertically (not diagonally). The grid is completely surrounded

 * by water, and there is exactly one island (i.e., one or more connected land

 * cells). The island doesn't have "lakes" (water inside that isn't connected

 * to the water around the island). One cell is a square with side length 1.

 * The grid is rectangular, width and height don't exceed 100. Determine the

 * perimeter of the island.

 * 

 * Example:

 * 

 * [[0,1,0,0],

 * ⁠[1,1,1,0],

 * ⁠[0,1,0,0],

 * ⁠[1,1,0,0]]

 * 

 * Answer: 16

 * Explanation: The perimeter is the 16 yellow stripes in the image below:

 * 

 * 

 * 

 */

using namespace std;


class Solution {
public:
     int islandPerimeter(vector<vector<int>>& grid) {
          if (grid.empty())
               return 0;
          int row = grid.size();
          int col = grid[0].size();
          int node = 0;
          int shared = 0;
          for (int i = 0; i < row; i++)
          {
               for (int j = 0; j < col; j++)
               {
                    if (grid[i][j] == 1)
                    {
                         node++;
                         if (j > 0 && grid[i][j-1] == 1)
                              shared++;
                         if (i > 0 && grid[i-1][j] == 1)
                              shared++;
                    }
               }
          }
          return node * 4 - shared * 2;
     }
};


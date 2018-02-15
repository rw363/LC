/*

 * [657] Judge Route Circle

 *

 * https://leetcode.com/problems/judge-route-circle/description/

 *

 * algorithms

 * Easy (68.56%)

 * Total Accepted:    57.5K

 * Total Submissions: 83.8K

 * Testcase Example:  '"UD"'

 *

 * 

 * Initially, there is a Robot at position (0, 0). Given a sequence of its

 * moves, judge if this robot makes a circle, which means it moves back to the

 * original place. 

 * 

 * 

 * 

 * The move sequence is represented by a string. And each move is represent by

 * a character. The valid robot moves are R (Right), L (Left), U (Up) and D

 * (down). The output should be true or false representing whether the robot

 * makes a circle.

 * 

 * 

 * Example 1:

 * 

 * Input: "UD"

 * Output: true

 * 

 * 

 * 

 * Example 2:

 * 

 * Input: "LL"

 * Output: false

 * 

 * 

 */

using namespace std;

class Solution {
public:
     bool judgeCircle(string moves) {
          int x = 0;
          int y = 0;
          for (auto m:moves)
          {
               if (m == 'U')
                    x++;
               else if (m == 'D')
                    x--;
               else if (m == 'L')
                    y++;
               else if (m == 'R')
                    y--;
          }
          if (x == 0 && y == 0)
               return true;
          return false;
     }
};


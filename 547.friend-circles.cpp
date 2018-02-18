/*

 * [547] Friend Circles

 *

 * https://leetcode.com/problems/friend-circles/description/

 *

 * algorithms

 * Medium (49.11%)

 * Total Accepted:    30.3K

 * Total Submissions: 61.6K

 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'

 *

 * 

 * There are N students in a class. Some of them are friends, while some are

 * not. Their friendship is transitive in nature. For example, if A is a direct

 * friend of B, and B is a direct friend of C, then A is an indirect friend of

 * C. And we defined a friend circle is a group of students who are direct or

 * indirect friends.

 * 

 * 

 * 

 * Given a N*N matrix M representing the friend relationship between students

 * in the class. If M[i][j] = 1, then the ith and jth students are direct

 * friends with each other, otherwise not. And you have to output the total

 * number of friend circles among all the students.

 * 

 * 

 * Example 1:

 * 

 * Input: 

 * [[1,1,0],

 * ⁠[1,1,0],

 * ⁠[0,0,1]]

 * Output: 2

 * Explanation:The 0th and 1st students are direct friends, so they are in a

 * friend circle. The 2nd student himself is in a friend circle. So return

 * 2.

 * 

 * 

 * 

 * Example 2:

 * 

 * Input: 

 * [[1,1,0],

 * ⁠[1,1,1],

 * ⁠[0,1,1]]

 * Output: 1

 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd

 * students are direct friends, so the 0th and 2nd students are indirect

 * friends. All of them are in the same friend circle, so return 1.

 * 

 * 

 * 

 * 

 * Note:

 * 

 * N is in range [1,200].

 * M[i][i] = 1 for all students.

 * If M[i][j] = 1, then M[j][i] = 1.

 * 

 * 

 */


using namespace std;

      // Smilar to Q200 Number of Islands
      // when we see a 1, mark all its friends and increase the counter.
      //      1) Use vector<bool> to track who is marked.  For i [0~size-1]: if (!marked[p], circle ++
      //      2) when marking if (!marked[other_p] && (M[p][other_p] == 1)), mark it and call marker recursively
      // we only need to scan row of M since the cols are just mirror of it to show the relationships

class Solution {
public:
     void mark(vector<vector<int>> &M, vector<bool> &marked, int thisP)
     {
          for (int otherP = 0; otherP < M.size(); otherP++)
          {
               if (!marked[otherP] && M[thisP][otherP] == 1)
               {
                    marked[otherP] = true;
                    mark(M, marked, otherP);
               }
          }
     }

     int findCircleNum(vector<vector<int>>& M) {
          int count = 0;
          if (M.empty())
               return count;
          vector<bool>marked(M.size(), false);
          for (int thisP = 0; thisP < M.size(); thisP++)
          {
               if (!marked[thisP])
               {
                    count++;
                    mark(M, marked, thisP);
               }
          }
          return count;
     }
};


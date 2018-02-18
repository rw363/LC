/*

 * [96] Unique Binary Search Trees

 *

 * https://leetcode.com/problems/unique-binary-search-trees/description/

 *

 * algorithms

 * Medium (41.76%)

 * Total Accepted:    142.5K

 * Total Submissions: 341.3K

 * Testcase Example:  '1'

 *

 * Given n, how many structurally unique BST's (binary search trees) that store

 * values 1...n?

 * 

 * 

 * For example,

 * Given n = 3, there are a total of 5 unique BST's.

 * 

 * 

 * ⁠  1         3     3      2      1

 * ⁠   \       /     /      / \      \

 * ⁠    3     2     1      1   3      2

 * ⁠   /     /       \                 \

 * ⁠  2     1         2                 3

 * 

 * 

 */

using namespace std;

class Solution {
public:
     int numTrees(int n) {
          vector<int>trees(n+1, 0);
          trees[0] = 1;
          for (int i = 1; i <=n; i++)
          {
               for (int j = 1; j <= i; j++)
               {
                    trees[i] += trees[j-1] * trees[i-j];
               }
          }
          return trees.back();
     }
};


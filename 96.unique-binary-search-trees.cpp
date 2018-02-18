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
        // DP with divid and conqure, ways of constructing the BST with numbers [1~n] = the comb of all BSTs using a starting root value from 1~n
        // After picking a starting number i [2~n] as the starting root, we can divide the rest numbers into left [1 ~ i-1] and right [i+1 ~ n] groups.  The # ways of BST with i as the starting rood = # ways ways to make left BST * # ways to make right group
        // ways[i] = sum(ways[1~ x-1] * ways [x+1 ~ i]) with x[1~i] = sum (ways[x-1] * ways[i-x]) for all x [1 ~ i].  Where ways[i] is the way to make try [1 ~ i].  i = 0 means that part is empty, which is allowed
        // use a vector<int> ways(n+1) to hold the ways.   Base cases:   ways[0] = 1 (empty tree), ways[1] = 1 (only one node)

        vector<int> counts(n+1, 0);
        counts[0] = counts[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int x = 1; x <=i; x++)
                counts[i] += counts[x-1] * counts[i-x];
        return counts.back();
    }
};

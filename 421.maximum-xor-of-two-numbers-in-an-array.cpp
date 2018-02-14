/*

 * [421] Maximum XOR of Two Numbers in an Array

 *

 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

 *

 * algorithms

 * Medium (47.67%)

 * Total Accepted:    20.2K

 * Total Submissions: 42.3K

 * Testcase Example:  '[3,10,5,25,2,8]'

 *

 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai <

 * 231.

 * 

 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

 * 

 * Could you do this in O(n) runtime?

 * 

 * Example:

 * 

 * Input: [3, 10, 5, 25, 2, 8]

 * 

 * Output: 28

 * 

 * Explanation: The maximum result is 5 ^ 25 = 28.

 * 

 * 

 */

using namespace std;

     // if A xor B = C, then A can be find by C xor B
     // bit by bit from MSB to LSB do below (i.e. i = sizeof(int)*8 ~ 0)
     // assume the biggest answer which is the existing ans << 1 + new bit = 1
     // store the possible bits from the input vector into a set.    possible.insert(n>>i);
     // check if it can be made by XOR the nums in the given array.  if (possible.find((ans|1) ^ p) != possible.end())

class Solution
{
public:
     int findMaximumXOR(vector<int>& nums)
     {
          int ans = 0;
          // do this bit by bit from MSB to LSB
          for (int i = 8*sizeof(int) - 1; i >= 0; i--)
          {
               // get ready for the next bit
               ans <<= 1;
               unordered_set<int>possible(nums.size());
               // prepare the list
               for (auto n:nums)
                    possible.insert(n>>i);

               // now try to find a match
               for (auto p:possible)
                    if (possible.find(p ^ (ans+1)) != possible.end())
                         // found
                         ans++;
          }

          return ans;
     }
};


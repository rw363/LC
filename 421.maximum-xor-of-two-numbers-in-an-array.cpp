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

class Solution
{
public:
     int findMaximumXOR(vector<int>& nums)
     {
          int ans = 0;
          for (int i = 31; i >= 0; i--)
          {
               ans <<= 1;
               unordered_set<int>possible(nums.size());
               for (auto n:nums)
               {
                    possible.insert(n>>i);
               }
               for (auto p:possible)
               {
                    if (possible.find(p ^ (ans+1)) != possible.end())
                    {
                         ans++;
                    }
               }
          }

          return ans;
     }
};


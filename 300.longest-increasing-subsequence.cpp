/*

 * [300] Longest Increasing Subsequence

 *

 * https://leetcode.com/problems/longest-increasing-subsequence/description/

 *

 * algorithms

 * Medium (38.85%)

 * Total Accepted:    112.5K

 * Total Submissions: 289.5K

 * Testcase Example:  '[10,9,2,5,3,7,101,18]'

 *

 * 

 * Given an unsorted array of integers, find the length of longest increasing

 * subsequence.

 * 

 * 

 * For example,

 * Given [10, 9, 2, 5, 3, 7, 101, 18],

 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length

 * is 4. Note that there may be more than one LIS combination, it is only

 * necessary for you to return the length.

 * 

 * 

 * Your algorithm should run in O(n2) complexity.

 * 

 * 

 * Follow up: Could you improve it to O(n log n) time complexity? 

 * 

 * Credits:Special thanks to @pbrother for adding this problem and creating all

 * test cases.

 */

using namespace std;

class Solution {
public:
     int lengthOfLIS(vector<int>& nums) {
          vector<int> tails;
          for (auto n:nums)
          {
               int i;
               for (i = 0; i < tails.size(); i++)
               {
                    if (tails[i] >= n)
                         break;
               }
               if (i >= tails.size())
                    tails.push_back(n);
               else
                    tails[i] = n;
          }
          return tails.size();
     }
};


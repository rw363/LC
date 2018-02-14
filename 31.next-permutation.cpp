/*

 * [31] Next Permutation

 *

 * https://leetcode.com/problems/next-permutation/description/

 *

 * algorithms

 * Medium (28.98%)

 * Total Accepted:    140.1K

 * Total Submissions: 483.2K

 * Testcase Example:  '[1,2,3]'

 *

 * 

 * Implement next permutation, which rearranges numbers into the

 * lexicographically next greater permutation of numbers.

 * 

 * 

 * If such arrangement is not possible, it must rearrange it as the lowest

 * possible order (ie, sorted in ascending order).

 * 

 * 

 * The replacement must be in-place, do not allocate extra memory.

 * 

 * 

 * Here are some examples. Inputs are in the left-hand column and its

 * corresponding outputs are in the right-hand column.

 * 1,2,3 → 1,3,2

 * 3,2,1 → 1,2,3

 * 1,1,5 → 1,5,1

 * 

 */

using namespace std;

class Solution {
public:
     void nextPermutation(vector<int>& nums) {
          // first starting from back to find where the decreasing order stops
          int n = nums.size();
          int bp;
          for (int i = n - 1; i >= 0; i--)
          {
               if (nums[i-1] < nums[i])
               {
                    bp = i;
                    break;
               }
          }
          if (bp == 0)
          {
               reverse(nums.begin(), nums.end());
               return;
          }
          // find the smallest bigger number
          for (int i = n - 1; i >= 0; i--)
          {
               if (nums[bp-1] < nums[i])
               {
                    swap(nums[bp-1], nums[i]);
                    break;
               }
          }
          reverse(nums.begin()+bp, nums.end());
     }
};


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

     // Find from the back where it stops reverse ordered, swap the next(i-1) with the biggest number, and make the back forward sorted
     // 1) search from the back, and skip the reversed sorted ones
     // 2) if cannot find (search ends when i == 0), reverse the input vector and done with it
     // 3) if find such breakpoint, find the smallest number that is bigger than then number before the breakpoint
     // 4) swap it with nums[i-1]
     // 5) reverse the back of the vector to make it forward sorted (so the resulting order is the smallest next one)

class Solution {
public:
     void nextPermutation(vector<int>& nums) {
          // first starting from back to find where the decreasing order stops
          int n = nums.size();
          if (n <= 1)
               return;
          int bp;
          for (int i = n - 1; i >= 0; i--)
          {
               if (nums[i-1] < nums[i])
               {
                    bp = i;
                    break;
               }
          }
          // check if i == 0, then reverse the string and end of it
          if (bp == 0)
          {
               reverse(nums.begin(), nums.end());
               return;
          }
          // find the smallest number that is bigger than the number nums[i-1] before break point
          for (int i = n - 1; i >= 0; i--)
          {
               if (nums[bp-1] < nums[i])
               {
                    // now swap the number (nums[i-1]) before breakpoint with the smallest number bigger than it
                    swap(nums[bp-1], nums[i]);
                    break;
               }
          }
          // reverse the back to make it increase order
          reverse(nums.begin()+bp, nums.end());
     }
};


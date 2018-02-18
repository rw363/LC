/*

 * [75] Sort Colors

 *

 * https://leetcode.com/problems/sort-colors/description/

 *

 * algorithms

 * Medium (38.76%)

 * Total Accepted:    205.9K

 * Total Submissions: 531.2K

 * Testcase Example:  '[0]'

 *

 * 

 * Given an array with n objects colored red, white or blue, sort them so that

 * objects of the same color are adjacent, with the colors in the order red,

 * white and blue.

 * 

 * 

 * 

 * Here, we will use the integers 0, 1, and 2 to represent the color red,

 * white, and blue respectively.

 * 

 * 

 * 

 * Note:

 * You are not suppose to use the library's sort function for this problem.

 * 

 * 

 * click to show follow up.

 * 

 * 

 * Follow up:

 * A rather straight forward solution is a two-pass algorithm using counting

 * sort.

 * First, iterate the array counting number of 0's, 1's, and 2's, then

 * overwrite array with total number of 0's, then 1's and followed by 2's.

 * Could you come up with an one-pass algorithm using only constant space?

 * 

 * 

 */

using namespace std;

     // almost like sorting. r_i = 0, b_i = nums.size() - 1.
     // While i [0~b_i]. NOTE: b_i is a moving target
     //      1) move all 0s to the begining swap(nums[i++], nums[r_i++])
     //      2) move all 2s to the end swap(nums[i], nums[b_i--]).  NOTE: moving blue to end does not increase i because a 2 can be swapped to the back so we need to check again
     //      3) else i++ to skip all 1s

class Solution {
public:
     void sortColors(vector<int>& nums){
          if (nums.empty())
               return;
          int n = nums.size();
          int r_i = 0;
          int b_i = n - 1;
          for (int i = 0; i <= b_i; i++)
          {
               if (nums[i] == 0)
                    swap(nums[i], nums[r_i++]);
               else if (nums[i] == 2)
                    swap(nums[i--], nums[b_i--]);
          }
     }
};


/*

 * [33] Search in Rotated Sorted Array

 *

 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/

 *

 * algorithms

 * Medium (32.03%)

 * Total Accepted:    232.4K

 * Total Submissions: 725.4K

 * Testcase Example:  '[]\n5'

 *

 * Suppose an array sorted in ascending order is rotated at some pivot unknown

 * to you beforehand.

 * 

 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 * 

 * You are given a target value to search. If found in the array return its

 * index, otherwise return -1.

 * 

 * You may assume no duplicate exists in the array.

 */

using namespace std;

     // Binary search in the half that is in order.  Check if target == anyone of [mid, l, r]
     // After rotate the original sorted ascending array. The array is still in ascending order except the point where the rotation happended.  If mid > left, then the left side is in order, otherwise the right side is in order
     // Check if the target is in the range of the part that in order.

class Solution {
public:
     int search(vector<int>& nums, int target)
     {
          if (nums.empty())
               return -1;
          int l = 0;
          int r = nums.size() - 1;
          while (l <= r)
          {
               int mid = l + (r-l)/2;
               if (nums[mid] == target)
                    return mid;
               if (nums[l] == target)
                    return l;
               if (nums[r] == target)
                    return r;
               // if left in order
               if (nums[l] < nums[mid])
               {
                    if (nums[l] < target && target < nums[mid])
                         r = mid - 1;
                    else
                         l = mid + 1;
               }
               // right in order
               else
               {
                    if (nums[mid] < target && target < nums[r])
                         l = mid + 1;
                    else
                         r = mid - 1;
               }
          }
          printf("l = %d r = %d", l, r);
          return -1;
     }
};


/*

 * [34] Search for a Range

 *

 * https://leetcode.com/problems/search-for-a-range/description/

 *

 * algorithms

 * Medium (31.59%)

 * Total Accepted:    175.3K

 * Total Submissions: 554.8K

 * Testcase Example:  '[5,7,7,8,8,10]\n8'

 *

 * Given an array of integers sorted in ascending order, find the starting and

 * ending position of a given target value.

 * 

 * Your algorithm's runtime complexity must be in the order of O(log n).

 * 

 * If the target is not found in the array, return [-1, -1].

 * 

 * 

 * For example,

 * Given [5, 7, 7, 8, 8, 10] and target value 8,

 * return [3, 4].

 * 

 */

using namespace std;

     // CHECK NULL INPUT FIRST!!!
     // Binary search, need to find the value twice, at both ends. So we need to biases
     // while (l < r)  Note: it is NOT " <= "
     //      1) when bias to find the left end (min index of the target), i.e. either >= is not what we want. But we cannot move over it since it can be the last match, so r = mid, not mid - 1
     //              a) if num[i] >= target then r = mid, otherwise l = mid + 1;
     //              b) at the end of the loop if we find any nums[l] == target
     //      2) when bias to find the right end (max index of the target):   either <= is not what we want
     //              a) we already know l = left end, so just need to reset right to nums.size() -1 to find the right end
     //              b) mid = l + (r-l)/2 + 1 <---- to baise to right
     //              b) if num[i] <= target then l = mid, otherwise r = mid - 1;

class Solution {
public:
     vector<int> searchRange(vector<int>& nums, int target) {
          vector<int> ans(2, -1);
          if (nums.empty())
               return ans;
          int l = 0;
          int r = nums.size()-1;
          while(l < r)
          {
               int mid = l + (r-l)/2;
               if (nums[mid] >= target)
                    r = mid;
               else
                    l = mid + 1;
          }
          if (nums[l] != target)
               return ans;
          ans[0] = l;
          r = nums.size()-1;
          while(l < r)
          {
               int mid = l + (r-l)/2 + 1;
               if (nums[mid] <= target)
                    l = mid;
               else
                    r = mid - 1;
          }
          ans[1] = r;
          return ans;
     }
};


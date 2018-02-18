/*

 * [215] Kth Largest Element in an Array

 *

 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/

 *

 * algorithms

 * Medium (40.36%)

 * Total Accepted:    188K

 * Total Submissions: 465.9K

 * Testcase Example:  '[1]\n1'

 *

 * Find the kth largest element in an unsorted array. Note that it is the kth

 * largest element in the sorted order, not the kth distinct element.

 * 

 * For example,

 * Given [3,2,1,5,6,4] and k = 2, return 5.

 * 

 * 

 * Note: 

 * You may assume k is always valid, 1 ≤ k ≤ array's length.

 * 

 * Credits:Special thanks to @mithmatt for adding this problem and creating all

 * test cases.

 */

using namespace std;

class Solution {
public:
     int partition (vector<int> &nums, int start, int end)
     {
          swap(nums[end], nums[start + rand()%(end-start+1)]);
          int p = nums[end];
          int w_i = start;
          for (int i = start; i < end; i++)
          {
               if (nums[i] > p)
               {
                    swap(nums[i], nums[w_i++]);
               }
          }
          swap(nums[end], nums[w_i]);
          return w_i;
     }

     int findKthLargest(vector<int>& nums, int k) {
          int n = nums.size();
          if (n < k)
               return -1;
          int start = 0;
          int end = n - 1;
          while(start <= end)
          {
               int p_i = partition(nums, start, end);
               if (p_i+1 == k)
                    return nums[p_i];
               else if (p_i+1 > k)
                    end = p_i - 1;
               else
                    start = p_i + 1;
          }
          return -1;
     }
};


/*

 * [560] Subarray Sum Equals K

 *

 * https://leetcode.com/problems/subarray-sum-equals-k/description/

 *

 * algorithms

 * Medium (40.38%)

 * Total Accepted:    28.2K

 * Total Submissions: 69.8K

 * Testcase Example:  '[1,1,1]\n2'

 *

 * Given an array of integers and an integer k, you need to find the total

 * number of continuous subarrays whose sum equals to k.

 * 

 * Example 1:

 * 

 * Input:nums = [1,1,1], k = 2

 * Output: 2

 * 

 * 

 * 

 * Note:

 * 

 * The length of the array is in range [1, 20,000].

 * The range of numbers in the array is [-1000, 1000] and the range of the

 * integer k is [-1e7, 1e7].

 * 

 * 

 */

using namespace std;

class Solution {
public:
     int subarraySum(vector<int>& nums, int k) {
          int count = 0;
          unordered_map<int, int>map;
          map.emplace(0,1);
          int sum = 0;
          for (auto n:nums)
          {
               sum += n;
               if (map.find(sum-k) != map.end())
               {
                    count += map[sum-k];
               }
               map[sum]++;
          }
          return count;
     }
};


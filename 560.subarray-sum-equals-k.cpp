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
          // The numbers must appreared continuously in the input vector. Use DP, similar to finding the prefect squre. Map key: current sum, value: how many times the same same appeared
          // W need to find sum [0 ~ current] = sum [0 ~ x] + sum [x ~ current], where sum[x ~ current] == target
          //      1) So, if we can find a pre existing sum[0 ~ x] such that sum [0~x] == sum [0 ~ current] - target, then ans += map[sum-k] <--- # ways of getting sum[0 ~ x]
          //      2) the location of x does not matter:  sum[0~100] = sum[0~1] + sum[1~100] = sum[0~55] + sum[55~100], both can be a valid answer
          //      3) This pre-X sum might not always be 1 where the pre-pre sum are 0:   sum(-1 1 1 2) = sum(1 2), so we need a map to track the pre-X sums and the frequency of making them possible
          //      4) similar to finding the prefect squre, the first member of preX sum map shall be (0,1) means there is 1 way to find a sum of 0 by including nothing

          int total = 0;
          // key: current sum, value: how many times the same same appeared
          unordered_map<int, int> counts;
          // one way to make a target sum of 0, but including nothing
          counts.emplace(0, 1);
          // sum all numbers to get sum [0~current]
          int sum = 0;
          for (auto n : nums)
          {
               sum += n;
               //if can find a presum [0~x] == sum [0~current] - target, then target can be found as sum [x~current]
               if (counts.find(sum - k) != counts.end())
               {
                    total += counts[sum - k];
               }
               // record this sum;
               counts[sum]++;
          }

          return total;
     }
};

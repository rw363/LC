/*

 * [1] Two Sum

 *

 * https://leetcode.com/problems/two-sum/description/

 *

 * algorithms

 * Easy (37.15%)

 * Total Accepted:    793.2K

 * Total Submissions: 2.1M

 * Testcase Example:  '[3,2,4]\n6'

 *

 * Given an array of integers, return indices of the two numbers such that they

 * add up to a specific target.

 * 

 * You may assume that each input would have exactly one solution, and you may

 * not use the same element twice.

 * 

 * 

 * Example:

 * 

 * Given nums = [2, 7, 11, 15], target = 9,

 * 

 * Because nums[0] + nums[1] = 2 + 7 = 9,

 * return [0, 1].

 * 

 * 

 */

using namespace std;

class Solution {
public:
     vector<int> twoSum(vector<int>& nums, int target) {
          vector<int>ans;
          if (nums.empty())
               return ans;
          unordered_map<int, int>map;
          for (int i = 0; i < nums.size(); i++)
          {
               if (map.find(target - nums[i]) != map.end())
               {
                    ans.push_back(map[target-nums[i]]);
                    ans.push_back(i);
                    break;
               }
               map.emplace(nums[i], i);
          }
          return ans;
     }
};


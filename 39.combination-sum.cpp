/*

 * [39] Combination Sum

 *

 * https://leetcode.com/problems/combination-sum/description/

 *

 * algorithms

 * Medium (40.74%)

 * Total Accepted:    202.4K

 * Total Submissions: 496.8K

 * Testcase Example:  '[2,3,6,7]\n7'

 *

 * 

 * Given a set of candidate numbers (C) (without duplicates) and a target

 * number (T), find all unique combinations in C where the candidate numbers

 * sums to T. 

 * 

 * 

 * The same repeated number may be chosen from C unlimited number of times.

 * 

 * 

 * Note:

 * 

 * All numbers (including target) will be positive integers.

 * The solution set must not contain duplicate combinations.

 * 

 * 

 * 

 * 

 * For example, given candidate set [2, 3, 6, 7] and target 7, 

 * A solution set is: 

 * 

 * [

 * ⁠ [7],

 * ⁠ [2, 2, 3]

 * ]

 * 

 * 

 */

using namespace std;

class Solution {
public:
     void backtrack(vector<vector<int>> &ans, vector<int> &holder, vector<int> &nums, int start, int target)
     {
          if (target < 0)
               return;
          if (target == 0)
          {
               ans.push_back(holder);
               return;
          }
          for (int i = start; i < nums.size(); i++)
          {
               holder.push_back(nums[i]);
               backtrack(ans, holder, nums, i, target - nums[i]);
               holder.pop_back();
          }
     }

     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>>ans;
          vector<int> holder;
          if (candidates.empty())
               return ans;
          backtrack(ans, holder, candidates, 0, target);
          return ans;
     }
};


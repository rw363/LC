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
     // backtrack: the input does not including duplicates, but the KEY is that we can resume the same number again and again!
     //      1) for (int i = start; i < candidates.size(); i++)
     //              { target -= current number; start = i (not i +1)} <----  because we can reuse same number ulimited times, we will start finding new target starting with the same index
     //      2) because we can reuse the same number, so we cannot start > size as return condidation. therefore we use target < 0 as reuse condidition assuming all inputs are possible numbers

class Solution {
public:
     void backtrack(vector<vector<int>> &ans, vector<int> &holder, vector<int> &nums, int start, int target)
     {
          // because we can reuse same number ulimited times, we will start finding new target starting with the same index
          // so we cannot use start > size to exist, but rather use target < 0 as return conditition, assuming all possible input numbers
          if (target < 0)
               return;
          if (target == 0)
          {
               ans.push_back(holder);
               return;
          }
          // do loop, with reuse the same number
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


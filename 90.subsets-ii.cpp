/*

 * [90] Subsets II

 *

 * https://leetcode.com/problems/subsets-ii/description/

 *

 * algorithms

 * Medium (37.83%)

 * Total Accepted:    137.6K

 * Total Submissions: 363.7K

 * Testcase Example:  '[1,2,2]'

 *

 * 

 * Given a collection of integers that might contain duplicates, nums, return

 * all possible subsets (the power set).

 * 

 * Note: The solution set must not contain duplicate subsets.

 * 

 * 

 * For example,

 * If nums = [1,2,2], a solution is:

 * 

 * 

 * 

 * [

 * ⁠ [2],

 * ⁠ [1],

 * ⁠ [1,2,2],

 * ⁠ [2,2],

 * ⁠ [1,2],

 * ⁠ []

 * ]

 * 

 */
using namespace std;

class Solution {
public:
     void backtrack(vector<vector<int>> &ans, vector<int> &holder, vector<int> &nums, int start)
     {
          ans.push_back(holder);
          for (int i = start; i < nums.size(); i++)
          {
               if (i > start && nums[i] == nums[i-1])
                    continue;
               holder.push_back(nums[i]);
               backtrack(ans, holder, nums, i+1);
               holder.pop_back();
          }
     }
     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          vector<vector<int>> ans;
          vector<int> holder;
          sort(nums.begin(), nums.end());
          backtrack(ans, holder, nums, 0);
          return ans;
     }
};


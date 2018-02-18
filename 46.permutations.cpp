/*

 * [46] Permutations

 *

 * https://leetcode.com/problems/permutations/description/

 *

 * algorithms

 * Medium (46.43%)

 * Total Accepted:    215.9K

 * Total Submissions: 464.9K

 * Testcase Example:  '[1,2,3]'

 *

 * 

 * Given a collection of distinct numbers, return all possible permutations.

 * 

 * 

 * 

 * For example,

 * [1,2,3] have the following permutations:

 * 

 * [

 * ⁠ [1,2,3],

 * ⁠ [1,3,2],

 * ⁠ [2,1,3],

 * ⁠ [2,3,1],

 * ⁠ [3,1,2],

 * ⁠ [3,2,1]

 * ]

 * 

 * 

 */

using namespace std;

     // Backtrack.  // Note we need to include all numbers everytime, but different from the one already in the holder (if cannot find)
     // input vector contains no duplicate numbers, no need to check if nums[i] == nums[i - 1]
     // have to use all numbers, so push holder into answer when holder.size() == nums.size()

class Solution {
public:
     void backtrack (vector<vector<int>> &ans, vector<int> &holder, vector<int> &nums)
     {
          if (holder.size() == nums.size())
          {
               ans.push_back(holder);
               return;
          }

          for (int i = 0; i < nums.size(); i++)
          {
               if (find(holder.begin(), holder.end(), nums[i]) != holder.end())
                    continue;
               holder.push_back(nums[i]);
               backtrack(ans, holder, nums);
               holder.pop_back();
          }
     }

     vector<vector<int>> permute(vector<int>& nums) {
          vector<vector<int>> ans;
          vector<int> holder;
          backtrack(ans, holder, nums);
          return ans;
     }
};


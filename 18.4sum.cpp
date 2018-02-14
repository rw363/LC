/*

 * [18] 4Sum

 *

 * https://leetcode.com/problems/4sum/description/

 *

 * algorithms

 * Medium (27.39%)

 * Total Accepted:    146.3K

 * Total Submissions: 533.8K

 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'

 *

 * Given an array S of n integers, are there elements a, b, c, and d in S such

 * that a + b + c + d = target? Find all unique quadruplets in the array which

 * gives the sum of target.

 * 

 * Note: The solution set must not contain duplicate quadruplets.

 * 

 * 

 * 

 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

 * 

 * A solution set is:

 * [

 * ⁠ [-1,  0, 0, 1],

 * ⁠ [-2, -1, 1, 2],

 * ⁠ [-2,  0, 0, 2]

 * ]

 * 

 */
using namespace std;

     //general solution for N Sum = target problems
     //when n == 2 search from both ends while(l<r) find nums[l] + nums[r] == target
     //when n > 2 do backtrack with start = i+1, target = target - nums[i], n = n-1.
     //to avoid duplicate sets, skip if (i > start && nums[i] == nums[i-1])

class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &holder, vector<int> &nums, int target, int start, int n)
    {
        if (n == 2)
        {
            int l = start;
            int r = nums.size() - 1;
            while(l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum == target)
                {
                    vector<int> tmp = holder;
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    ans.push_back(tmp);
                    while(l < r && nums[l++] == nums[l]);
                    while(l < r && nums[r--] == nums[r]);
                }
                else if (sum > target)
                    r--;
                else
                    l++;
            }
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i-1])
                continue;
            holder.push_back(nums[i]);
            backtrack(ans, holder, nums, target - nums[i], i + 1, n - 1);
            holder.pop_back();
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> holder;
        sort(nums.begin(), nums.end());
        backtrack(ans, holder, nums, target, 0, 4);
        return ans;
    }
};

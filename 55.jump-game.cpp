/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (29.59%)
 * Total Accepted:    153K
 * Total Submissions: 517K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * 
 * Each element in the array represents your maximum jump length at that
 * position. 
 * 
 * 
 * Determine if you are able to reach the last index.
 * 
 * 
 * 
 * For example:
 * A = [2,3,1,1,4], return true.
 * 
 * 
 * A = [3,2,1,0,4], return false.
 * 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
	for (int i = 0; i <= maxJump; i++)
	{
		maxJump = max(maxJump, i+nums[i]);
		if (maxJump >= nums.size()-1)
			return true;
	}
	return false;
    }
};

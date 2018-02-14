/*

 * [494] Target Sum

 *

 * https://leetcode.com/problems/target-sum/description/

 *

 * algorithms

 * Medium (43.81%)

 * Total Accepted:    44.2K

 * Total Submissions: 100.9K

 * Testcase Example:  '[1,1,1,1,1]\n3'

 *

 * 

 * You are given a list of non-negative integers, a1, a2, ..., an, and a

 * target, S. Now you have 2 symbols + and -. For each integer, you should

 * choose one from + and - as its new symbol.

 * ⁠

 * 

 * Find out how many ways to assign symbols to make sum of integers equal to

 * target S.  

 * 

 * 

 * Example 1:

 * 

 * Input: nums is [1, 1, 1, 1, 1], S is 3. 

 * Output: 5

 * Explanation: 

 * 

 * -1+1+1+1+1 = 3

 * +1-1+1+1+1 = 3

 * +1+1-1+1+1 = 3

 * +1+1+1-1+1 = 3

 * +1+1+1+1-1 = 3

 * 

 * There are 5 ways to assign symbols to make the sum of nums be target 3.

 * 

 * 

 * 

 * Note:

 * 

 * The length of the given array is positive and will not exceed 20. 

 * The sum of elements in the given array will not exceed 1000.

 * Your output answer is guaranteed to be fitted in a 32-bit integer.

 * 

 * 

 */

using namespace std;

class Solution {
private:
    // <target, <start index, # of possible>>
    /*
    unordered_map<int, unordered_map<int, int>> hisotry;
    */
public:
    /*
    // Backtrack with target sum, use DP to speed up <target, <start index, # of possible>>
    // start with 0 and move to the end of input nums
    //      if start reaches the end (nums.size() since the check is done after start + 1), return if target == 0
    //      if the the start index and target sum has been calculated, return the DP
    //      try both + and -, with start + 1, target S -= current nums[start]

    int helper (vector<int> &nums, int target, int start)
    {
        // if reaches the end
        if (start == nums.size())
        {
            // if find the target
            return (int) (target == 0);
        }

        // check if we already have this in the memory
        if ( (hisotry.find(target) == hisotry.end()) && (hisotry[target].find(start) == hisotry[target].end()))
        {
            // now check all comb of the rest
            int tmp = helper(nums, target +w nums[start], start + 1) + helper(nums, target - nums[start], start + 1);
            if (hisotry.find(target)  != hisotry.end())
            {
                hisotry[target].emplace(start, tmp);
            }
            else
            {
                unordered_map<int, int> tmp_map;
                tmp_map.emplace(start, tmp);
                hisotry.emplace(target, tmp_map);
            }
        }
        return hisotry[target][start];
    }
    */

    int findTargetSumWays(vector<int>& nums, int S) {
        // Similar to Q 416 Partition Equal Subset Sum. Use knapsack method. if sum(nums) < S, return 0
        // Target S can be divided into two groups P and N, where sum(P) - sum (N) = S
        // add sum(nums) to both sides we have 2 * sum (P) = S + sum(nums) -> sum(P) = (S + sum(nums)) /2, where S + sum(nums) must be even
        // use DP like buy or sell stock: scan the input vector and we either add the number into P or not
        // with given num, can we get P from n? calculate all i [P ~ n] DP[i] backward, where i = target, i >= num, i--
        // given DP[i] = possible wasys to nums[i], then DP[i] = DP[i] + DP[i-n] (from i-n + n = i)
        // return DP[P]

        int P = 0;
        for (auto n:nums)
            P += n;
        if (P < S) return 0;
        if ((P + S) % 2 != 0) return 0;
        P = (P+S) / 2;

        vector<int> possible (P+1, 0);
        // 1 ways to get 0 from 0 numbers
        possible[0] = 1;

        for (auto n:nums)
        {
            // possible to get S from n?
            for (int i = P; i >= n; i--)
            {
                // pick or no pick
                possible[i] = possible[i] + possible[i-n];
            }
        }

        return possible[P];


        /*
        return helper(nums, S, 0);
        */
    }
};


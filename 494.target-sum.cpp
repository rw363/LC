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
public:
     int backtrack(vector<int> &nums, int S, int start, unordered_map<int, unordered_map<int, int>> &history)
     {
          int count = 0;
          if (start == nums.size())
               return (int) (S == 0);

          if (history.find(S) != history.end() && history[S].find(start) != history[S].end())
               return history[S][start];
          count += backtrack(nums, S + nums[start], start+1, history);
          count += backtrack(nums, S - nums[start], start+1, history);
          if (history.find(S) != history.end())
               history[S].emplace(start, count);
          else
          {
               unordered_map<int, int> tmp;
               tmp.emplace(start, count);
               history.emplace(S, tmp);
          }
          return count;
     }

     int findTargetSumWays(vector<int>& nums, int S) {
          // unordered_map<int, unordered_map<int, int>> history;
          // return backtrack(nums, S, 0, history);
          int count = 0;
          int P = 0;
          for (auto n:nums)
               P += n;
          if (P < S || (P+S) % 2 != 0)
               return count;
          P = (P+S) / 2;
          vector<int> ways(P+1, 0);
          ways[0] = 1;
          for (auto n:nums)
               for (int i = P; i >= n; i--)
                    ways[i] = ways[i] + ways[i-n];
          return ways.back();

     }
};


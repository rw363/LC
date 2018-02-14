/*

 * [15] 3Sum


 *

 * https://leetcode.com/problems/3sum/description/

 *

 * algorithms

 * Medium (21.82%)

 * Total Accepted:    291.9K

 * Total Submissions: 1.3M

 * Testcase Example:  '[-1,0,1,2,-1,-4]'

 *

 * Given an array S of n integers, are there elements a, b, c in S such that a

 * + b + c = 0? Find all unique triplets in the array which gives the sum of

 * zero.

 * 

 * Note: The solution set must not contain duplicate triplets.

 * 

 * 

 * For example, given array S = [-1, 0, 1, 2, -1, -4],

 * 

 * A solution set is:

 * [

 * ⁠ [-1, 0, 1],

 * ⁠ [-1, -1, 2]

 * ]

 * 

 */
using namespace std;
     // vector size must >= 3 or return nothing
     // first, sort the input vector
     // for i [0~size-1] skip the repeated number with if (i != 0 && nums[i] == nums[i-1]) continue;
     // binary search [i+1~size-1] for nums[l] + nums[r] = -nums[i]
     // when find a match during search, skip the repeated ones while(l < r && nums[l++] == nums[l]); and continue search
class Solution {
public:
     vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int>> ans;
     // key: sum, value: index
     if (nums.size() < 3)
          return ans;
     unordered_map<int, int>map;
     sort(nums.begin(), nums.end());
     for (int i = 0; i < nums.size(); i++)
     {
          if (i > 0 && nums[i] == nums[i-1])
               continue;
          int l = i+1;
          int r = nums.size() - 1;
          while(l < r)
          {
               if (nums[l] + nums[r] == -nums[i])
               {
                    vector<int> holder = {nums[i], nums[l], nums[r]};
                    ans.push_back(holder);
                    while(l<r && nums[l++] == nums[l]);
                    while(l<r && nums[r--] == nums[r]);
               }
               else if (nums[l] + nums[r] > -nums[i])
                    r--;
               else
                    l++;
          }
     }
     return ans;
    }
};


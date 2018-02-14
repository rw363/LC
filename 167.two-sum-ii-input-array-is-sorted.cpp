/*

 * [167] Two Sum II - Input array is sorted

 *

 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

 *

 * algorithms

 * Easy (47.24%)

 * Total Accepted:    122.3K

 * Total Submissions: 258.9K

 * Testcase Example:  '[2,3,4]\n6'

 *

 * Given an array of integers that is already sorted in ascending order, find

 * two numbers such that they add up to a specific target number.

 * 

 * The function twoSum should return indices of the two numbers such that they

 * add up to the target, where index1 must be less than index2. Please note

 * that your returned answers (both index1 and index2) are not zero-based.

 * 

 * You may assume that each input would have exactly one solution and you may

 * not use the same element twice.

 * 

 * 

 * Input: numbers={2, 7, 11, 15}, target=9

 * Output: index1=1, index2=2

 * 

 */

using namespace std;

// Similar to binary search (but it is not!). O(n): search both numbers at the same time num[l] + num[r] == target
class Solution {
public:
     vector<int> twoSum(vector<int>& numbers, int target) {
          vector<int> ans;
          int l = 0;
          int r = numbers.size() - 1;
          while(l < r)
          {
               int sum = numbers[l] + numbers[r];
               if (sum == target)
               {
                    ans.push_back(l+1);
                    ans.push_back(r+1);
                    break;
               }
               else if (sum > target)
                    r--;
               else
                    l++;
          }
          return ans;
     }
};


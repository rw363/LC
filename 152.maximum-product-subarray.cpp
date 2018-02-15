/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (26.55%)
 * Total Accepted:    129.3K
 * Total Submissions: 487.1K
 * Testcase Example:  '[-2]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest product.
 * 
 * 
 * 
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 * 
 */

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = 1;
        int minN = 1;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(maxP, minN);
            maxP = max(nums[i], nums[i] * maxP);
            minN = min(nums[i], nums[i] * minN);
            ans = max(ans, maxP);
        }
        return ans;
    }
};

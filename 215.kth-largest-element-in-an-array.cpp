/*

 * [215] Kth Largest Element in an Array

 *

 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/

 *

 * algorithms

 * Medium (40.36%)

 * Total Accepted:    188K

 * Total Submissions: 465.9K

 * Testcase Example:  '[1]\n1'

 *

 * Find the kth largest element in an unsorted array. Note that it is the kth

 * largest element in the sorted order, not the kth distinct element.

 * 

 * For example,

 * Given [3,2,1,5,6,4] and k = 2, return 5.

 * 

 * 

 * Note: 

 * You may assume k is always valid, 1 ≤ k ≤ array's length.

 * 

 * Credits:Special thanks to @mithmatt for adding this problem and creating all

 * test cases.

 */

using namespace std;

class Solution {
public:
    // METHOD1: sort it and find the kth largest
    // METHOD2:
    //          1) modifiy the quick sort and only sort the part that contains the kth largest number. To find the kth eaiser, sort in decreasing order.   if (nums[i] > pivot) swap(nums[i], nums[w_i++]);
    //          2) instead of calling quicksort recursively if (start < end), we only partition the part contains kth node with while (start < end)
    //                  a) Since p_i is 0 based, there is p_i + 1 numbers less than the number at p_i:  if (p_i + 1 == k) return nums[p_i];
    //                  b) if we do not have enough small numbers, the target number is at the bigger part.  Since the value of p_i is a abosulte value, no need offset      else if (p_i + 1 < k)  start = p_i + 1;
    //                  c) else     end = p_i - 1;
    //          3) if we finished the while loop before finding the target, return -1

    int partition(vector<int> &nums, int start, int end)
    {
        int rpi = start + rand()%(end-start+1);
        int pivot = nums[rpi];
        swap(nums[rpi], nums[end]);

        int w_i = start;
        for (int i = start; i < end; i++)
        {
            if (nums[i] > pivot)
                swap(nums[i], nums[w_i++]);
        }
        swap(nums[w_i], nums[end]);
        return w_i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end)
        {
            int p_i = partition(nums, start, end);
            // since p_i is 0 based, there is p_i + 1 numbers less than the number at p_i
            if (p_i + 1 == k)
                return nums[p_i];
            // if we do not have enough small numbers, the target number is at the bigger part
            // since the value of p_i is a abosulte value, no need offset
            else if (p_i + 1 < k)
                start = p_i + 1;
            else
                end = p_i - 1;
        }
        // if reaches here, we can not find it
        return -1;
    }

    /*
    void quicksort(vector<int> &num, int start, int end)
    {
        if (start < end)
        {
            int p_i = parition(nums, start, end);
            quicksort(nums, start, p_i - 1);
            quicksort(nums, p_i + 1, end);
        }
    }
    */
};

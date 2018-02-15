/*
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (45.39%)
 * Total Accepted:    53.8K
 * Total Submissions: 118.4K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 */

using namespace std;

//     Note: we dont know whose bigger between matrix[0][100] and matrix[0][100]!
//     but we still can do binary search in the entire matrix (not only row or col).
//     Scan row and col and count if more than K numbers smaller than mid, h = mid -1; otherwise, l = mid + 1
//          1) the smallest number of any sub-matrix is at (0, 0)
//          2) the biggest number of any sub-matrix is at (n-1, m-1)
//          3) mid = l+(r-l)/2
//      while (l <= h), for i [0~n-1], for j [0~m-1], move until matrix[i][j] > mid then break and count += j

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty())
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int l = matrix[0][0];
        int h = matrix[row-1][col-1];
        while(l <= h)
        {
            int count = 0;
            int mid = l + (h-l) / 2;
            for (int i = 0; i < row; i++)
            {
                int j;
                for (j = 0; j < col; j++)
                {
                    if (matrix[i][j] > mid)
                        break;
                }
                count += j;
                if (count > k)
                    break;
            }
            // if don't have enough small numbers, move lower boundary up to include more small numbers
            if (count < k)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l;
    }
};

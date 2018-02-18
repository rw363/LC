/*

 * [105] Construct Binary Tree from Preorder and Inorder Traversal

 *

 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

 *

 * algorithms

 * Medium (33.34%)

 * Total Accepted:    128.2K

 * Total Submissions: 384.6K

 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'

 *

 * Given preorder and inorder traversal of a tree, construct the binary tree.

 * 

 * Note:

 * You may assume that duplicates do not exist in the tree.

 * 

 * For example, given

 * 

 * 

 * preorder = [3,9,20,15,7]

 * inorder = [9,3,15,20,7]

 * 

 * Return the following binary tree:

 * 

 * 

 * ⁠   3

 * ⁠  / \

 * ⁠ 9  20

 * ⁠   /  \

 * ⁠  15   7

 * 

 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using namespace std;

     // 1) The first node in preoder is the root
     // 2) The nodes before root in inorder is the left child, and the nodes after in on the right child
     // So cut into half and divide & conqure.  TreeNode* helper(vector<int> &preorder, vector<int> inorder, int pStart, int pEnd, int iStart, int iEnd).
     //      if pstart > pend OR istart > iend, return NULL;
     //      left: [pstart+1 ~ pend],                   [istart ~ i-1]
     //      right: [pstart+(i+1-istart)  ~ pend]       [i+1 ~ iend]

class Solution {
public:
     TreeNode* helper(vector<int> &preorder, int pStart, vector<int> &inorder, int iStart, int iEnd)
     {
          // first find the index of root in inorder ;
          if (iStart > iEnd)
               return NULL;
          TreeNode* root = new TreeNode(preorder[pStart]);
          int i;
          for (i = iStart; i <= iEnd; i++)
          {
               if (inorder[i] == preorder[pStart])
                    break;
          }
          // now cut them into half and connect both left and right child to root
          root->left = helper(preorder, pStart+1, inorder, iStart, i-1);
          root->right = helper(preorder, pStart+1+(i-iStart), inorder, i+1, iEnd);
          return root;
     }
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          return helper(preorder, 0, inorder, 0, inorder.size()-1);
     }
};


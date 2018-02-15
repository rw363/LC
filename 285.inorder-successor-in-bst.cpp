/*

 * [285] Inorder Successor in BST

 *

 * https://leetcode.com/problems/inorder-successor-in-bst/description/

 *

 * algorithms

 * Medium (36.04%)

 * Total Accepted:    52.7K

 * Total Submissions: 146.3K

 * Testcase Example:  '[0]\nnode with value 0'

 *

 * 

 * Given a binary search tree and a node in it, find the in-order successor of

 * that node in the BST.

 * 

 * 

 * 

 * Note: If the given node has no in-order successor in the tree, return null.

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



class Solution {
public:
     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
          if (!root)
               return root;
          if (root->val <= p->val)
               return inorderSuccessor(root->right, p);

          TreeNode* node = inorderSuccessor(root->left, p);
          if (!node)
               return root;
          else
               return node;
     }
};


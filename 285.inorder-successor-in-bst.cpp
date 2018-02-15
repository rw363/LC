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

     // smilar to inorder travel
     // if we need to find successor (the next one during inorder travel), which is the most left leaf of the right side branch.
     // if the current node is small or equal, move to its right; otherwise go left, and if we got null return (cant go further), return the current
     // if we need to find the presuccessor, that is the right leaf of the left branch (mirror of the below logic)
     //      1) check for NULL root
     //      2) if the current node is small, we move to the right and return its result
     //      3) else move to left and check the return result, if can find, return it, if got NULL (cannot go further), return the current root

class Solution {
public:
     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
          if (!root)
               return root;
          // if the target node is the the current node, we go to the right side and find the left leave
          // if the target node is bigger than the current node, we go to right side to find it
          if (root->val <= p->val)
               return inorderSuccessor(root->right, p);

          // if the target node is bigger than the current node, we are on the right side and trying to reach the left leave
          TreeNode* node = inorderSuccessor(root->left, p);
          // if there is no left child, this is the most left leave
          if (!node)
               return root;
          // this is the return from the most left leave, just pass it to upper level
          else
               return node;
     }
};


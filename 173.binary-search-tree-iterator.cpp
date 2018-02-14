/*

 * [173] Binary Search Tree Iterator

 *

 * https://leetcode.com/problems/binary-search-tree-iterator/description/

 *

 * algorithms

 * Medium (43.12%)

 * Total Accepted:    119.4K

 * Total Submissions: 277K

 * Testcase Example:  '[]'

 *

 * Implement an iterator over a binary search tree (BST). Your iterator will be

 * initialized with the root node of a BST.

 * 

 * Calling next() will return the next smallest number in the BST.

 * 

 * Note: next() and hasNext() should run in average O(1) time and uses O(h)

 * memory, where h is the height of the tree. 

 * 

 * Credits:Special thanks to @ts for adding this problem and creating all test

 * cases.

 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using namespace std;

     // since average O(1) time, cannot use recursion inorder travel
     // and since we need to solve it with O(h) not O(n) sapce, we cannot use exact stack inorder travel
     // modify inorder stack travel with: only push the left nodes and pop on one node from the stack each time we need a next O(h), update node = node->right to go right (since we already finished the left by now), average is O(1) execpt when we need to push left nodes

class BSTIterator
{
private:
     stack<TreeNode*> nodes;
     TreeNode* head;
public:
     BSTIterator(TreeNode *root)
     {
          head = root;
     }

     /** @return whether we have a next smallest number */
     bool hasNext()
     {
          return (!nodes.empty() || head);
     }

     /** @return the next smallest number */
     int next()
     {
          if (!hasNext())
               return -1;
          while(head)
          {
               nodes.push(head);
               head = head->left;
          }
          head = nodes.top();
          nodes.pop();
          int val = head->val;
          head = head->right;
          return val;
     }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


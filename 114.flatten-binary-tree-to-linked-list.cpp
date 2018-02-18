/*

 * [114] Flatten Binary Tree to Linked List

 *

 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

 *

 * algorithms

 * Medium (36.22%)

 * Total Accepted:    154.7K

 * Total Submissions: 427.3K

 * Testcase Example:  '[]'

 *

 * 

 * Given a binary tree, flatten it to a linked list in-place.

 * 

 * 

 * 

 * For example,

 * Given

 * 

 * ⁠        1

 * ⁠       / \

 * ⁠      2   5

 * ⁠     / \   \

 * ⁠    3   4   6

 * 

 * 

 * 

 * The flattened tree should look like:

 * 

 * ⁠  1

 * ⁠   \

 * ⁠    2

 * ⁠     \

 * ⁠      3

 * ⁠       \

 * ⁠        4

 * ⁠         \

 * ⁠          5

 * ⁠           \

 * ⁠            6

 * 

 * 

 * click to show hints.

 * 

 * Hints:

 * If you notice carefully in the flattened tree, each node's right child

 * points to the next node of a pre-order traversal.

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
 #ifndef METHOD1
 private:
     TreeNode* prev = NULL;
 #endif
 public:
     void flatten(TreeNode* root) {
         // Note the question says flatten it to a listed list. It didn't really mean create a listed list (there is no return)
         // Rather we need to change the tree to make it only has right child and looks like a listed list
         // METHOD1 iterative:
         //      1) preorder travel, instead of printing root, let root->left = NULL, root->right = nodes.top() which is the the next node,  do not pop the next node
         //      2) check if reaches the end of the tree, either stack is empty after trying to push left/right or check nodes.empty before root->right = nodes.top()
         // METHOD2 recursive:
         //      1) The result seems to be preorder travel, but we do not know the next node of the linked list until we get to the next level so we need to build the tree from bottom and goes way up, like reverse preorder travel
         //      2) Instead of root, left, right; we do right, left, root.  And we keep a global/class next pointer to tell the upper level where to point

 #ifdef METHOD1
         if (!root)
             return;
         stack<TreeNode*> nodes;
         nodes.push(root);
         while(!nodes.empty() && root)
         {
             root = nodes.top();
             nodes.pop();
             if (root->right)
                 nodes.push(root->right);
             if (root->left)
                 nodes.push(root->left);
             root->left = NULL;
             if (!nodes.empty())
                 root->right = nodes.top();
         }
 #else
         if (!root)
             return;
         flatten(root->right);
         flatten(root->left);
         root->left = NULL;
         root->right = prev;
         prev = root;
 #endif
     }
 };

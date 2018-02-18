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
public:
     void flatten(TreeNode* root) {
          if (!root)
               return;
          stack<TreeNode*> nodes;
          nodes.push(root);
          while(!nodes.empty())
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
     }
};


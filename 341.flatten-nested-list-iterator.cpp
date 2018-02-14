/*

 * [341] Flatten Nested List Iterator

 *

 * https://leetcode.com/problems/flatten-nested-list-iterator/description/

 *

 * algorithms

 * Medium (42.87%)

 * Total Accepted:    57.1K

 * Total Submissions: 133.2K

 * Testcase Example:  '[[1,1],2,[1,1]]'

 *

 * Given a nested list of integers, implement an iterator to flatten it.

 * 

 * Each element is either an integer, or a list -- whose elements may also be

 * integers or other lists.

 * 

 * Example 1:

 * Given the list [[1,1],2,[1,1]],

 * 

 * By calling next repeatedly until hasNext returns false, the order of

 * elements returned by next should be: [1,1,2,1,1].

 * 

 * 

 * 

 * Example 2:

 * Given the list [1,[4,[6]]],

 * 

 * By calling next repeatedly until hasNext returns false, the order of

 * elements returned by next should be: [1,4,6].

 * 

 * 

 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

using namespace std;

class NestedIterator {
private:
     stack<NestedInteger> head;
public:
     NestedIterator(vector<NestedInteger> &nestedList) {
          for (int i = nestedList.size() - 1; i >= 0; i--)
          {
               head.push(nestedList[i]);
          }
     }

     int next() {
          if (hasNext())
          {
               int val = head.top().getInteger();
               head.pop();
               return val;
          }
          return -1;
     }

     bool hasNext() {
          while (!head.empty())
          {
               if(head.top().isInteger())
                    return true;
               vector<NestedInteger> node = head.top().getList();
               head.pop();
               for (int i = node.size() - 1; i >= 0; i--)
                  head.push(node[i]);
          }
          return false;
     }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


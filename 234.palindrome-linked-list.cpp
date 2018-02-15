/*

 * [234] Palindrome Linked List

 *

 * https://leetcode.com/problems/palindrome-linked-list/description/

 *

 * algorithms

 * Easy (33.36%)

 * Total Accepted:    144K

 * Total Submissions: 431.6K

 * Testcase Example:  '[]'

 *

 * Given a singly linked list, determine if it is a palindrome.

 * 

 * Follow up:

 * Could you do it in O(n) time and O(1) space?

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;

class Solution {
public:
     ListNode* reverseList(ListNode *head)
     {
          ListNode *prev = NULL;
          ListNode *next;
          while(head)
          {
               next = head->next;
               head->next = prev;
               prev = head;
               head = next;
          }
          return prev;
     }

     bool isPalindrome(ListNode* head) {
          ListNode *slow = head;
          ListNode *fast = head;
          while(fast && fast->next)
          {
               slow = slow->next;
               fast = fast->next->next;
          }
          fast = head;
          slow = reverseList(slow);
          while(slow)
          {
               if (slow->val != fast->val)
                    return false;
               slow = slow->next;
               fast = fast->next;
          }
          return true;
     }
};


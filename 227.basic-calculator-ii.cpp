/*

 * [227] Basic Calculator II

 *

 * https://leetcode.com/problems/basic-calculator-ii/description/

 *

 * algorithms

 * Medium (29.86%)

 * Total Accepted:    60.7K

 * Total Submissions: 203.1K

 * Testcase Example:  '"3+2*2"'

 *

 * Implement a basic calculator to evaluate a simple expression string.

 * 

 * The expression string contains only non-negative integers, +, -, *, /

 * operators and empty spaces  . The integer division should truncate toward

 * zero.

 * 

 * You may assume that the given expression is always valid.

 * 

 * Some examples:

 * 

 * "3+2*2" = 7

 * " 3/2 " = 1

 * " 3+5 / 2 " = 5

 * 

 * 

 * 

 * 

 * Note: Do not use the eval built-in library function.

 * 

 * 

 * Credits:Special thanks to @ts for adding this problem and creating all test

 * cases.

 */

using namespace std;

     // Simplified version of Q224 Basic Calculator without "()", but added "*/" which is similar to (). Also similar to Q150
     // use a stack to holder the numbers.  Check for NULL input
     // localCal (stack<long> &nums, long cur_num, char op) as below
     //      if sees a number, find its value
     //      if sees a space, skip it, do nothing
     //      if sees a + , push num in stack
     //      if sees a - , push -num in stack
     //      if sess a * or /, pop the front and push top operator (NOTE, this is from the last op, not the current * or /) num in stack
     // reset num and get new operator at the end of the round
     // at the end of the loop, do the last calculation with localCal
     // finally, add all numbers in the stack to get the ans

class Solution {
public:
     int calculate(string s) {
          if (s.empty())
               return 0;
          int n = s.size();
          stack<int> nums;
          int num = 0;
          char op = '+';
          for (int i = 0; i < n; i++)
          {
               num = 0;
               while(i < n && s[i] == ' ')
                    i++;
               while(i < n && isdigit(s[i]))
               {
                    num = num * 10 + s[i++] - '0';
               }
               if (op == '+')
                    nums.push(num);
               else if (op == '-')
                    nums.push(-num);
               else if (op == '*')
               {
                    int tmp = nums.top();
                    nums.pop();
                    nums.push(tmp*num);
               }
               else if (op == '/')
               {
                    int tmp = nums.top();
                    nums.pop();
                    nums.push(tmp/num);
               }
               if (i < n)
                    op = s[i];
          }
          num = 0;
          while(!nums.empty())
          {
               num+=nums.top();
               nums.pop();
          }
          return num;
     }
};


/*

 * [344] Reverse String

 *

 * https://leetcode.com/problems/reverse-string/description/

 *

 * algorithms

 * Easy (60.00%)

 * Total Accepted:    216.3K

 * Total Submissions: 360.4K

 * Testcase Example:  '"hello"'

 *

 * Write a function that takes a string as input and returns the string

 * reversed.

 * 

 * 

 * Example:

 * Given s = "hello", return "olleh".

 * 

 */

using namespace std;

class Solution {
public:
     string reverseString(string s) {
          int start = 0;
          for (int i = 0; i < s.size()/2; i++)
          {
               swap(s[i], s[s.size()-1-i]);
          }
          return s;
     }
};


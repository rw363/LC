/*

 * [647] Palindromic Substrings

 *

 * https://leetcode.com/problems/palindromic-substrings/description/

 *

 * algorithms

 * Medium (55.19%)

 * Total Accepted:    30.5K

 * Total Submissions: 55.2K

 * Testcase Example:  '"abc"'

 *

 * 

 * Given a string, your task is to count how many palindromic substrings in

 * this string.

 * 

 * 

 * 

 * The substrings with different start indexes or end indexes are counted as

 * different substrings even they consist of same characters. 

 * 

 * 

 * Example 1:

 * 

 * Input: "abc"

 * Output: 3

 * Explanation: Three palindromic strings: "a", "b", "c".

 * 

 * 

 * 

 * Example 2:

 * 

 * Input: "aaa"

 * Output: 6

 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

 * 

 * 

 * 

 * Note:

 * 

 * The input string length won't exceed 1000.

 * 

 * 

 */

using namespace std;

     // Similar to Q5 Longest Palindromic Substring. Note both odd and even substrings, so run both (i,i) and (i,i+1)
     // scan the input string from i [0~size-1], and expend center around i: while(l>=0 && r < size-1) as long as the substr is palindromic s[l--] == s[r++].  Note it is l-- not l++ as we are expending
     // for every sub palindromic, increase the counter (aa, aaa, aaaa are four palindromics)

class Solution {
public:
     int expendAtCenter(string s, int start, int end)
     {
          int count = 0;
          while(start  >= 0 && end < s.size())
          {
               if (s[start--] == s[end++])
                    count++;
               else
                    break;
          }
          return count;
     }

     int countSubstrings(string s) {
          int count = 0;
          for (int i = 0; i < s.size(); i++)
          {
               count += expendAtCenter(s, i, i);
               count += expendAtCenter(s, i, i+1);
          }
          return count;
     }
};


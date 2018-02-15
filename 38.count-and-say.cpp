/*

 * [38] Count and Say

 *

 * https://leetcode.com/problems/count-and-say/description/

 *

 * algorithms

 * Easy (36.33%)

 * Total Accepted:    176.8K

 * Total Submissions: 486.7K

 * Testcase Example:  '1'

 *

 * The count-and-say sequence is the sequence of integers with the first five

 * terms as following:

 * 

 * 1.     1

 * 2.     11

 * 3.     21

 * 4.     1211

 * 5.     111221

 * 

 * 

 * 

 * 1 is read off as "one 1" or 11.

 * 11 is read off as "two 1s" or 21.

 * 21 is read off as "one 2, then one 1" or 1211.

 * 

 * 

 * 

 * Given an integer n, generate the nth term of the count-and-say sequence.

 * 

 * 

 * 

 * Note: Each term of the sequence of integers will be represented as a

 * string.

 * 

 * 

 * Example 1:

 * 

 * Input: 1

 * Output: "1"

 * 

 * 

 * 

 * Example 2:

 * 

 * Input: 4

 * Output: "1211"

 * 

 * 

 */

using namespace std;

class Solution {
public:
     string countAndSay(int n) {
          string ans = "1";
          while(--n > 0)
          {
               string tmp = "";

               int j = 0;
               while(j < ans.size())
               {
                    char prev = ans[j];
                    int count = 0;
                    while (j < ans.size() && ans[j] == prev)
                    {
                         j++;
                         count++;
                    }
                    tmp += to_string(count) + prev;
               }
               ans = tmp;
          }
          return ans;
     }
};


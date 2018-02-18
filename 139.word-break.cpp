/*

 * [139] Word Break

 *

 * https://leetcode.com/problems/word-break/description/

 *

 * algorithms

 * Medium (31.19%)

 * Total Accepted:    195K

 * Total Submissions: 625K

 * Testcase Example:  '"leetcode"\n["leet","code"]'

 *

 * 

 * Given a non-empty string s and a dictionary wordDict containing a list of

 * non-empty words, determine if s can be segmented into a space-separated

 * sequence of one or more dictionary words. You may assume the dictionary does

 * not contain duplicate words.

 * 

 * 

 * For example, given

 * s = "leetcode",

 * dict = ["leet", "code"].

 * 

 * 

 * 

 * Return true because "leetcode" can be segmented as "leet code".

 * 

 * 

 * 

 * UPDATE (2017/1/4):

 * The wordDict parameter had been changed to a list of strings (instead of a

 * set of strings). Please reload the code definition to get the latest

 * changes.

 * 

 */

using namespace std;

class Solution {
public:
     bool wordBreak(string s, vector<string>& wordDict) {
          unordered_set<string>dict(wordDict.begin(), wordDict.end());
          if (s.empty())
               return true;
          if (dict.empty())
               return false;
          vector<bool>possible(s.size()+1, false);
          possible[0] = true;
          for (int i = 1; i <= s.size(); i++)
          {
               for (int x = 0; x <= i; x++)
               {
                    if ((possible[x] && dict.find(s.substr(x, i-x)) != dict.end()))
                    {
                         possible[i] = true;
                         break;
                    }
               }

          }
          return possible.back();
     }
};


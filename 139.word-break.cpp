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
        // DP: For all i [1 ~ s.size()+1], if it is possible to make substr(0 ~ j) from wordDict and can find substr (j ~ i) in dict then continue
        // possible[i] = possibility of making s.substr(0, i) from wordDict
        // init possible to s.size() + 1 of false, EXCEPT possible[0] is true as can always make empty string
        // To find the possible substring using for (int i = 1; i < s.size() + 1; i++)
        //      Try all possible combs of substr (0 ~ j) + substr (j ~ i) using for (int j = 0; j < i; j++)
        //          If we knew from DP that we can make substr (0 ~ j), then try to find substr (j ~ i) in the dict
        //              If such comb can be found, mark it so possible[i] is true ( since (0~j) + (j~i) are true) and break trying all j's to get the right comb
        //          when find a solution for current i, continue i++ to search the next until possible[n] -> is it possible to make s[0~n-1]

        // DP to hold if making substr (0 ~ i) is possible with the given dict. Init all size()+1 to false
        vector<bool> possible (s.size()+1, false);
        // possible to make empty array is always true
        possible[0] = true;

        // convert wordDict into set for easy search
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // scan from first to the last char, i is the index of the possible vector, which is +1 of the s index
        for (int i = 0; i < s.size()+1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                //If we knew from DP that we can make substr (0 ~ j)
                if (possible[j])
                {
                    // then try to find substr (j ~ i) in the dict
                    if (dict.find(s.substr(j, i-j)) != dict.end())
                    {
                        possible[i] = true;
                        break;
                    }
                }
            }
        }
        return possible.back();
    }
};

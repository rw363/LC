/*

 * [131] Palindrome Partitioning

 *

 * https://leetcode.com/problems/palindrome-partitioning/description/

 *

 * algorithms

 * Medium (35.13%)

 * Total Accepted:    114.4K

 * Total Submissions: 325.6K

 * Testcase Example:  '"aab"'

 *

 * 

 * Given a string s, partition s such that every substring of the partition is

 * a palindrome.

 * 

 * 

 * Return all possible palindrome partitioning of s.

 * 

 * 

 * For example, given s = "aab",

 * 

 * Return

 * 

 * [

 * ⁠ ["aa","b"],

 * ⁠ ["a","a","b"]

 * ]

 * 

 * 

 */

using namespace std;

// backtrack
// push holder into answer if we scanned all chars in this round (start = s.size())
// from start index to the end, check if we pass palindrome check with s [start ~ i], i.e. still palindrom after adding current char
// if so, push_back s[start ~ i] into holder, do backtrack with start = i + 1, and pop_back

class Solution {
public:
     bool checkpalindrome(string s, int start, int end)
     {
          while (start < end)
          {
               if (s[start++] != s[end--])
                    return false;
          }
          return true;
     }

     void backtrack(vector<vector<string>> &ans, vector<string> &holder, string s, int start)
     {
          // if we finish scanning the input string this round, push what we have into the ans
          if (start == s.size())
               ans.push_back(holder);
          // else if we still have a palindrome from start to this char, do backtracking
          for (int i = start; i < s.size(); i++)
          {
               if (checkpalindrome(s, start, i))
               {
                    holder.push_back(s.substr(start, i - start + 1));
                    backtrack(ans, holder, s, i+1);
                    holder.pop_back();
               }
          }
     }

     vector<vector<string>> partition(string s) {
          vector<vector<string>> ans;
          vector<string> holder;
          backtrack(ans, holder, s, 0);
          return ans;
     }
};


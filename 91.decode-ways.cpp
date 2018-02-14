/*

 * [91] Decode Ways

 *

 * https://leetcode.com/problems/decode-ways/description/

 *

 * algorithms

 * Medium (20.22%)

 * Total Accepted:    159.2K

 * Total Submissions: 787.4K

 * Testcase Example:  '""'

 *

 * 

 * A message containing letters from A-Z is being encoded to numbers using the

 * following mapping:

 * 

 * 

 * 

 * 'A' -> 1

 * 'B' -> 2

 * ...

 * 'Z' -> 26

 * 

 * 

 * 

 * Given an encoded message containing digits, determine the total number of

 * ways to decode it.

 * 

 * 

 * 

 * For example,

 * Given encoded message "12",

 * it could be decoded as "AB" (1 2) or "L" (12).

 * 

 * 

 * 

 * The number of ways decoding "12" is 2.

 * 

 */

using namespace std;

class Solution{
public:
     int numDecodings(string s){
          int n = s.size();
          if (n == 0)
               return 0;
          vector<int>ways(n+1, 0);
          ways[n] = 1;
          ways[n-1] = s[n-1] == '0'?0:1;

          for (int i = n - 2; i >= 0; i--)
          {
               if (s[i] == '0')
                    continue;
               if ((s[i]-'0') * 10 + (s[i+1]-'0') > 26)
                    ways[i] = ways[i+1];
               else
                    ways[i] = ways[i+1] + ways[i+2];
          }

          return ways[0];
     }
};


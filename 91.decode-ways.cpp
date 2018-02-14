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

     // Note we are decoding the message not like the excel row # question, so we do not need to do calculation like AB = A*26+B
     // if s[i~i+1] <= 26, this char can be presented with a min of 1 number
     //      1) [0] we cannot decode a leading 0, do nothing
     //      2) [1 ~ 9]  one way to decode
     //      3) [10 ~ 26] two ways to decode
     //      4) [26 ~ ] one way since it must be represented by at least two chars.  The maximum digit to look is 2
     // Then we can use DP, scan from the back of the string, least significant digit
     //      1) base case: a) possible[n] = 1       b) possible[n - 1] = 1 if s.back() isn't zero, otherwise 0;
     //      2) for i [n-2 ~ 0],
     //              a) if s[i] == '0' do nothing
     //              b) if s[i]*10 + s[i+1] is between [1 ~ 26], ways[i] = ways[i+1] + ways[i+2]      (can be either 1 or two chars)
     //              c) else ways[i] = ways[i+1]    (can not present with one)

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


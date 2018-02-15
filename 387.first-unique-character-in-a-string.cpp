/*

 * [387] First Unique Character in a String

 *

 * https://leetcode.com/problems/first-unique-character-in-a-string/description/

 *

 * algorithms

 * Easy (47.24%)

 * Total Accepted:    101.8K

 * Total Submissions: 215.6K

 * Testcase Example:  '"leetcode"'

 *

 * 

 * Given a string, find the first non-repeating character in it and return it's

 * index. If it doesn't exist, return -1.

 * 

 * Examples:

 * 

 * s = "leetcode"

 * return 0.

 * 

 * s = "loveleetcode",

 * return 2.

 * 

 * 

 * 

 * 

 * Note: You may assume the string contain only lowercase letters.

 * 

 */

using namespace std;

class Solution {
public:
     int firstUniqChar(string s) {
          vector<int>map(26, 0);
          for (auto c:s)
               map[c-'a']++;

          for (int i = 0; i < s.size(); i++)
               if (map[s[i]-'a'] == 1)
                    return i;
          return -1;
     }
};


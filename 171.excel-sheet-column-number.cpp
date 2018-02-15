/*

 * [171] Excel Sheet Column Number

 *

 * https://leetcode.com/problems/excel-sheet-column-number/description/

 *

 * algorithms

 * Easy (48.21%)

 * Total Accepted:    157.3K

 * Total Submissions: 326.2K

 * Testcase Example:  '"A"'

 *

 * Related to question Excel Sheet Column Title

 * Given a column title as appear in an Excel sheet, return its corresponding

 * column number.

 * 

 * For example:

 * ⁠   A -> 1

 * ⁠   B -> 2

 * ⁠   C -> 3

 * ⁠   ...

 * ⁠   Z -> 26

 * ⁠   AA -> 27

 * ⁠   AB -> 28 

 * 

 * Credits:Special thanks to @ts for adding this problem and creating all test

 * cases.

 */
using namespace std;

class Solution {
public:
     int titleToNumber(string s) {
          int num = 0;
          for (auto c:s)
               num = num * 26 + c-'A' + 1;

          return num;
     }
};


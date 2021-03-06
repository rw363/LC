/*

 * [166] Fraction to Recurring Decimal

 *

 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/

 *

 * algorithms

 * Medium (17.99%)

 * Total Accepted:    61K

 * Total Submissions: 339.3K

 * Testcase Example:  '1\n5'

 *

 * Given two integers representing the numerator and denominator of a fraction,

 * return the fraction in string format.

 * 

 * If the fractional part is repeating, enclose the repeating part in

 * parentheses.

 * 

 * For example,

 * 

 * Given numerator = 1, denominator = 2, return "0.5".

 * Given numerator = 2, denominator = 1, return "2".

 * Given numerator = 2, denominator = 3, return "0.(6)".

 * 

 * 

 * 

 * Credits:Special thanks to @Shangrila for adding this problem and creating

 * all test cases.

 */

using namespace std;
     // Similar to Q29 Divide two Interger. just simple math, while (num):
     //     push num/den into ans; num = num%den; nums *= 10;
     // things to note:
     // 1) return 0 if either numerator or denominator is zero
     // 2) check negative sign if (numerator < 0 ^ denominator < 0) ans += "-";
     // 3) use long num = labs((long) numerator);
     // 4) add '.' the 1st time after pushing num/den, and if num != 0
     // 5) check if you see repeated numerator (use map to record where the repeat pattern starts)

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        if (denominator == 0)
             return ans;
        if (numerator == 0)
             return "0";
        if ((numerator < 0) ^ (denominator <0))
             ans += '-';
        long num = labs(numerator);
        long denum = labs(denominator);
        bool decpoint = false;
        unordered_map<long, int>map;
        while(num)
        {
             if (map.find(num) != map.end())
             {
                  ans.insert(ans.begin() + map[num], '(');
                  ans.push_back(')');
                  break;
             }
             map.emplace(num, ans.size());

             ans += to_string(num / denum);
             num = num % denum * 10;
             if (!decpoint && num)
             {
                  ans += '.';
                  decpoint = true;
             }
        }
        return ans;
    }
};


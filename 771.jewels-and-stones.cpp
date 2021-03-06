/*
 * [782] Jewels and Stones
 *
 * https://leetcode.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (81.94%)
 * Total Accepted:    100.9K
 * Total Submissions: 123.5K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 * You're given strings J representing the types of stones that are jewels, and
 * S representing the stones you have.  Each character in S is a type of stone
 * you have.  You want to know how many of the stones you have are also
 * jewels.
 * 
 * The letters in J are guaranteed distinct, and all characters in J and S are
 * letters. Letters are case sensitive, so "a" is considered a different type
 * of stone from "A".
 * 
 * Example 1:
 * 
 * 
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: J = "z", S = "ZZ"
 * Output: 0
 * 
 * 
 * Note:
 * 
 * 
 * S and J will consist of letters and have length at most 50.
 * The characters in J are distinct.
 * 
 */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
	char jewels[256] = {0};
        //unordered_set<char> jewels;
	int num = 0;
	for (auto j:J)
	{
		jewels[j] = 1;
		//jewels.insert(j);
	}
	for (auto s:S)
	{
		//if(jewels.find(s) != jewels.end())
		if (jewels[s]==1)
			num++;
	}
	return num;
    }
};

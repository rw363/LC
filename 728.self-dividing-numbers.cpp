/*
 * [728] Self Dividing Numbers
 *
 * https://leetcode.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (67.11%)
 * Total Accepted:    49K
 * Total Submissions: 73K
 * Testcase Example:  '1\n22'
 *
 * 
 * A self-dividing number is a number that is divisible by every digit it
 * contains.
 * 
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 ==
 * 0, and 128 % 8 == 0.
 * 
 * Also, a self-dividing number is not allowed to contain the digit zero.
 * 
 * Given a lower and upper number bound, output a list of every possible self
 * dividing number, including the bounds if possible.
 * 
 * Example 1:
 * 
 * Input: 
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * 
 * 
 * Note:
 * The boundaries of each input argument are 1 .
 * 
 */
class Solution {
public:
	bool check_self(int num)
	{
		int copy = num;
		unordered_set<int> dict;
		while(copy)
		{
			char x = copy%10;
			if (x==0) return false;
			dict.insert(x);
			copy /= 10;
		}
		for (unordered_set<int>::iterator it = dict.begin(); it != dict.end(); it++)
		{
			if (num%(*it))
				return false;
		}
		return true;
	}
    vector<int> selfDividingNumbers(int left, int right) {
	vector<int> ans;
        for (;left <= right; left++)
	{
		if (check_self(left))
			ans.push_back(left);
	}
	return ans;
    }
};

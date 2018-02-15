/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.61%)
 * Total Accepted:    431.7K
 * Total Submissions: 1.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxL = 0;
        int start = 0;
        unordered_map<char, int>history;
        for (int i = 0; i < s.size(); i++)
        {
            if (history.find(s[i]) != history.end())
            {
                start = max(start, history[s[i]]+1);
                history[s[i]] = i;
            }
            else
                history.emplace(s[i], i);

            maxL = max(maxL, i - start + 1);

        }
        return maxL;
    }
};

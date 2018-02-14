/*

 * [151] Reverse Words in a String

 *

 * https://leetcode.com/problems/reverse-words-in-a-string/description/

 *

 * algorithms

 * Medium (15.67%)

 * Total Accepted:    186.6K

 * Total Submissions: 1.2M

 * Testcase Example:  '""'

 *

 * 

 * Given an input string, reverse the string word by word.

 * 

 * 

 * 

 * For example,

 * Given s = "the sky is blue",

 * return "blue is sky the".

 * 

 * 

 * 

 * Update (2015-02-12):

 * For C programmers: Try to solve it in-place in O(1) space.

 * 

 * 

 * click to show clarification.

 * 

 * Clarification:

 * 

 * 

 * 

 * What constitutes a word?

 * A sequence of non-space characters constitutes a word.

 * Could the input string contain leading or trailing spaces?

 * Yes. However, your reversed string should not contain leading or trailing

 * spaces.

 * How about multiple spaces between two words?

 * Reduce them to a single space in the reversed string.

 * 

 * 

 * 

 */
     // Reverse the whole string and then reverse each word by (always check i < size):
     // i = 0, wordS = 0, wordE = 0.  wordE also acts like a write index
     // while (i < size)
     //      1) Pre-process:
     //          a) skip spaces and move i to the start of the next word
     //          b) if this is not the 1st word (end>0), add a space in wordE(w_i). This is safe since at least a space was deleted, hence free space
     //      2) copy char and find end
     //          a) wordS = wordE: prepare to check the next word
     //          b) copy the next word (all the following non-space char) in wordE(w_i)
     //      3) reverse word
     //          e) reverse(s[wordS], s[wordE])
     // Finally, s.resize(wordE)

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        // start and end of each word
        int start;
        int end = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++)
        {
             // delete leading white spaces
             while(i < n && s[i] == ' ')
                  i++;
             // if it is not the 1st word, add a leading space
             if (i < n && end > 0)
                  s[end++] = ' ';
             // update start index for the next round
             start = end;
             while(i < n && s[i] != ' ')
                  s[end++] = s[i++];
             reverse(s.begin()+start, s.begin()+end);
        }
        s.resize(end);
    }
};


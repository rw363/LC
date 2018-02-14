/*

 * [388] Longest Absolute File Path

 *

 * https://leetcode.com/problems/longest-absolute-file-path/description/

 *

 * algorithms

 * Medium (37.22%)

 * Total Accepted:    42.4K

 * Total Submissions: 113.8K

 * Testcase Example:  '"dir\\n\\tsubdir1\\n\\tsubdir2\\n\\t\\tfile.ext"'

 *

 * Suppose we abstract our file system by a string in the following manner:

 * 

 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

 * 

 * dir

 * ⁠   subdir1

 * ⁠   subdir2

 * ⁠       file.ext

 * 

 * 

 * The directory dir contains an empty sub-directory subdir1 and a

 * sub-directory subdir2 containing a file file.ext.

 * 

 * The string

 * "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"

 * represents:

 * 

 * dir

 * ⁠   subdir1

 * ⁠       file1.ext

 * ⁠       subsubdir1

 * ⁠   subdir2

 * ⁠       subsubdir2

 * ⁠           file2.ext

 * 

 * 

 * The directory dir contains two sub-directories subdir1 and subdir2. subdir1

 * contains a file file1.ext and an empty second-level sub-directory

 * subsubdir1. subdir2 contains a second-level sub-directory subsubdir2

 * containing a file file2.ext.

 * 

 * We are interested in finding the longest (number of characters) absolute

 * path to a file within our file system. For example, in the second example

 * above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and

 * its length is 32 (not including the double quotes).

 * 

 * Given a string representing the file system in the above format, return the

 * length of the longest absolute path to file in the abstracted file system.

 * If there is no file in the system, return 0.

 * 

 * Note:

 * 

 * The name of a file contains at least a . and an extension.

 * The name of a directory or sub-directory will not contain a ..

 * 

 * 

 * 

 * Time complexity required: O(n) where n is the size of the input string.

 * 

 * Notice that a/aa/aaa/file1.txt is not the longest file path, if there is

 * another path aaaaaaaaaaaaaaaaaaaaa/sth.png.

 */
using namespace std;

 class Solution {
 public:
     int lengthLongestPath(string input) {
         // use array to keep the length of the start of each level
         // WHILE sees '\t', level++, i++
         // WHILE does not see '\n',
         //      i++, len++,
         //      when sees '.', set isFile = true
         // when sees '\n',
         //      if isFile == true, maxL = max(maxL, length[level-1] + len)
         //      else length[level] = length[level-1] + len + 1

         int maxL = 0;
         vector<int>length(input.size(), 0);

         for (int i = 0; i < input.size(); i++)
         {
             int level = 0;
             bool isFile = false;
             int len = 0;
             while(i < input.size() && input[i] == '\t')
             {
                 level++;
                 i++;
             }
             while(i < input.size() && input[i] != '\n')
             {
                 if (input[i] == '.')
                     isFile = true;
                 i++;
                 len++;
             }

             if (isFile)
                 maxL = max(maxL, length[level-1] + len);
             else
                 length[level] = length[level-1] + len + 1;
         }
         return maxL;
     }
 };


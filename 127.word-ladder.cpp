/*

 * [127] Word Ladder

 *

 * https://leetcode.com/problems/word-ladder/description/

 *

 * algorithms

 * Medium (19.88%)

 * Total Accepted:    153.2K

 * Total Submissions: 770.9K

 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'

 *

 * 

 * Given two words (beginWord and endWord), and a dictionary's word list, find

 * the length of shortest transformation sequence from beginWord to endWord,

 * such that:

 * 

 * 

 * Only one letter can be changed at a time.

 * Each transformed word must exist in the word list. Note that beginWord is

 * not a transformed word.

 * 

 * 

 * 

 * For example,

 * 

 * 

 * Given:

 * beginWord = "hit"

 * endWord = "cog"

 * wordList = ["hot","dot","dog","lot","log","cog"]

 * 

 * 

 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",

 * return its length 5.

 * 

 * 

 * 

 * Note:

 * 

 * Return 0 if there is no such transformation sequence.

 * All words have the same length.

 * All words contain only lowercase alphabetic characters.

 * You may assume no duplicates in the word list.

 * You may assume beginWord and endWord are non-empty and are not the same.

 * 

 * 

 * 

 * 

 * UPDATE (2017/1/20):

 * The wordList parameter had been changed to a list of strings (instead of a

 * set of strings). Please reload the code definition to get the latest

 * changes.

 * 

 */

using namespace std;

class Solution {
public:
     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
          int count = 2;
          unordered_set<string> s1;
          unordered_set<string> s2;
          unordered_set<string>dict(wordList.begin(), wordList.end());
          if (dict.find(endWord) == dict.end())
               return 0;
          s1.insert(beginWord);
          dict.erase(beginWord);
          s2.insert(endWord);
          dict.erase(endWord);
          while(!s1.empty() && !s2.empty())
          {
               unordered_set<string> holder;
               if (s1.size() > s2.size())
                    swap(s1, s2);
               for (auto word:s1)
               {
                    for (int i = 0; i < word.size(); i++)
                    {
                         char save = word[i];
                         for (char j = 'a'; j <= 'z'; j++)
                         {
                              if (word[i] == j)
                                   continue;
                              word[i] = j;
                              if (s2.find(word) != s2.end())
                                   return count;
                              if (dict.find(word) != dict.end())
                              {
                                   dict.erase(word);
                                   holder.insert(word);
                              }
                         }
                         word[i] = save;
                    }
               }
               count ++;
               swap(s1, holder);
          }
          return 0;
     }
};


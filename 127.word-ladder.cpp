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
     // find the distance by searching from both start and end, do so using two sets
     // first create a dict contains all input wordlist
     // if target word is not in dict, return 0;
     // add start and end into two sets (every time add a word into the sets, remove it from dict to avoid loop)
     // while (both sets are not empty (have more to search))
     //      1) create a new list to hold the new candidates
     //      2) search the sorter of the two sets
     //          a) for all chars in the word, save it first then try one of the 26 chars (except itself)
     //          b) if find it in the other set (long list), return dist
     //          c) or, if find in the dict, we know we can get there. so add the dict word into the holder (also delet from dict)
     //          d) restore the saved word
     //      3) increase the dist and use the holder as the new set

class Solution {
public:
     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
          int count = 2;
          unordered_set<string> start;
          unordered_set<string> target;
          unordered_set<string>dict(wordList.begin(), wordList.end());
          if (dict.find(endWord) == dict.end())
               return 0;
          start.insert(beginWord);
          dict.erase(beginWord);
          target.insert(endWord);
          dict.erase(endWord);
          while(!start.empty() && !target.empty())
          {
               unordered_set<string> holder;
               if (start.size() > target.size())
                    swap(start, target);
               for (auto word:start)
               {
                    for (int i = 0; i < word.size(); i++)
                    {
                         char save = word[i];
                         for (char j = 'a'; j <= 'z'; j++)
                         {
                              if (word[i] == j)
                                   continue;
                              word[i] = j;
                              if (target.find(word) != target.end())
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
               swap(start, holder);
          }
          return 0;
     }
};


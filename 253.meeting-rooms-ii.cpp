/*

 * [253] Meeting Rooms II

 *

 * https://leetcode.com/problems/meeting-rooms-ii/description/

 *

 * algorithms

 * Medium (39.54%)

 * Total Accepted:    60.8K

 * Total Submissions: 153.8K

 * Testcase Example:  '[]'

 *

 * Given an array of meeting time intervals consisting of start and end times

 * [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms

 * required.

 * 

 * 

 * For example,

 * Given [[0, 30],[5, 10],[15, 20]],

 * return 2.

 * 

 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

using namespace std;

class Solution {
public:
     int minMeetingRooms(vector<Interval>& intervals) {
          int count = 0;
          vector<int> start(intervals.size(), 0);
          vector<int> end(intervals.size(), 0);
          for (int i = 0; i < intervals.size(); i++)
          {
               start[i] = intervals[i].start;
               end[i] = intervals[i].end;
          }
          sort(start.begin(), start.end());
          sort(end.begin(), end.end());

          int endi = 0;
          for (int i = 0; i < intervals.size(); i++)
          {
               if (start[i] < end[endi])
               {
                    count++;
               }
               else
               {
                    endi++;
               }
          }
          return count;
     }
};


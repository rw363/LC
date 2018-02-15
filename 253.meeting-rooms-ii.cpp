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

     // sort the input vector using its start time , and the try to find a room is empty (room end < current start)
     //      1) METHOD1: use vector<int> rooms to track the end time, then search: for (int i = 0; i < rooms.size(); i++). Return size of rooms
     //          if (rooms[i] <= I.start) then room[i] = I.end;   else room.push_back(I.end)    <--- add a room.
     //      2) METHOD2: two vectors to store the start and end time separtely, sort them, and then for (int i = 0; i < start.size(); i++)
     //          if (start[i] < ends[end_i]) then roomCount ++;   else end_i++;

class Solution {
public:
     int minMeetingRooms(vector<Interval>& intervals) {
          /*
          vector<int> rooms;
          auto cmp = [](Interval &i1, Interval &i2) {return i1.start < i2.start || (i1.start == i2.start && i1.end < i2.end);};
          sort(intervals.begin(), intervals.end(), cmp);
          for (auto I:intervals)
          {
               bool found = false;
               if (rooms.empty())
               {
                    rooms.push_back(I.end);
                    continue;
               }

               for (auto &r:rooms)
               {
                    if (I.start >= r)
                    {
                         r = I.end;
                         found = true;
                         break;
                    }
               }
               if (!found)
                    rooms.push_back(I.end);
          }
          return rooms.size();
          */

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


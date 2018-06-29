/*
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (15.21%)
 * Total Accepted:    89.3K
 * Total Submissions: 587.3K
 * Testcase Example:  '[]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    void reduce(int &x, int &y)
    {
        int tmpx = x, tmpy = y;
        while(tmpy != 0)
        {
            int reminder = tmpx%tmpy;
            tmpx = tmpy;
            tmpy = reminder;
        }
        x /= tmpx;
        y /= tmpx;
    }
    
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();
        // points on the same line iff
        // 1. overlap (dx == 0 && dy ==0)
        // 2. same slot and pass the same (this) point
        int maxP = 0;
        // (x, (y, count))
        unordered_map<int, unordered_map<int, int>> lines;
        
        for (int i = 0; i < points.size(); i++)
        {
            int overlap = 0;
            int cur_max = 0;
            lines.clear();
            for (int j = i + 1; j < points.size(); j++)
            {
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                // check for overlap
                if (dx == 0 && dy == 0)
                {
                    overlap++;
                    continue;
                }
                reduce(dx, dy);
                // existing x
                if (lines.find(dx) != lines.end())
                {
                    // now check for y
                    if (lines[dx].find(dy) != lines[dx].end())
                    {
                        // found a match (same slop thought this point)
                        lines[dx][dy]++;
                    }
                    else
                    {
                        lines[dx].emplace(dy, 1);
                    }
                }
                else
                {
                    unordered_map<int, int> tmp;
                    tmp.emplace(dy, 1);
                    lines.emplace(dx, tmp);
                }
                cur_max = max(cur_max, lines[dx][dy]);
            }
            // same line, overlap, and itself
            maxP = max(maxP, cur_max + overlap + 1);
        }
        return maxP;
    }
};

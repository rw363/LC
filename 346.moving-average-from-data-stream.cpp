/*

 * [346] Moving Average from Data Stream

 *

 * https://leetcode.com/problems/moving-average-from-data-stream/description/

 *

 * algorithms

 * Easy (59.93%)

 * Total Accepted:    34.8K

 * Total Submissions: 58K

 * Testcase Example:  '["MovingAverage","next","next","next","next"]\n[[3],[1],[10],[3],[5]]'

 *

 * Given a stream of integers and a window size, calculate the moving average

 * of all integers in the sliding window.

 * 

 * For example,

 * 

 * MovingAverage m = new MovingAverage(3);

 * m.next(1) = 1

 * m.next(10) = (1 + 10) / 2

 * m.next(3) = (1 + 10 + 3) / 3

 * m.next(5) = (10 + 3 + 5) / 3

 * 

 * 

 */

using namespace std;

class MovingAverage {
private:
     int n;
     int sum;
     queue<int> nums;
public:
     /** Initialize your data structure here. */
     MovingAverage(int size) {
          n = size;
          sum = 0;
     }

     double next(int val) {
          if (nums.size() < n)
          {
               sum += val;
               nums.push(val);
               return (double) sum / nums.size();
          }
          sum -= nums.front();
          nums.pop();
          sum += val;
          nums.push(val);
          return (double) sum / n;
     }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */


/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:
Input: [[0,30],[5,10],[15,20]]
Output: false

Example 2:
Input: [[7,10],[2,4]]
Output: true
*/


// github.com/gentlespoon
// Q252
// 2019-02-28-16-38-51
// 2019-02-28-16-46-43


/*
Runtime: 12 ms, faster than 99.48% of C++ online submissions for Meeting Rooms.
Memory Usage: 9.2 MB, less than 96.39% of C++ online submissions for Meeting Rooms.
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
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int end = 0;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {return a.start<b.start;});
        for (Interval& i : intervals) {
            if (end == -1) {
                end = i.end;
                continue;
            }
            if (end <= i.start) {
                end=i.end;
            } else {
                return false;
            }
        }
        return true;
    }
};

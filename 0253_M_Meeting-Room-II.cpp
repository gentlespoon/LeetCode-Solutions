// github.com/gentlespoon
// Q253 - Medium - Meeting Room II
// 2019-02-28-22-23-48
// 2019-02-28-22-31-09
// Runtime: 16 ms, faster than 97.45% of C++ online submissions for Meeting Rooms II.
// Memory Usage: 10.6 MB, less than 21.39% of C++ online submissions for Meeting Rooms II.

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:
Input: [[7,10],[2,4]]
Output: 1
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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (!intervals.size()) return 0;
        sort(intervals.begin(), intervals.end(),
             [](Interval& a, Interval& b){ return a.start < b.start; });
        vector<vector<Interval>> rooms;
        for (Interval& intv : intervals) {
            bool settled = false;
            for (vector<Interval>& room : rooms) {
                if (!room.size() || room.back().end <= intv.start) {
                    room.push_back(intv);
                    settled = true;
                    break;
                }
            }
            if (!settled) {
                vector<Interval> newRoom(0);
                newRoom.push_back(intv);
                rooms.push_back(newRoom);
            }
        }
        // for (vector<Interval>& room : rooms) {
        //     cout << "Room\t";
        //     for (Interval& intv : room) {
        //         cout << intv.start << "-" << intv.end << "\t";
        //     }
        //     cout << endl;
        // }
        return rooms.size();
    }
};
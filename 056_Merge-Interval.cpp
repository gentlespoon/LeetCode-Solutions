/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/


// github.com/gentlespoon
// Q056
// 2019-02-28-16-20-39
// 2019-02-28-16-36-12

/*
Runtime: 16 ms, faster than 97.89% of C++ online submissions for Merge Intervals.
Memory Usage: 10.9 MB, less than 37.29% of C++ online submissions for Merge Intervals.
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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (!intervals.size()) return {};
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return a.start<b.start; });
        vector<Interval> answer;
        for (const Interval& i : intervals) {
            if (answer.empty() || i.start > answer.back().end) {
                answer.push_back(i);
            } else {
                answer.back().end = max(answer.back().end, i.end);
            }
        }
        return answer;
    }
};

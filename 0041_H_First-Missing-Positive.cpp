// github.com/gentlespoon
// 0041 - Hard - First Missing Positive
// 2019-03-16T12:34:52-0700
// 2019-03-16T12:40:12-0700
// Runtime: 8 ms, faster than 62.72% of C++ online submissions for First 
Missing Positive.
// Memory Usage: 9.7 MB, less than 20.23% of C++ online submissions for 
First Missing Positive.

class Solution {
public:
    map<int, int> m;
    int firstMissingPositive(vector<int>& nums) {
        for (int i : nums) {
            if (i>0) {
                if (m.count(i)) {
                    m[i]++;
                } else {
                    m.insert(make_pair(i, 1));
                }
            }
        }
        int i=1;
        for (; i<INT_MAX; i++) {
            if (!m.count(i)) {
                return i;
            }
        }
        return i; 
    }
};

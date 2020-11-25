/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

 */

// GentleSpoon me@gentlespoon.com
// Leetcode    Q681
// Start       2017-11-14-14-27-38
// Finish      2017-11-14-14-53-42

class Solution {
public:
    int digits[4];

    /**
     * Check if the digit is valid
     * @param  val  The digit being checked
     * @return      Boolean
     */
    bool isvalid(int val) {
        for (int i = 0; i < 4; i++) {
            if (val == digits[i]) {
                return true;
            }
        }
        return false;
    }
    
    string nextClosestTime(string time) {
        string timeWithoutColon = time;
        timeWithoutColon.erase(2,1);
        for(int i = 0; i<4; i++) {
            digits[i] = timeWithoutColon[i]-'0';
        }
        int hour = stoi(time.substr(0,2));
        int minute = stoi(time.substr(3,2));
        for(int i = 0; i < 1440; i++) {            // worst case: exact same time in another day, 1440 min later
            if (++minute == 60) {
                minute = 0;
                if (++hour == 24) {
                    hour = 0;
                }
            }
            if (isvalid(minute%10) &&
                isvalid(minute/10) &&
                isvalid(hour%10)   &&
                isvalid(hour/10)
                ) {
                ostringstream oss;
                oss << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minute;
                return oss.str();
            }
        }
    }
    
};

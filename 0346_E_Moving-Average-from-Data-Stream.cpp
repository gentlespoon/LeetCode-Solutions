// github.com/gentlespoon
// 0346 - Easy - Moving Average from Data Stream
// 2019-03-17T11:11:11-0700
// 2019-03-17T11:17:03-0700
// Runtime: 36 ms, faster than 99.02% of C++ online submissions for 
Moving Average from Data Stream.
// Memory Usage: 15.4 MB, less than 56.35% of C++ online submissions for 
Moving Average from Data Stream.


class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int capacity;
    int sum = 0;
    
    MovingAverage(int size) {
        capacity = size;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (capacity < q.size()) {
            sum -= q.front();
            q.pop();
        }
        return sum/(double)q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

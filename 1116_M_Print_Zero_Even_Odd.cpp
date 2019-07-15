// github.com/gentlespoon
// 1116 - Medium - Print Zero Even Odd
// Start       2019-07-12T21:35:23-07:00
// Finish      2019-07-13T11:43:18-07:00
// Runtime: 48 ms, faster than 72.66% of C++ online submissions for Print Zero Even Odd.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Print Zero Even Odd.

/*
Suppose you are given the following code:

class ZeroEvenOdd {
  public ZeroEvenOdd(int n) { ... }      // constructor
  public void zero(printNumber) { ... }  // only output 0's
  public void even(printNumber) { ... }  // only output even numbers
  public void odd(printNumber) { ... }   // only output odd numbers
}
The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A will call zero() which should only output 0's.
Thread B will call even() which should only ouput even numbers.
Thread C will call odd() which should only output odd numbers.
Each of the thread is given a printNumber method to output an integer. Modify the given program to output the series 010203040506... where the length of the series must be 2n.

 

Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously. One of them calls zero(), the other calls even(), and the last one calls odd(). "0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"
*/


class ZeroEvenOdd {
private:
    int n;

public:
    mutex mz, mo, me;
    ZeroEvenOdd(int n) {
        this->n = n;
        mo.lock();
        me.lock();
    }
    
    int current = 0;

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            mz.lock();
            printNumber(0);
            if (++current % 2) mo.unlock();
            else me.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            mo.lock();
            printNumber(current);
            mz.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            me.lock();
            printNumber(current);
            mz.unlock();
        }
    }
};

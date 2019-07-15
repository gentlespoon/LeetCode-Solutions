// github.com/gentlespoon
// 1117 - Hard - Building H2O
// Start       2019-07-13T11:51:39-07:00
// Finish      2019-07-13T12:02:51-07:00
// Runtime: 404 ms, faster than 18.18% of C++ online submissions for Building H2O.
// Memory Usage: 12.5 MB, less than 100.00% of C++ online submissions for Building H2O.

/*
There are two kinds of threads, oxygen and hydrogen. Your goal is to group these threads to form water molecules. There is a barrier where each thread has to wait until a complete molecule can be formed. Hydrogen and oxygen threads will be given a releaseHydrogen and releaseOxygen method respectfully, which will allow them to pass the barrier. These threads should pass the barrier in groups of three, and they must be able to immediately bond with each other to form a water molecule. You must guarantee that all the threads from one molecule bond before any other threads from the next molecule do.

In other words:

If an oxygen thread arrives at the barrier when no hydrogen threads are present, it has to wait for two hydrogen threads.
If a hydrogen thread arrives at the barrier when no other threads are present, it has to wait for an oxygen thread and another hydrogen thread.
Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.

 

Example 1:

Input: "HOH"
Output: "HHO"
Explanation: "HOH" and "OHH" are also valid answers.
Example 2:

Input: "OOHHHH"
Output: "HHOHHO"
Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.
*/


class H2O {
public:
    H2O() {
        o.lock();
    }
    int hCount = 0;
    mutex o, h;

    
    
    void hydrogen(function<void()> releaseHydrogen) {
        h.lock();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        hCount++;
        if (hCount<2) {
            h.unlock();
        } else {
            o.unlock();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        o.lock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        hCount-=2;
        h.unlock();
    }
};

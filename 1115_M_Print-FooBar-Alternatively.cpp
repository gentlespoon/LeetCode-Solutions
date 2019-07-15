// github.com/gentlespoon
// 1115 - Medium - Print FooBar Alternately
// Start       2019-07-12T21:25:21-07:00
// Finish      2019-07-12T21:26:18-07:00
// Runtime: 176 ms, faster than 97.22% of C++ online submissions for Print FooBar Alternately.
// Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Print FooBar Alternately.

/*
Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads. Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.

 

Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
*/



class FooBar {
private:
    int n;

public:
    
    mutex mf, mb;
    FooBar(int n) {
        mb.lock();
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            mf.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            mb.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            mb.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            mf.unlock();
        }
    }
};

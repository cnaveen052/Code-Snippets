/*
https://leetcode.com/problems/fizz-buzz-multithreaded/
*/

class FizzBuzz {
private:
    int n, count;
    mutex mu;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        count = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(1){
            unique_lock<mutex> ul(mu);
            cv.wait(ul, [&]{return count>n or (count%3==0 and count%5!=0);});
            if(count>n) return;
            printFizz();
            count++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(1){
            unique_lock<mutex> ul(mu);
            cv.wait(ul, [&]{return count>n or (count%3!=0 and count%5==0);});
            if(count>n) return;
            printBuzz();
            count++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(1){
            unique_lock<mutex> ul(mu);
            cv.wait(ul, [&]{return count>n or (count%3==0 and count%5==0);});
            if(count>n) return;
            printFizzBuzz();
            count++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(1){
            unique_lock<mutex> ul(mu);
            cv.wait(ul, [&]{return count>n or (count%3!=0 and count%5!=0);});
            if(count>n) return;
            printNumber(count++);
            cv.notify_all();
        }
    }
};

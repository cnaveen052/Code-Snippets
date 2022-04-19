#include <bits/stdc++.h>
#include <mutex>
using namespace std;

/*
Chapter 5: Singleton Design Pattern
*/

class Singleton{
    static Singleton* instance;
    static mutex mu;
    string data;
    Singleton(const string& val) : data(val){}
public:
    static Singleton* getInstance(const string& val){
        if(instance == nullptr){
            lock_guard<mutex> lg(mu);
            if(instance == nullptr){
                instance = new Singleton(val);
            }
        }
        return instance;
    }
    
    string getData() const{
        return data;
    }
    
    //Singletons should not be cloneable
    Singleton(Singleton &other) = delete;
    //Singletons should not be assignable
    void operator=(const Singleton &) = delete;
};

//Static variables should be defined outside the class
Singleton* Singleton::instance = nullptr;
mutex Singleton::mu;

void foo(){
    Singleton* singleton = Singleton::getInstance("foo");
    cout<<singleton->getData()<<endl;
}

void bar(){
    Singleton* singleton = Singleton::getInstance("bar");
    cout<<singleton->getData()<<endl;
}

int main() {
    thread t1(foo);
    thread t2(bar);
    t1.join();
    t2.join();
    //If values are equal, Singleton is implemented
}

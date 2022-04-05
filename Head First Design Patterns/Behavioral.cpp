#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(...) for(auto& i:__VA_ARGS__) cout<<i<<" "; cout<<'\n';
#define read(...) for(auto& i:__VA_ARGS__) cin>>i;
#define int long long
const int mod=1e9+7;

/*
Chapter 1: Intro to design patterns
Behavioral Design Pattern
*/

//Interface
class FlyBehavior{
public:
    virtual void fly() = 0;
};

//Implementation
class FlyWithWings : public FlyBehavior{
public:
    void fly(){
        cout<<"Flying with Wings!"<<endl;
    }
};

class FlyNoWay : public FlyBehavior{
public:
    void fly(){
        cout<<"Can't fly!"<<endl;
    }
};

//Interface
class QuackBehavior{
public:
    virtual void quack() = 0;
};

//Implementation
class Quack : public QuackBehavior{
public:
    void quack(){
        cout<<"Quack!"<<endl;
    }
};

class MuteQuack : public QuackBehavior{
public:
    void quack(){
        cout<<"........"<<endl;
    }
};

class Squeak : public QuackBehavior{
public:
    void quack(){
        cout<<"Squeak!"<<endl;
    }
};

//Abstract
class Duck{
protected:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackbehavior;
public:
    virtual void display() = 0;
    void performFly(){
        flyBehavior->fly();
    }
    void performQuack(){
        quackbehavior->quack();
    }
    void swim(){
        cout<<"floating..."<<endl;
    }
};

//Concrete
class MallardDuck : public Duck{
public:
    MallardDuck(){
        flyBehavior = new FlyWithWings();
        quackbehavior = new Quack();
    }
    void display(){
        cout<<"Looks like Mallard duck"<<endl;
    }
};
 
#undef int
int main() {
    Duck* mallard = new MallardDuck();
    mallard->display();
    mallard->performFly();
}
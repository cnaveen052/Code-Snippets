#include <bits/stdc++.h>
using namespace std;

/*
Chapter 1: Intro to design patterns
Strategy Design Pattern
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

class FlyRocketPowered : public FlyBehavior{
public:
    void fly(){
        cout<<"flying with rocket boosters!"<<endl;
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
    void setFlyBehavior(FlyBehavior* fb){
        flyBehavior = fb;
    }
    void setQuackBehavior(QuackBehavior* qb){
        quackbehavior = qb;
    }
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

class ModelDuck : public Duck{
public:
    ModelDuck(){
        flyBehavior = new FlyNoWay();
        quackbehavior = new Quack();
    }
    
    void display(){
        cout<<"Looks like Model duck"<<endl;
    }
};
 
#undef int
int main() {
    Duck* mallard = new MallardDuck();
    mallard->display();
    mallard->performFly();
    
    Duck* model = new ModelDuck();
    model->performFly();
    model->setFlyBehavior(new FlyRocketPowered());
    model->performFly();
}

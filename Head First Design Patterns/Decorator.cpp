#include <bits/stdc++.h>
using namespace std;

/*
Chapter 3: Decorator Design Pattern
*/

class Beverage{
protected:
    string description = "Unknown Beverage";
public:
    virtual string getDescription(){
        return description;
    }
    
    virtual double cost() = 0;
};

class Expresso : public Beverage{
public:
    Expresso(){
        description = "Expresso Coffee";
    }
    
    double cost(){
        return 1.99;
    }
};

class HouseBlend : public Beverage{
public:
    HouseBlend(){
        description = "House Blend Coffee";
    }
    
    double cost(){
        return 0.89;
    }
};

//can skip this class
class CondimentDecorator : public Beverage{
    
};

class Mocha : public CondimentDecorator{
    Beverage* beverage;
public:
    Mocha(Beverage* beverage){
        this->beverage = beverage;
    }
    
    string getDescription(){
        return beverage->getDescription() + ", Mocha";
    }
    
    double cost(){
        return beverage->cost() + 0.2;
    }
};

class Whip : public CondimentDecorator{
    Beverage* beverage;
public:
    Whip(Beverage* beverage){
        this->beverage = beverage;
    }
    
    string getDescription(){
        return beverage->getDescription() + ", Whip";
    }
    
    double cost(){
        return beverage->cost() + 0.3;
    }
};

int main() {
    Beverage* beverage = new Expresso();
    cout<<beverage->getDescription()<<" $"<<beverage->cost()<<endl;
    
    Beverage* beverage2 = new HouseBlend();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    cout<<beverage2->getDescription()<<" $"<<beverage2->cost()<<endl;
    
    Beverage* beverage3 = new Expresso();
    beverage3 = new Mocha(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    cout<<beverage3->getDescription()<<" $"<<beverage3->cost()<<endl;
}

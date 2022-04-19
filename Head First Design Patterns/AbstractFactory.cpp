#include <bits/stdc++.h>
using namespace std;

/*
Chapter 4: Abstract Factory Design Pattern
*/

class Dough{
public:
    virtual string getType() = 0;
};

class ThinCrustDough : public Dough{
public:
    string getType(){
        return "Thin Crust Dough";
    }
};

class ThickCrustDough : public Dough{
public:
    string getType(){
        return "Thick Crust Dough";
    }
};

class Clams{
public:
    virtual string getType() = 0;
};

class FreshClams : public Clams{
public:
    string getType(){
        return "Fresh Clams";
    }
};

class FrozenClams : public Clams{
public:
    string getType(){
        return "Frozen Clams";
    }
};

class PizzaIngredientFactory{
public:
    virtual Dough* createDough() = 0;
    virtual Clams* createClams() = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory{
public:
    Dough* createDough(){
        Dough* dough = new ThickCrustDough();
        cout<<"Using "<<dough->getType()<<endl;
        return dough;
    }
    
    Clams* createClams(){
        Clams* clam = new FreshClams();
        cout<<"Using "<<clam->getType()<<endl;
        return clam;
    }
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory{
public:
    Dough* createDough(){
        Dough* dough = new ThinCrustDough();
        cout<<"Using "<<dough->getType()<<endl;
        return dough;
    }
    
    Clams* createClams(){
        Clams* clam = new FrozenClams();
        cout<<"Using "<<clam->getType()<<endl;
        return clam;
    }
};

class Pizza{
protected:
    string name;
    
    
    Dough* dough;
    Clams* clams;
public:
    virtual void prepare() = 0;
    
    virtual void bake(){
        cout<<"Bake for 25 minutes at 350"<<endl;
    }
    
    virtual void cut(){
        cout<<"Cutting the pizza into diagonal slices"<<endl;
    }
    
    virtual void box(){
        cout<<"Place pizza in official PizzaStore box"<<endl;
    }
    
    string getName(){
        return name;
    }
    
    string setName(string name){
        this->name = name;
    }
};

class CheesePizza : public Pizza{
    PizzaIngredientFactory* ingredientFactory;
public:
    CheesePizza(PizzaIngredientFactory* ingredientFactory){
        this->ingredientFactory = ingredientFactory;
    }
    
    void prepare(){
        cout<<"Preparing "<<name<<endl;
        dough = ingredientFactory->createDough();
        clams = ingredientFactory->createClams();
    }
};

class ClamPizza : public Pizza{
    PizzaIngredientFactory* ingredientFactory;
public:
    ClamPizza(PizzaIngredientFactory* ingredientFactory){
        this->ingredientFactory = ingredientFactory;
    }
    
    void prepare(){
        cout<<"Preparing "<<name<<endl;
        dough = ingredientFactory->createDough();
        clams = ingredientFactory->createClams();
    }
};

class PizzaStore{
protected:
    virtual Pizza* createPizza(string type) = 0;
public:
    Pizza* orderPizza(string type){
        Pizza* pizza = createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};

class NYPizzaStore : public PizzaStore{
    Pizza* createPizza(string type){
        Pizza* pizza = nullptr;
        PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory();
        
        if(type=="cheese"){
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("New York Style Cheese Pizza");
        }
        else if(type=="clam"){
            pizza = new ClamPizza(ingredientFactory);
            pizza->setName("New York Style Clam Pizza");
        }
        return pizza;
    }
};

class ChicagoPizzaStore : public PizzaStore{
    Pizza* createPizza(string type){
        Pizza* pizza = nullptr;
        PizzaIngredientFactory* ingredientFactory = new ChicagoPizzaIngredientFactory();
        
        if(type=="cheese"){
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("Chicago Style Cheese Pizza");
        }
        else if(type=="clam"){
            pizza = new ClamPizza(ingredientFactory);
            pizza->setName("Chicago Style Clam Pizza");
        }
        return pizza;
    }
};

int main() {
    PizzaStore* nyPizzaStore = new NYPizzaStore();
    Pizza* pizza = nyPizzaStore->orderPizza("cheese");
    cout<<"Nick ordered "<<pizza->getName()<<endl<<endl;
    
    PizzaStore* chicagoPizzaStore = new ChicagoPizzaStore();
    Pizza* pizza2 = chicagoPizzaStore->orderPizza("clam");
    cout<<"Clement ordered "<<pizza2->getName()<<endl<<endl;
}

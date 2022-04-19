#include <bits/stdc++.h>
using namespace std;

/*
Chapter 4: Factory Design Pattern

createPizza is the abstract factory method
encapsulating the creation of concrete Pizzas
*/

class Pizza{
protected:
    string name;
    string dough;
    string sauce;
    vector<string> toppings;
public:
    virtual void prepare(){
        cout<<"Preparing "<<name<<endl;
        cout<<"Tossing dough..."<<endl;
        cout<<"Adding sauce..."<<endl;
        cout<<"Adding toppings: ";
        for(auto topping : toppings) cout<<topping<<' '; cout<<endl;
    }
    
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
};

class NYStyleCheesePizza : public Pizza{
public:
    NYStyleCheesePizza(){
        name = "NY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Grated Reggiano Cheese");
    }
};

class NYStylePepperoniPizza : public Pizza{
public:
    NYStylePepperoniPizza(){
        name = "NY Style Sauce and Pepperoni Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Pork Pepperoni");
    }
};

class ChicagoStyleCheesePizza : public Pizza{
public:
    ChicagoStyleCheesePizza(){
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Shredded Mozzarella Cheese");
    }
    
    void cut(){
        cout<<"Cutting the pizza into square slices"<<endl;
    }
};

class ChicagoStylePepperoniPizza : public Pizza{
public:
    ChicagoStylePepperoniPizza(){
        name = "Chicago Style Deep Dish Pepperoni Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Pork Pepperoni");
    }
    
    void cut(){
        cout<<"Cutting the pizza into square slices"<<endl;
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
        if(type == "cheese") return new NYStyleCheesePizza();
        else if(type == "pepperoni") return new NYStylePepperoniPizza();
        else return nullptr;
    }
};

class ChicagoPizzaStore : public PizzaStore{
    Pizza* createPizza(string type){
        if(type == "cheese") return new ChicagoStyleCheesePizza();
        else if(type == "pepperoni") return new ChicagoStylePepperoniPizza();
        else return nullptr;
    }
};

int main() {
    PizzaStore* nyStore = new NYPizzaStore();
    Pizza* pizza = nyStore->orderPizza("cheese");
    cout<<"Nick order a "<<pizza->getName()<<endl<<endl;
    
    PizzaStore* chicagoStore = new ChicagoPizzaStore();
    Pizza* pizza2 = chicagoStore->orderPizza("pepperoni");
    cout<<"Clement order a "<<pizza2->getName()<<endl<<endl;
}

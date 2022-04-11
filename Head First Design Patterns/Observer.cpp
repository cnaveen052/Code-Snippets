#include <bits/stdc++.h>
using namespace std;

/*
Chapter 2: Observer Design Pattern
*/

class Observer{
public:
    virtual void update() = 0;
};

//Subject
class WeatherData{
    unordered_set<Observer*> observers;
    int temperature, humidity, pressure;
public:
    int getTemperature(){
        return temperature;
    }
    
    int getHumidity(){
        return humidity;
    }
    
    int getPressure(){
        return pressure;
    }

    void registerObserver(Observer* o){
        observers.insert(o);
    }
    
    void removeObserver(Observer* o){
        observers.erase(o);
    }
    
    void setMeasurements(int temperature, int humidity, int pressure){
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        notifyObservers();
    }
    
    void notifyObservers(){
        for(auto observer : observers)
            observer->update();
    }
};

class CurrentConditionDisplay : public Observer{
    int temperature, humidity;
    WeatherData* weatherData;
public:
    CurrentConditionDisplay(WeatherData* weatherData){
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }
    
    void update(){
        temperature = weatherData->getTemperature();
        humidity = weatherData->getHumidity();
        display();
    }
    
    void display(){
        cout<<"Current conditions: "<<temperature<<"F degrees and "<<humidity<<"% humidity"<<endl;
    }
};

class ForecastDisplay : public Observer{
    int temperature, pressure;
    WeatherData* weatherData;
public:
    ForecastDisplay(WeatherData* weatherData){
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }
    
    void update(){
        temperature = weatherData->getTemperature();
        pressure = weatherData->getPressure();
        display();
    }
    
    void display(){
        if(temperature<5 and pressure<5)
            cout<<"Forecast: It will be cold!"<<endl;
        else if(temperature<5 and pressure>5)
            cout<<"Forecast: It might rain!"<<endl;
        else
            cout<<"Forecast: It will be hot!"<<endl;
    }
};

int main() {
    WeatherData* weatherData = new WeatherData();
    CurrentConditionDisplay* currentConditions = new CurrentConditionDisplay(weatherData);
    ForecastDisplay* forecastDisplay = new ForecastDisplay(weatherData);
    
    weatherData->setMeasurements(3,6,4);
    weatherData->setMeasurements(4,8,7);
    weatherData->setMeasurements(9,5,7);
}

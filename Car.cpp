#include "Car.h"
namespace domain {

    Car::Car()
    {
        id = -1;
    }

    Car::Car(int id, string model, string brand, int first_registration_year, int km, int power,
             float price, string fuel_type) {
        this->id = id;
        this->model = model;
        this->brand = brand;
        this->fuel_type = fuel_type;
        this->first_registration_year = first_registration_year;
        this->km = km;
        this->power = power;
        this->price = price;
    }
    //getters
    int Car::get_id() {
        return id;
    }

    string Car::get_model() {
        return model;
    }

    string Car::get_brand() {
        return brand;
    }

    string Car::get_fuel_type() {
        return fuel_type;
    }

    int Car::get_first_registration_year() {
        return first_registration_year;
    }

    int Car::get_km() {
        return km;
    }

    int Car::get_power() {
        return power;
    }

    float Car::get_price() {
        return price;
    }

    //setters
    void Car::set_id(int id) {
        this->id = id;
    }

    void Car::set_model(string model) {
        this->model = model;
    }

    void Car::set_brand(string brand) {
        this->brand = brand;
    }

    void Car::set_fuel_type(string fuel_type) {
        this->fuel_type = fuel_type;
    }

    void Car::set_first_registration_year(int first_registration_year) {
        this->first_registration_year = first_registration_year;
    }

    void Car::set_power(int power) {
        this->power = power;
    }

    void Car::set_km(int km) {
        this->km = km;
    }

    void Car::set_price(float price) {
        this->price = price;
    }

    void Car::update_car(Car car) {
        set_model(car.get_model());
        set_brand(car.get_brand());
        set_first_registration_year(car.get_first_registration_year());
        set_fuel_type(car.get_fuel_type());
        set_price(car.get_price());
        this->power = car.get_power();
        this->km = car.get_km();
    }

    string Car::toString() {
        return this->model + " " + this->brand + " registered in the year " + to_string(this->first_registration_year) + " with " +
               to_string(this->km) + " km, fuel type of " + this->fuel_type + " and a power of " + to_string(this->power) + " PS" + " costs: " + to_string(this->price) + "$";
    }

}
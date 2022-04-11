#ifndef CAR_H
#define CAR_H
#include "MainHeader.h"
namespace domain {

    class Car {
    private:
        int id;  // unique ID
        string model;
        string brand;
        string fuel_type;
        int first_registration_year;
        int km;
        int power;
        float price;

    public:
        Car();
        Car(int id, string model, string brand, int first_registration_year, int km, int power, float price, string fuel_type);

        //getters
        int get_id();
        string get_model();
        string get_brand();
        string get_fuel_type();
        int get_first_registration_year();
        int get_km();
        int get_power();
        float get_price();

        //setters
        void set_id(int id);
        void set_model(string model);
        void set_brand(string brand);
        void set_fuel_type(string fuel_type);
        void set_first_registration_year(int first_registration_year);
        void set_km(int km);
        void set_power(int power);
        void set_price(float price);

        //utils
        void update_car(Car car);
        string toString();
    };
}
#endif
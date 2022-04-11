#include "CarInMemoryRepository.h"
using namespace domain;
namespace repository {

#define NULL_Car Car(0,"","",0,0,0,0,"");

    CarInMemoryRepository::CarInMemoryRepository() {
    }

    CarInMemoryRepository::CarInMemoryRepository(vector<Car> repo_of_cars) {
        this->repo_of_cars = repo_of_cars;
    }

    void CarInMemoryRepository::set_cars(vector<Car> repo_of_cars) {
        this->repo_of_cars = repo_of_cars;
    }

    Car CarInMemoryRepository::findOne(int id) {
        for (auto index = 0; index < repo_of_cars.size(); index++)
            if (repo_of_cars[index].get_id() == id)
                return repo_of_cars[index];
        return NULL_Car;
    }

    vector<Car> CarInMemoryRepository::findAll() {
        return repo_of_cars;
    }

    Car CarInMemoryRepository::save(Car entity) {
        for (auto index = 0; index < repo_of_cars.size(); index++)
            if (repo_of_cars[index].get_id() == entity.get_id())
            {
                repo_of_cars[index].set_brand(entity.get_brand());
                repo_of_cars[index].set_model(entity.get_model());
                repo_of_cars[index].set_price(entity.get_price());
                repo_of_cars[index].set_power(entity.get_power());
                repo_of_cars[index].set_first_registration_year(entity.get_first_registration_year());
                repo_of_cars[index].set_fuel_type(entity.get_fuel_type());
                repo_of_cars[index].set_km(entity.get_km());
                return repo_of_cars[index];
            }
        repo_of_cars.push_back(entity);
        return NULL_Car;
    }

    Car CarInMemoryRepository::del(int id) {
        for (auto index = 0; index < repo_of_cars.size(); index++)
            if (repo_of_cars[index].get_id() == id) {
                Car temp = repo_of_cars[index];
                repo_of_cars.erase(repo_of_cars.begin() + index);
                return temp;
            }
        Car temp = Car();
        return temp;
    }

    Car CarInMemoryRepository::update(Car entity) {
        for (auto index = 0; index < repo_of_cars.size(); index++)
            if (repo_of_cars[index].get_id() == entity.get_id())
            {
                repo_of_cars[index].set_brand(entity.get_brand());
                repo_of_cars[index].set_model(entity.get_model());
                repo_of_cars[index].set_price(entity.get_price());
                repo_of_cars[index].set_power(entity.get_power());
                repo_of_cars[index].set_first_registration_year(entity.get_first_registration_year());
                repo_of_cars[index].set_fuel_type(entity.get_fuel_type());
                repo_of_cars[index].set_km(entity.get_km());
                return repo_of_cars[index];
            }
        return NULL_Car;
    }

    //this function checks if the car already exists in the vector
    bool CarInMemoryRepository::does_car_exists(Car car) {
        for (auto index = 0; index < repo_of_cars.size(); index++)
            if (repo_of_cars[index].get_id() == car.get_id())
                return true;
        return false;
    }

    int CarInMemoryRepository::how_many() {
        return this->repo_of_cars.size();
    }

    //this function reads our cars from the file
    void CarInMemoryRepository::load_from_file(string filename) {
        ifstream infile(filename);
        string line;
        int id = 0;
        while (getline(infile, line)) {
            istringstream iss(line);
            string model, brand, fuel_type;
            int first_registration_year, km, power;
            float price;
            char sep = ',';
            if (!(iss >> model >> sep >> brand >> sep >> first_registration_year >> sep >> km >> sep >> price >> sep
                      >> power >> sep >> fuel_type)) {
                return;
            }
            Car car = Car(id, model, brand, first_registration_year, km, power, price, fuel_type);
            id++;
            repo_of_cars.push_back(car);
        }
    }
}


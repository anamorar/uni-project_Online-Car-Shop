#include "Controller.h"
using namespace domain;
using namespace repository;
namespace controller {

    Controller::Controller() {
    }

    Controller::Controller(CarInMemoryRepository repo) {
        this->repo = repo;
    }

    CarInMemoryRepository Controller::get_repo() {
        return repo.findAll();
    }

    void Controller::set_repo(CarInMemoryRepository repo) {
        this->repo.set_cars(repo.findAll());
    }

    bool Controller::add_car(Car car) {
        if (repo.does_car_exists(car))
            return false;
        repo.save(car);
        return true;
    }

    bool Controller::delete_car(Car car) {
        if (repo.does_car_exists(car)) {
            repo.del(car.get_id());
            return true;
        }
        return false;
    }

    bool Controller::update_car(Car car) {
        if (repo.does_car_exists(car)) {
            repo.update(car);
            return true;
        }
        return false;
    }

    //this function searches for the wanted car
    vector<Car> Controller::search_car(string keyword) {
        vector<Car> filtered_cars;
        vector<Car> all_cars = repo.findAll();
        for (Car &car : all_cars) {
            if (strstr(car.get_model().c_str(), keyword.c_str()) || strstr(car.get_brand().c_str(), keyword.c_str())) {
                filtered_cars.push_back(car);
            }
        }
        return filtered_cars;
    }

    //this function filters the cars by km
    vector<Car> Controller::filter_by_km(int km) {
        vector<Car> filtered;
        vector<Car> all_cars = repo.findAll();
        for (Car &car : all_cars) {
            if (car.get_km() == km) {
                filtered.push_back(car);
            }
        }
        return filtered;
    }

    //function for comparing the prices
    bool cmp_prices(Car &a, Car &b) {
        return a.get_price() < b.get_price();
    }

    //this function sorts our cars by price
    vector<Car> Controller::sort_by_price() {
        vector<Car> all_cars = repo.findAll();
        sort(all_cars.begin(), all_cars.end(), cmp_prices);
        return all_cars;
    }

    vector<Car> Controller::get_cars() {
        return repo.findAll();
    }

    int Controller::how_many() {
        return repo.how_many();
    }



}



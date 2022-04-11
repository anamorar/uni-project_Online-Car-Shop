#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "CarInMemoryRepository.h"
#include "CRUD_Repository.h"
using namespace domain;
using namespace repository;
namespace controller {

    class Controller {
    private:
        CarInMemoryRepository repo;
    public:
        Controller();

        Controller(CarInMemoryRepository repo);

        // Getters
        CarInMemoryRepository get_repo();

        // Setters
        void set_repo(CarInMemoryRepository repo);

        // Utils
        // CRUD
        bool add_car(Car car);
        bool delete_car(Car car);
        bool update_car(Car car);

        vector<Car> search_car(string keyword);
        vector<Car> filter_by_km(int km);
        vector<Car> sort_by_price();
        vector<Car> get_cars();

        int how_many();

    };
}

#endif
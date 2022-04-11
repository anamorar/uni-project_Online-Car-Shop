#ifndef CARINMEMORYREPOSITORY_H
#define CARINMEMORYREPOSITORY_H
#include "CRUD_Repository.h"
#include "Car.h"
using namespace domain;
namespace repository {

    class CarInMemoryRepository : public CrudRepository<Car> {
    private:
        vector<Car> repo_of_cars;
    public:
        CarInMemoryRepository();

        CarInMemoryRepository(vector<Car> repo_of_cars);

        // Setters
        void set_cars(vector<Car> repo_of_cars);

        // CRUD
        /*
            C -> CREATE
            R -> READ
            U -> UPDATE
            D -> DELETE
        */
        virtual Car findOne(int id);
        virtual vector<Car> findAll();
        virtual Car save(Car entity);
        virtual Car del(int id);
        virtual Car update(Car entity);

        bool does_car_exists(Car car);
        int how_many();

        void load_from_file(string filename);
    };
}

#endif
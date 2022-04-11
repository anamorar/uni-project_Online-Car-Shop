#ifndef UI_H
#define UI_H
#include "Controller.h"
using namespace domain;
using namespace repository;
using namespace controller;
namespace ui {

    class UI {
    private:
        Controller ctrl;
    public:
        UI();

        UI(Controller& ctrl);

        void clear_console();
        void display_check_name();
        void display_start_menu();
        void start_program(Controller& controller);
        void error_wrong_input();
        bool check_password_manager();
        void display_manager_menu();
        void display_manager();
        void display_client_menu();
        void display_client();
        void end_program();

        void add_car_message(Car car);
        void delete_car_message(Car car);
        void update_car_message(Car car);

        bool name_exists(char names[]);
        void load_cart(vector<Car> &cart, char names[]);
        void create_database_file(char names[]);
    };
}

#endif
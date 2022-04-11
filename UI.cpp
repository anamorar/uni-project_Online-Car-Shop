#include "UI.h"
using namespace domain;
using namespace repository;
using namespace controller;
namespace ui {

    UI::UI() {
    }

    UI::UI(Controller &ctrl) {
        this->ctrl = ctrl;
    }

    void UI::clear_console() {
        for (auto index = 0; index < 200; index++)
            cout << endl;
    }

    void UI::display_check_name() {
        clear_console();
        cout << "=====================================================" << endl;
        cout << "||  What is your firstname?                        ||" << endl;
        cout << "=====================================================" << endl;
        cout << "  My firstname is: ";
    }

    void UI::display_start_menu() {
        cout << "=====================================================" << endl;
        cout << "||  1. Manager UI                                  ||" << endl;
        cout << "||  2. Client UI                                   ||" << endl;
        cout << "||  0. Exit application                            ||" << endl;
        cout << "=====================================================" << endl;
        cout << "  Decision: ";
    }

    void UI::start_program(Controller &controller) {


        char decision = 's';
        while (decision != '0') {
            clear_console();
            display_start_menu();
            cin >> decision;
            switch (decision) {
                case '1':    //manager
                    if (check_password_manager()) {
                        display_manager();
                        decision = '0';
                    } else {
                        clear_console();
                        cout << " Wrong password. Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                case '2':    //client
                    display_client();
                    decision = '0';
                    break;
                case '0':    //end program
                    end_program();
                    break;
                default:
                    error_wrong_input();
                    break;
            }
        }
    }

    //this function checks if it was entered a valid option
    void UI::error_wrong_input() {
        clear_console();
        cout << "=====================================================" << endl;
        cout << "||  You have entered the wrong value.              ||" << endl;
        cout << "||  Press ENTER to continue                        ||" << endl;
        cout << "=====================================================" << endl;
        cin.ignore();
    }

    bool UI::check_password_manager() {
        string password = "manager";
        cout << "Enter password: " << flush;
        string input;
        cin >> input;
        if (input == password)
            return true;
        return false;
    }

    //this function shows the option menu for the manager
    void UI::display_manager_menu() {
        clear_console();
        cout << "=====================================================" << endl;
        cout << "||  Options menu: (type number for action)         ||" << endl;
        cout << "||  0. Exit                                        ||" << endl;
        cout << "||  1. Add car                                     ||" << endl;
        cout << "||  2. Remove car                                  ||" << endl;
        cout << "||  3. Update car                                  ||" << endl;
        cout << "||  4. Search by model/brand                       ||" << endl;
        cout << "||  5. Filter by km                                ||" << endl;
        cout << "||  6. Sort by price                               ||" << endl;
        cout << "||  7. All cars                                    ||" << endl;
        cout << "=====================================================" << endl;
        cout << "||  8. Change to client                            ||" << endl;
        cout << "=====================================================" << endl;
    }

    //this function continues with the chosen option by the manager
    void UI::display_manager() {
        char decision = 's';

        while (decision != '0') {
            display_manager_menu();
            cout << "   Decision: ";
            cin >> decision;
            string model, brand, fuel_type, keyword;
            int id, first_registration_year, km, power;
            float price;
            switch (decision) {
                case '1': {
                    id = ctrl.get_repo().findAll().size();
                    cout << "Enter model: ";
                    cin >> model;
                    cout << "Enter brand: ";
                    cin >> brand;
                    cout << "Enter first year of registration: ";
                    cin >> first_registration_year;
                    cout << "Enter km: ";
                    cin >> km;
                    cout << "Enter price: ";
                    cin >> price;
                    cout << "Enter power: ";
                    cin >> power;
                    cout << "Enter type of fuel: ";
                    cin >> fuel_type;
                    Car car = Car(id, model, brand, first_registration_year, km, power, price, fuel_type);
                    add_car_message(car);
                    break;
                }
                case '2': {
                    cout << "Enter id: ";
                    cin >> id;
                    Car car = Car(id, "", "", -1, -1, -1, -1, "");
                    delete_car_message(car);
                    break;
                }
                case '3': {
                    string new_model, new_brand, new_fuel_type;
                    int new_first_registration_year, new_km, new_power;
                    float new_price;
                    cout << "Enter id: ";
                    cin >> id;
                    cout << "Enter new model: ";
                    cin >> new_model;
                    cout << "Enter new brand: ";
                    cin >> new_brand;
                    cout << "Enter new first year of registration: ";
                    cin >> new_first_registration_year;
                    cout << "Enter new km: ";
                    cin >> new_km;
                    cout << "Enter new power: ";
                    cin >> new_power;
                    cout << "Enter new price: ";
                    cin >> new_price;
                    cout << "Enter new type of fuel: ";
                    cin >> new_fuel_type;
                    Car car = Car(id, new_model, new_brand, new_first_registration_year, new_km, new_power, new_price,
                                  new_fuel_type);
                    update_car_message(car);
                    break;
                }
                case '4': {
                    vector<Car> repo;
                    cout << "Enter keyword for search: ";
                    cin >> keyword;
                    repo = ctrl.search_car(keyword);
                    if (repo.size() == 0) {
                        cout << "\nNo cars have been found. Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    } else {
                        for (auto index = 0; index < repo.size(); index++)
                            cout << repo[index].toString() << endl;
                        cout << "\nPress ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case '5': {
                    vector<Car> repo;
                    cout << "Enter km for filtering: ";
                    cin >> km;
                    repo = ctrl.filter_by_km(km);
                    if (repo.size() == 0) {
                        cout << "\nNo cars have been found. Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    } else {
                        for (auto index = 0; index < repo.size(); index++)
                            cout << repo[index].toString() << endl;
                        cout << "\nPress ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case '6': {
                    vector<Car> repo;
                    repo = ctrl.sort_by_price();
                    if (repo.size() == 0) {
                        cout << "\nNo cars have been found. Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    } else {
                        for (auto index = 0; index < repo.size(); index++)
                            cout << repo[index].toString() << endl;
                        cout << "\nPress ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case '7': {
                    clear_console();
                    vector<Car> repo;
                    repo = ctrl.get_cars();
                    if (repo.size() == 0) {
                        cout << "\nNo cars have been found. Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    } else {
                        for (auto index = 0; index < repo.size(); index++)
                            cout << repo[index].get_id() << ". " << repo[index].toString() << endl;
                        cout << "\nPress ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case '8': {
                    clear_console();
                    display_client();
                    decision = '0';
                    break;
                }
                case '0': {
                    end_program();
                    break;
                }
                default: {
                    error_wrong_input();
                    break;
                }
            }
        }
    }

    //this function shows the option menu for the client
    void UI::display_client_menu() {
        clear_console();
        cout << "=====================================================" << endl;
        cout << "||  Options menu: (type number for action)         ||" << endl;
        cout << "||  0. Exit                                        ||" << endl;
        cout << "||  1. Search by model/brand                       ||" << endl;
        cout << "||  2. Filter by km                                ||" << endl;
        cout << "||  3. Sort by price                               ||" << endl;
        cout << "||  4. All cars                                    ||" << endl;
        cout << "||  5. Buy cars                                    ||" << endl;
        cout << "||  6. Display cart                                ||" << endl;
        cout << "=====================================================" << endl;
        cout << "||  7. Change to manager                           ||" << endl;
        cout << "=====================================================" << endl;
    }

    //this function continues with the chosen option by the client
    void UI::display_client() {
        vector<Car> cart;
        display_check_name();
        char names[100];
        cin.get();
        cin.getline(names, 10, '\n');
        if (name_exists(names))
            load_cart(cart, names);
        else {
            clear_console();
            cout << "\nYour name was not found in the database. We create an account for you.";
            create_database_file(names);
        }
        char decision[10];
        decision[0] = 's';
        cin.get();

        while (decision[0] != '0') {
            display_client_menu();
            cout << "   Decision: ";
            cin.getline(decision, 10, '\n');
            int decision_int = 0;
            int i = 0;
            while (decision[i]) {
                decision_int = decision_int * 10 + (int) decision[i] - (int) '0';
                i++;
            }
            string model, brand, fuel_type, keyword;
            int km;
            switch (decision_int) {
                case 1: {
                    vector<Car> repo;
                    cout << "Enter keyword for search: ";
                    cin >> keyword;
                    repo = ctrl.search_car(keyword);
                    if (repo.size() == 0) {
                        cout << "\nNo cars have been found. Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    } else {
                        for (auto index = 0; index < repo.size(); index++)
                            cout << repo[index].toString() << endl;
                        cout << "\nPress ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case 2: {
                    vector<Car> repo;
                    cout << "Enter km for filtering: ";
                    cin >> km;
                    repo = ctrl.filter_by_km(km);
                    if (repo.size() == 0) {
                        cout << "\nNo cars have been found. Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    } else {
                        for (auto index = 0; index < repo.size(); index++)
                            cout << repo[index].toString() << endl;
                        cout << "\nPress ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case 3: {
                    vector<Car> repo;
                    repo = ctrl.sort_by_price();
                    if (repo.size() == 0) {
                        cout << "\nNo cars have been found. Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    } else {
                        for (auto index = 0; index < repo.size(); index++)
                            cout << repo[index].toString() << endl;
                        cout << "\nPress ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case 4: {
                    clear_console();
                    vector<Car> repo;
                    repo = ctrl.get_cars();
                    if (repo.size() == 0) {
                        cout << "\nNo cars have been found. Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    } else {
                        for (auto index = 0; index < repo.size(); index++)
                            cout << repo[index].toString() << endl;
                        cout << "\nPress ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case 5: {
                    vector<Car> repo;
                    repo = ctrl.get_cars();
                    if (repo.size() == 0) {
                        cout << "\nNo cars have been found. Press ENTER to continue.";
                        cin.ignore();
                        cin.ignore();
                    } else {
                        string decision_buy = "s";
                        int number;

                        for (auto index = 0; index < repo.size(); index++)
                            cout << index << ". " << repo[index].toString() << endl;
                        cout << "====================================================\n";
                        cout << "|| Which car do you want to buy ?                 ||\n";
                        cout << "====================================================\n";
                        cout << "  Decision: ";

                        cin >> decision_buy;
                        stringstream iss(decision_buy);
                        iss >> number;

                        cart.push_back(repo[number]);
                        char names_aux[100];
                        strcpy(names_aux, names);
                        strcat(names_aux, "_database.csv");
                        char path[1000] = "I:/Meditatii/Ana/tem/hmw/";
                        strcpy(path, names_aux);
                        ofstream fout(path);

                        for(auto i = 0; i < cart.size(); i++)
                        {
                            fout << cart[i].get_id() << "," << cart[i].get_brand() << "," << cart[i].get_model() << "," << cart[i].get_first_registration_year() << "," << cart[i].get_km() << "," << cart[i].get_power() << "," << cart[i].get_price() << "," << cart[i].get_fuel_type() << "\n";
                        }

                        cout << "\nYou have added the car with success ! Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case 6: {
                    if (cart.size() == 0) {
                        cout << "\nNo cars have been found. Press ENTER to continue.";
                        cin.ignore();
                        cin.ignore();
                    } else {
                        for (auto index = 0; index < cart.size(); index++)
                            cout << cart[index].toString() << endl;
                        cout << "\nPress ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case 7: {
                    clear_console();
                    if (check_password_manager()) {
                        display_manager();
                        decision[0] = '0';
                    } else {
                        clear_console();
                        cout << " Wrong password. Press ENTER to continue";
                        cin.ignore();
                        cin.ignore();
                    }
                    break;
                }
                case 0: {
                    end_program();
                    break;
                }
                default: {
                    error_wrong_input();
                    break;
                }
            }
        }
    }

    void UI::end_program() {
        cout << "=====================================================" << endl;
        cout << "||  Program shutting down...                       ||" << endl;
        cout << "||  Press ENTER to continue                        ||" << endl;
        cout << "=====================================================" << endl;
        cin.ignore();
        cin.ignore();
    }

    void UI::add_car_message(Car car) {
        if (ctrl.add_car(car)) {
            cout << "\nCar was added with success. Press ENTER to continue";
            cin.ignore();
            cin.ignore();
        } else {
            cout << "\nCar already exists in the database. Press ENTER to continue";
            cin.ignore();
            cin.ignore();
        }
    }

    void UI::delete_car_message(Car car) {
        if (ctrl.delete_car(car)) {
            cout << "\nCar was deleted with success. Press ENTER to continue";
            cin.ignore();
            cin.ignore();
        } else {
            cout << "\nCar does not exists in the database. Press ENTER to continue";
            cin.ignore();
            cin.ignore();
        }
    }

    void UI::update_car_message(Car car) {
        if (ctrl.update_car(car)) {
            cout << "\nCar was updated with success. Press ENTER to continue";
            cin.ignore();
            cin.ignore();
        } else {
            cout << "\nCar does not exists in the database. Press ENTER to continue";
            cin.ignore();
            cin.ignore();
        }
    }

    // function for checking if the name exists in the database
    bool UI::name_exists(char names[]) {
        ifstream infile("database_names.csv");
        string line;
        while (getline(infile, line)) { // read from file line by line
            istringstream iss(line);
            string name;
            char sep = ',';
            if ((iss >> name >> sep)) {
                return false;
            }
            if (strcmp(names, name.c_str()) == 0)  // we compare the names
                return true;    // true, if the name already exists in the database
        }
        return false;
    }

    // function for displaying the client's cart
    void UI::load_cart(vector<Car> &cart, char names[]) {
        char copy_names[100];
        strcpy(copy_names, names);  // copy the names to another vector to add the extension
        strcat(copy_names, "_database.csv");
        char path[100] = "/Users/Ana/CLionProjects/OOP/L6_Team04/";
        strcat(path, copy_names);
        ifstream infile(path);
        string line;
        ///
        while (getline(infile, line)) {
            istringstream iss(line);
            string model, brand, fuel_type;
            int first_registration_year, km, power, id;
            float price;
            char sep = ',';
            if (!(iss >> id >> sep >> model >> sep >> brand >> sep >> first_registration_year >> sep >> km >> sep >> power >> sep
                      >> price >> sep >> fuel_type)) {
                return;
            }
            Car car = Car(id, model, brand, first_registration_year, km, power, price, fuel_type);
            id++;
            cart.push_back(car);
        }
    }

    // function for entering a new client in the database
    void UI::create_database_file(char names[]) {
        char copy_names[100];
        strcpy(copy_names, names);
        strcat(copy_names, "_database.csv");
        ofstream MyFile(copy_names);
        MyFile.close();

        ifstream fin("database_names.csv");

        ofstream rezerva("database_de_rezerva.csv");
        char aux[100];
        while (fin.getline(aux, 100, '\n'))
            rezerva << aux << "\n";
        rezerva << names << "\n";
        fin.close();
        rezerva.close();

        ofstream fout("database_names.csv");
        ifstream rezerva2("database_de_rezerva.csv");
        while (rezerva2.getline(aux, 100, '\n'))
            fout << aux << "\n";
        fout.close();
        rezerva2.close();

        cout << "Press ENTER to continue";
        cin.ignore(2);
    }
}





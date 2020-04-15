#include <utility>

//
// Created by YKROPCHIK on 11.04.2020.
//

enum Sizes {
    small = 25, medium = 30, large = 35, extraLarge = 40
};

class Topping {
private:
    std::string name;
    uint32_t priseForOne;
    uint32_t quantity;

public:
    Topping(const std::string &name, uint32_t priseForOne, uint32_t quantity) {
        this->name = name;
        this->priseForOne = priseForOne;
    };

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Topping::name = name;
    }

    uint32_t getPriseForOne() const {
        return priseForOne;
    }

    void setPriseForOne(uint32_t priseForOne) {
        Topping::priseForOne = priseForOne;
    }

    uint32_t getQuantity() const {
        return quantity;
    }

    void addQuantity(uint32_t quantity) {
        Topping::quantity += quantity;
    }

    void print() {
        std::cout << name << ", ";
    }
};

class Pizza {
private:
    std::string name;
    std::vector<Topping> toppings;
    Sizes size;
    uint32_t prise;

public:
    Pizza(const std::string &name, std::vector<Topping> toppings, Sizes size, uint32_t prise) {
        this->name = name;
        this->toppings = std::move(toppings);
        this->size = size;
        this->prise = prise;
    };

    const std::string &getName() const {
        return name;
    }

    void setName(std::string name) {
        this->name = name;
    }

    uint8_t getSize() const {
        return size;
    }

    void setSize(Sizes size) {
        this->size = size;
    }

    uint32_t getPrise() const {
        return prise;
    }

    void setPrise(uint32_t prise) {
        this->prise = prise;
    }

    void addTopping() {

    }

    void print() {
        std::cout << name << " - ";
        for (int i = 0; i < toppings.size(); ++i) {
            toppings[i].print();
        }
        std::cout << " - " << size << "см - " << prise;
    }

    void printName(){
        std::cout << name << "\n";
    }

    void printTopping(){
        for (int i = 0; i < toppings.size(); ++i) {
            toppings[i].print();
        }
    }
};

class Menu {
private:
    std::vector<Pizza> pizzaList;

public:
    Menu(std::vector<Pizza> pizzaList) {
        this->pizzaList = pizzaList;
    };

    void addPizza(Pizza pizza) {
        pizzaList.push_back(pizza);
    }

    int getCountOfPizzas(){
        return pizzaList.size();
    }

    Pizza getPizza(int number){
        return pizzaList[number - 1];
    }

    void print() {
        for (int i = 0; i < pizzaList.size(); ++i) {
            std::cout << i + 1 << " - ";
            pizzaList[i].print();
            std::cout << std::endl;
        }

    }
};

#include <utility>

//
// Created by YKROPCHIK on 11.04.2020.
//

enum Sizes {
    small = 25, medium = 30, large = 35, extraLarge = 40
};

struct Topping {
    std::string name;
    uint8_t price;
    uint8_t quantity;
};

class Pizza {
protected:
    std::string name;
    std::vector<Topping> toppings;
    Sizes size;
    unsigned int price = 300;

public:
    virtual void addTopping(unsigned int topp, unsigned int quantity);
    virtual void printName() const;
    virtual void printTopp() const;
    virtual Sizes getSize() const;
    virtual unsigned int getPrice() const;
    virtual unsigned int getCountTopp() const;
};

void Pizza::printName() const {
    std::cout << Pizza::name;
}

void Pizza::printTopp() const {
    for (int i = 0; i < toppings.size(); ++i) {
        std::cout << i + 1 << " - " << toppings[i].name << "\n";
    }
}

Sizes Pizza::getSize() const {
    return size;
}

unsigned int Pizza::getPrice() const {
    return price;
}


unsigned int Pizza::getCountTopp() const {
    return toppings.size();
}

void Pizza::addTopping(unsigned int topp, unsigned int quantity) {
    toppings[topp].quantity += quantity;
    Pizza::price += (uint) (((size + 100.) / 100.) * quantity * toppings[topp].price);
}

class Margarita : public Pizza {
public:
    Margarita(Sizes size) {
        this->name = "Маргарита";
        this->size = size;
        this->toppings = {{"Соус",    10, 1},
                          {"Сыр",     40, 1},
                          {"Базилик", 20, 1}};
        for (int i = 0; i < toppings.size(); ++i) {
            this->price += toppings[i].price;
        }

        this->price = (uint) (price * ((size + 100.) / 100.));
    }

    void addTopping(unsigned int topp, unsigned int quantity) override {
        toppings[topp].quantity += quantity;
        this->price += (uint) (((size + 100.) / 100.) * quantity * toppings[topp].price);
    }


};

class Pepperoni : public Pizza {
public:
    Pepperoni(Sizes size) {
        this->name = "Пепперони";
        this->size = size;
        this->toppings = {{"Соус",   10, 1},
                          {"Чили",   10, 1},
                          {"Сыр",    40, 1},
                          {"Салями", 60, 1}};
        for (int i = 0; i < toppings.size(); ++i) {
            this->price += toppings[i].price;
        }

        this->price = (uint) (price * ((size + 100.) / 100.));
    }

    void addTopping(unsigned int topp, unsigned int quantity) override {
        toppings[topp].quantity += quantity;
        this->price += (uint) (((size + 100.) / 100.) * quantity * toppings[topp].price);
    }
};

class Caprichoza : public Pizza {
public:
    Caprichoza(Sizes size) {
        this->name = "Капричоза";
        this->size = size;
        this->toppings = {{"Соус",    10, 1},
                          {"Ветчина", 55, 1},
                          {"Грибы",   40, 1},
                          {"Сыр",     40, 1}};
        for (int i = 0; i < toppings.size(); ++i) {
            this->price += toppings[i].price;
        }

        this->price = (uint) (price * ((size + 100.) / 100.));
    }
};

class Phoongi : public Pizza {
public:
    Phoongi(Sizes size) {
        this->name = "Фунги";
        this->size = size;
        this->toppings = {{"Соус",          10, 1},
                          {"Колбаса",       50, 1},
                          {"Сладкий перец", 30, 1},
                          {"Грибы",         40, 1},
                          {"Базилик",       20, 1},
                          {"Сыр",           40, 1}};
        for (int i = 0; i < toppings.size(); ++i) {
            this->price += toppings[i].price;
        }

        this->price = (uint) (price * ((size + 100.) / 100.));
    }

    void addTopping(unsigned int topp, unsigned int quantity) override {
        toppings[topp].quantity += quantity;
        this->price += (uint) (((size + 100.) / 100.) * quantity * toppings[topp].price);
    }
};

class Classic : public Pizza {
public:
    Classic(Sizes size) {
        this->name = "Классическая";
        this->size = size;
        this->toppings = {{"Соус",    10, 1},
                          {"Колбаса", 50, 1},
                          {"Ветчина", 55, 1},
                          {"Сыр",     40, 1}};
        for (int i = 0; i < toppings.size(); ++i) {
            this->price += toppings[i].price;
        }

        this->price = (uint) (price * ((size + 100.) / 100.));
    }

    void addTopping(unsigned int topp, unsigned int quantity) override {
        toppings[topp].quantity += quantity;
        this->price += (uint) (((size + 100.) / 100.) * quantity * toppings[topp].price);
    }
};
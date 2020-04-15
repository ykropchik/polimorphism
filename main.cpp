#include <iostream>
#include <vector>
#include "menu.h"

class Order {
private:
    std::vector<Pizza> orderList;

public:
    void add(const Pizza &pizza) {
        orderList.push_back(pizza);
    }

    int getCount(){
        return orderList.size();
    }

    void print(){
        for (int i = 0; i < orderList.size(); ++i) {
            std::cout << i + 1 << " - ";
            orderList[i].printName();
            std::cout << " - ";
            orderList[i].printTopping();
        }
    }
};

void createMenu(){
    std::cout << "Главное меню:\n"
    << "0 - Выход\n"
    << "1 - Показать меню\n"
    << "2 - Меню заказа пиццы\n"
    << "4 - Показать заказ\n"
    << "5 - Оформить заказ\n";
}

void orderPizza(Menu &menu, Order &order) {
    int command;
    std::cout << "Меню заказа пиццы: \n";
    std::cout << "0 - Заказать пиццу \n";
    std::cout << "1 - Добавить начинку в заказанную пиццу\n";
    std::cout << "2 - Выйти в главное меню\n";
    std::cin >> command;

    while (command != 2) {
        switch (command) {
            case 0:
                int number;
                std::cout << "Введите номер пиццы из меню: ";
                std::cin >> number;
                if ((number > 0) && (number < (menu.getCountOfPizzas() + 1))) {
                    order.add(menu.getPizza(command));
                    std::cout << "Пицца добавлена в заказ\n";
                } else {
                    std::cout << "К сожалению вы ошиблись, у нас нет такого номера в меню :(\n";
                }
                break;
            case 1:
                int position;
                if (order.getCount() != 0) {
                    order.print();
                    std::cout << "Какой пицце вы хотите добавить начинку?\n";
                    std::cin >> position;
                    if ((position > 0) && (position < (order.getCount() + 1))) {
                    }

                    break;
                }

        }
    }
}

int main() {
    Topping cheese = Topping("Сыр", 15, 1);
    Topping sausage = Topping("Колбаса", 25, 1);
    Topping tomato = Topping("Томаты", 15, 1);
    Topping basil = Topping("Базилик", 10, 1);
    Topping sauce = Topping("Соус", 5, 1);
    Topping ham = Topping("Ветчина", 25, 1);
    Topping mushroom = Topping("Грибы", 20, 1);
    Topping chili = Topping("Чили", 10, 1);
    Topping bellPepper = Topping("Сладкий перец", 10, 1);
    Topping salami = Topping("Салями", 35, 1);


    Pizza margaritaM = Pizza("Маргарита (средняя)", {sauce, cheese, basil}, medium, 250);
    Pizza margaritaL = Pizza("Маргарита (большая)", {sauce, cheese, basil}, large, 270);
    Pizza pepperoniL = Pizza("Пепперони (большая)", {sauce, chili, cheese, salami}, large, 380);
    Pizza pepperoniEL = Pizza("Пепперони (очень большая)", {sauce, chili, cheese, salami}, extraLarge, 450);
    Pizza caprichozaS = Pizza("Капричоза (маленькая)", {sauce, ham, mushroom, cheese}, small, 270);
    Pizza caprichozaM = Pizza("Капричоза (средняя)", {sauce, ham, mushroom, cheese}, medium, 270);
    Pizza phoongiS = Pizza("Фунги (маленькая)", {sauce, sausage, bellPepper, mushroom, basil,cheese}, small, 270);
    Pizza phoongiM = Pizza("Фунги (средняя)", {sauce, sausage, bellPepper, mushroom, basil,cheese}, medium, 350);
    Pizza classicL = Pizza("Класическая (большая)", {sauce, sausage, ham,cheese}, large, 300);
    Pizza classicEL = Pizza("Классическая (очень большая)", {sauce, sausage, ham,cheese}, extraLarge, 350);

    Menu menu = Menu({margaritaM, margaritaL, pepperoniL, pepperoniEL, caprichozaS, caprichozaM, phoongiS, phoongiM, classicL, classicEL});
    //menu.print();

    int command = 9;
    createMenu();
    Order order;
    while (command != 0){
        std::cin >> command;
        switch (command) {
            case 1:
                menu.print();
                break;
            case 2:
                orderPizza(menu, order);
                createMenu();
                break;
            case 3:
                
                break;
            case 4:
                order.print();
                break;
            case 5:
                break;
        }
    }

    return 0;
}

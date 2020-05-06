#include <iostream>
#include <vector>
#include "menu.h"

class Order {
private:
    std::vector<Pizza *> orderList;

public:
    void add(Pizza *pizza) {
        orderList.push_back(pizza);
    }

    int getCount() {
        return orderList.size();
    }

    void print() {
        for (int i = 0; i < orderList.size(); ++i) {
            std::cout << i + 1 << " - ";
            orderList[i]->printName();
            std::cout << " - " << orderList[i]->getSize() << " см"
                      << " - " << orderList[i]->getPrice() << " руб\n";
        }
    }

    void printTopp(unsigned int num) {
        orderList[num]->printTopp();
    }

    unsigned int getCountTopp(unsigned int num) {
        return orderList[num]->getCountTopp();
    }

    void addTopp(unsigned int pizza, unsigned int topp, unsigned quantity) {
        orderList[pizza]->addTopping(topp, quantity);
    }
};

void menuPrint() {
    std::cout << "1 - Маргарита - Соус, Сыр, Базилик\n";
    std::cout << "2 - Пепперони - Соус, Чили, Сыр, Салями\n";
    std::cout << "3 - Капричоза - Соус, Ветчина, Грибы, Сыр\n";
    std::cout << "4 - Фунги - Соус, Колбаса, Сладкиц перец, Грибы, Базилик, Сыр\n";
    std::cout << "5 - Классическая - Соус, Колбаса, Ветчина, Сыр\n";
}

void createMainMenu() {
    std::cout << "Главное меню:\n"
              << "0 - Выход\n"
              << "1 - Заказ пиццы\n"
              << "2 - Показать заказ\n"
              << "3 - Оформить заказ\n";
}

void createOrderMenu() {
    std::cout << "Меню заказа пиццы: \n";
    std::cout << "0 - Выйти в главное меню\n";
    std::cout << "1 - Заказать пиццу \n";
    std::cout << "2 - Добавить начинку в заказанную пиццу\n";
}

void orderPizza(Order &order) {
    unsigned int command = 0;

    do {
        createOrderMenu();
        std::cin >> command;
        switch (command) {
            case 0:
                createMainMenu();
                break;
            case 1:
                menuPrint();
                std::cout << "Какую пиццу вы хотите?\n";
                int numPizza;
                std::cin >> numPizza;
                if ((numPizza < 1) || (numPizza > 5)) {
                    std::cout << "Простите, но у нас нет такой пиццы в меню :(\n Попробуйте еще раз ^_^\n";
                } else {
                    unsigned int sizePizza(0);
                    std::cout << "Какой размер?\n";
                    while ((sizePizza != 25) && (sizePizza != 30) && (sizePizza != 35) && (sizePizza != 40)) {
                        std::cout << "25см, 30см, 35см или 40см? (введите цифру 25, 30, 35 или 40)\n";
                        std::cin >> sizePizza;

                        if ((sizePizza != 25) && (sizePizza != 30) && (sizePizza != 35) && (sizePizza != 40)) {
                            std::cout << "Вы ввели не верный размер, попробуйте еще раз ^_^\n";
                        }
                    }
                    switch (numPizza) {
                        case 1:
                            order.add(new Margarita((Sizes) sizePizza));
                            break;
                        case 2:
                            order.add(new Pepperoni((Sizes) sizePizza));
                            break;
                        case 3:
                            order.add(new Caprichoza((Sizes) sizePizza));
                            break;
                        case 4:
                            order.add(new Phoongi((Sizes) sizePizza));
                            break;
                        case 5:
                            order.add(new Classic((Sizes) sizePizza));
                            break;
                    }
                    std::cout << "Пицца добавлена в ваш заказ ^_^\n";
                }
                break;
            case 2:
                if (order.getCount() == 0) {
                    std::cout
                            << "Извините, но вы не добавили ни одной пиццы в заказ, для начала закажите пиццу, затем добавьте начинку ^_^\n";
                } else {
                    std::cout << "К какой пиццу вы хотите добавить начинку?\n";
                    order.print();
                    unsigned int posOrderPizza(0);

                    do {
                        std::cin >> posOrderPizza;
                        if ((posOrderPizza == 0) || (posOrderPizza > order.getCount())) {
                            std::cout << "Извините, у вас нет такого номера в заказе, попробуйте еще раз ^_^\n";
                        } else {
                            order.printTopp(posOrderPizza - 1);
                            unsigned int posTopp(0);
                            do {
                                std::cin >> posTopp;
                                if ((posTopp == 0) || (posTopp > order.getCountTopp(posOrderPizza - 1))) {
                                    std::cout << "Извините, в этой пицце нет такой начинки, попробуйте еще раз ^_^\n";
                                } else {
                                    unsigned int quantityTopp(0);
                                    std::cout << "Сколько начинки вы хотите добавить?\n";
                                    std::cin >> quantityTopp;
                                    order.addTopp(posOrderPizza - 1, posTopp - 1, quantityTopp);
                                }
                            } while ((posTopp == 0) || (posTopp > order.getCountTopp(posOrderPizza - 1)));
                        }
                    } while ((posOrderPizza == 0) || (posOrderPizza > order.getCount()));
                }

                break;
            default:
                break;
        }
    } while (command != 0);
}


int main() {
    int command = 0;
    createMainMenu();
    Order order;
    do {
        std::cin >> command;
        switch (command) {
            case 0:
                std::cout << "До свидания, приходите еще ^_^\n";
            case 1:
                orderPizza(order);
                break;
            case 2:
                order.print();
                break;
            case 3:
                if (order.getCount() == 0) {
                    std::cout << "Извините, но вы ничего не добавили в заказ ^_^\n";
                } else {
                    std::cout << "Ваш заказ принят, ожидайте ^_^\n";
                    exit(0);
                }
                break;
            default:
                break;
        }
    } while (command != 0);

    return 0;
}

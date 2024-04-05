#include "Part.h"

// Клас для моторного масла, наслідується від Part
class Oil : public Part {
public:
    Oil(double price, std::string name) : Part(price, name) {} // Конструктор

    void display() const override { // Перевизначений метод для відображення інформації про масло
        std::cout << "Oil: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

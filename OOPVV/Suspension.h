#include "Part.h"

// Клас для моторного масла, наслідується від Part
class Suspension : public Part {
public:
    Suspension(double price, std::string name) : Part(price, name) {} // Конструктор

    void display() const override { // Перевизначений метод для відображення інформації про масло
        std::cout << "Suspension: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

#include "Part.h"

// Клас для моторного масла, наслідується від Part
class FuelSystem : public Part {
public:
    FuelSystem(double price, std::string name) : Part(price, name) {} // Конструктор

    void display() const override { // Перевизначений метод для відображення інформації про масло
        std::cout << "Fuel System: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

#include "Part.h"

// Клас для моторного масла, наслідується від Part
class CoolingSystem : public Part {
public:
    CoolingSystem(double price, std::string name) : Part(price, name) {} // Конструктор

    void display() const override { // Перевизначений метод для відображення інформації про масло
        std::cout << "Cooling System: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

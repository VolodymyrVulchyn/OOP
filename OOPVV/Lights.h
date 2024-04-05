#include "Part.h"

// Клас для моторного масла, наслідується від Part
class Lights : public Part {
public:
    Lights(double price, std::string name) : Part(price, name) {} // Конструктор

    void display() const override { // Перевизначений метод для відображення інформації про масло
        std::cout << "Ligths: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

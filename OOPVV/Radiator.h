#include "Part.h"

// Клас для радіаторів, наслідується від Part
class Radiator : public Part {
public:
    Radiator(double price, std::string name) : Part(price, name) {} // Конструктор

    void display() const override { // Перевизначений метод для відображення інформації про радіатори
        std::cout << "Radiator: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

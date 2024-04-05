#include "Part.h"

// Клас для суппортів, наслідується від Part
class BrakePad : public Part {
public:
    BrakePad(double price, std::string name) : Part(price, name) {} // Конструктор

    void display() const override { // Перевизначений метод для відображення інформації про суппорти
        std::cout << "Brake Pad: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

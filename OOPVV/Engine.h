#include "Part.h"

// Клас для двигуна, наслідується від Part
class Engine : public Part {
public:
    Engine(double price, std::string name) : Part(price, name) {} // Конструктор

    void display() const override { // Перевизначений метод для відображення інформації про двигун
        std::cout << "Engine: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

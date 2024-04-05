#include "Part.h"

// Клас для свічок запалювання, наслідується від Part
class SparkPlug : public Part {
public:
    SparkPlug(double price, std::string name) : Part(price, name) {} // Конструктор

    void display() const override { // Перевизначений метод для відображення інформації про свічки запалювання
        std::cout << "Spark Plug: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

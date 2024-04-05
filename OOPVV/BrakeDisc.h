#include "Part.h"

// Клас для гальмівних дисків, наслідується від Part
class BrakeDisc : public Part {
public:
    BrakeDisc(double price, std::string name) : Part(price, name) {} // Конструктор

    void display() const override { // Перевизначений метод для відображення інформації про гальмівні диски
        std::cout << "Brake Disc: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

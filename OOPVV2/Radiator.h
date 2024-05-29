#include "Part.h"

class Radiator : public Part {
public:
    Radiator(double price, std::string name) : Part(price, name) {} 

    void display() const override { 
        std::cout << "Radiator: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

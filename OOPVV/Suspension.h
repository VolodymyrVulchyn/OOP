#include "Part.h"

class Suspension : public Part {
public:
    Suspension(double price, std::string name) : Part(price, name) {} 

    void display() const override { 
        std::cout << "Suspension: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

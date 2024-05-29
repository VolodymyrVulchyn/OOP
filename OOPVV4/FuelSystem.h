#include "Part.h"


class FuelSystem : public Part {
public:
    FuelSystem(double price, std::string name) : Part(price, name) {} 

    void display() const override { 
        std::cout << "Fuel System: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

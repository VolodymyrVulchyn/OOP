#include "Part.h"


class CoolingSystem : public Part {
public:
    CoolingSystem(double price, std::string name) : Part(price, name) {} 

    void display() const override { 
        std::cout << "Cooling System: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

#include "Part.h"


class BrakeDisc : public Part {
public:
    BrakeDisc(double price, std::string name) : Part(price, name) {} 

    void display() const override { 
        std::cout << "Brake Disc: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

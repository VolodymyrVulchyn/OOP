#include "Part.h"


class BrakePad : public Part {
public:
    BrakePad(double price, std::string name) : Part(price, name) {} 

    void display() const override { 
        std::cout << "Brake Pad: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

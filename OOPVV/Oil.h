#include "Part.h"

class Oil : public Part {
public:
    Oil(double price, std::string name) : Part(price, name) {} 

    void display() const override { 
        std::cout << "Oil: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

#include "Part.h"


class Lights : public Part {
public:
    Lights(double price, std::string name) : Part(price, name) {} 

    void display() const override { 
        std::cout << "Ligths: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

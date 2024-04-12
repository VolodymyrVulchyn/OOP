#include "Part.h"

class Engine : public Part {
public:
    Engine(double price, std::string name) : Part(price, name) {} 

    void display() const override { 
        std::cout << "Engine: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

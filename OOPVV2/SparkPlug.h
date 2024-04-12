#include "Part.h"

class SparkPlug : public Part {
public:
    SparkPlug(double price, std::string name) : Part(price, name) {} 

    void display() const override { 
        std::cout << "Spark Plug: " << getName() << ", Price: " << getPrice() << std::endl;
    }
};

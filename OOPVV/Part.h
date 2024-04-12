#pragma once 

#include <string>
#include <iostream>

class Part {
protected:
    double price; 
    std::string name; 

public:
    Part(double p, std::string n) : price(p), name(n) {} 
    virtual ~Part() {} 

    virtual double getPrice() const { return price; } 
    virtual std::string getName() const { return name; } 

    virtual void display() const = 0; 
};

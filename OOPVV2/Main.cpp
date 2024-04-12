#include <iostream>
#include "Engine.h"
#include "Oil.h"
#include "BrakePad.h"
#include "BrakeDisc.h"
#include "Radiator.h"
#include "SparkPlug.h"
#include "Lights.h"
#include "CoolingSystem.h"
#include "Suspension.h"
#include "FuelSystem.h"
#include "LinkedList.h"
// #include "ShoppingCart.h"

int main() {
    LinkedList list; 

    std::shared_ptr<Part> engine(new Engine(5000, "V8 Engine"));
    std::shared_ptr<Part> oil(new Oil(50, "Synthetic Motor Oil"));
    std::shared_ptr<Part> brakePad(new BrakePad(30, "Ceramic Brake Pads"));
    std::shared_ptr<Part> brakeDisc(new BrakeDisc(70, "Ventilated Brake Disc"));
    std::shared_ptr<Part> radiator(new Radiator(150, "Aluminum Radiator"));
    std::shared_ptr<Part> sparkPlug(new SparkPlug(10, "Iridium Spark Plug"));
    std::shared_ptr<Part> lights(new Lights(250, "Iridium Spark Plug"));
    std::shared_ptr<Part> coolingSystem(new CoolingSystem(1500, "Iridium Spark Plug"));
    std::shared_ptr<Part> suspension(new Suspension(750, "Iridium Spark Plug"));
    std::shared_ptr<Part> fuelSystem(new FuelSystem(2000, "Iridium Spark Plug"));
    

    list.addFront(engine);
    list.addFront(oil);
    list.addFront(brakePad);
    list.addFront(brakeDisc);
    list.addFront(radiator);
    list.addFront(sparkPlug);
    list.addFront(lights);
    list.addFront(coolingSystem);
    list.addFront(suspension);
    list.addFront(fuelSystem);
    
    std::cout << "--------------CAR MOTORS CLUB--------------" << std::endl;
    std::cout << "Your bin: \n" << std::endl;
    
    list.display();
    
    std::cout << "Total: " << list.getTotal() << std::endl;
    std::cout << "--------------CAR MOTORS CLUB--------------" << std::endl;
    
    list.remove(brakePad);
    list.remove(suspension);
    list.remove(fuelSystem);
    

    std::cout << "\n--------------CAR MOTORS CLUB--------------";
    std::cout << "\nYour bin after removing one of elements:\n" << std::endl;

    list.display();
    
    // cart.displayRemovedParts();
    std::cout << "Total: " << list.getTotal() << std::endl;
    std::cout << "--------------CAR MOTORS CLUB--------------" << std::endl;
    return 0;
}

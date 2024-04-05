#include <iostream>
#include "Engine.h"
#include "Oil.h"
#include "BrakePad.h"
#include "BrakeDisc.h"
#include "Radiator.h"
#include "SparkPlug.h"
#include "ShoppingCart.h"
#include "Lights.h"
#include "CoolingSystem.h"
#include "Suspension.h"
#include "FuelSystem.h"


int main() {
    ShoppingCart cart; // Створення корзини покупок

    // Створення запчастин
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
    


    // Додавання запчастин до корзини
    cart.addPart(engine);
    cart.addPart(oil);
    cart.addPart(brakePad);
    cart.addPart(brakeDisc);
    cart.addPart(radiator);
    cart.addPart(sparkPlug);
    cart.addPart(lights);
    cart.addPart(coolingSystem);
    cart.addPart(suspension);
    cart.addPart(fuelSystem);
    
    
    // Відображення всіх запчастин в корзині до видалення одного з елементів
    std::cout << "Your bin: \n" << std::endl;
    
    // Відображення всіх запчастин в корзині до видалення одного з елементів
    cart.displayCart();
    
    // Виведення загальної суми покупки до видалення одного з елементів
    std::cout << "Total: " << cart.getTotal() << std::endl;

    // Видалення однієї запчастини з корзини
    cart.removePart(brakePad);
    cart.removePart(suspension);
    cart.removePart(fuelSystem);
    
    
    std::cout << "\nYour bin after removing one of elements:\n" << std::endl;

    // Відображення всіх запчастин в корзині після видалення одного з елементів
    cart.displayCart();
    
    // cart.displayRemovedParts();
    // Виведення загальної суми покупки після видалення одного з елементів
    std::cout << "Total: " << cart.getTotal() << std::endl;

    return 0;
}

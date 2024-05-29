#pragma once
#include <memory>
#include "Part.h"
#include "Node.h"

class LinkedList {
private:
    std::unique_ptr<Node> head; 

public:
    LinkedList() : head(nullptr) {}

    void addFront(std::shared_ptr<Part> part) {
        auto newNode = std::make_unique<Node>(part);
        newNode->next = std::move(head);
        head = std::move(newNode);
    }

    
    bool remove(std::shared_ptr<Part> part) {
        Node* current = head.get();
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->part == part) {
                if (prev == nullptr) { 
                    head = std::move(current->next);
                } else { 
                    prev->next = std::move(current->next);
                }
                return true;
            }
            prev = current;
            current = current->next.get();
        }
        return false;
    }

    void display() const {
        Node* current = head.get();
        while (current != nullptr) {
            current->part->display();
            current = current->next.get();
        }
    }

    double getTotal() const {
        double total = 0.0;
        Node* current = head.get();
        while (current != nullptr) {
            total += current->part->getPrice();
            current = current->next.get();
        }
        return total;
    }
};
// // PartTests.cpp

// #include <iostream>
// #include <sstream> // Додано цей заголовок для std::ostringstream
// #include "Engine.h"
// #include "ShoppingCart.h"
// #include "BrakePad.h"
// #include "BrakeDisc.h"
// #include "Lights.h"
// #include "Suspension.h"
// #include "CoolingSystem.h"
// #include "FuelSystem.h"
// #include "SparkPlug.h"
// #include "Oil.h"
// #include "Radiator.h"

// // Функція для перевірки результату
// void assertEqual(double actual, double expected, const std::string& testName) {
//     if (actual != expected) {
//         std::cerr << testName << " не пройдено: очікувалося " << expected << ", отримано " << actual << std::endl;
//     } else {
//         std::cout << testName << " пройдено." << std::endl;
//     }
// }

// // Тестування методу addPart
// void testAddPart() {
//     ShoppingCart cart;

//     // Додавання простої частини
//     std::shared_ptr<Part> brakePad = std::make_shared<BrakePad>(30, "Ceramic Brake Pads");
//     cart.addPart(brakePad);
//     assertEqual(cart.getTotal(), 30.0, "testAddPart - Додавання простого BrakePad");

//     // Додавання двигуна з залежностями
//     std::shared_ptr<Part> engine = std::make_shared<Engine>(5000, "V8 Engine");
//     cart.addPart(engine);
//     // Engine: 5000, FuelSystem: 2000, Oil: 50, Radiator: 150
//     assertEqual(cart.getTotal(), 7200.0, "testAddPart - Додавання Engine з залежностями");
// }

// // Тестування методу removePart
// void testRemovePart() {
//     ShoppingCart cart;

//     std::shared_ptr<Part> brakePad = std::make_shared<BrakePad>(30, "Ceramic Brake Pads");
//     std::shared_ptr<Part> suspension = std::make_shared<Suspension>(750, "Adjustable Suspension");

//     cart.addPart(brakePad);
//     cart.addPart(suspension);

//     // Видалення частини
//     cart.removePart(brakePad);
//     assertEqual(cart.getTotal(), 750.0, "testRemovePart - Видалення BrakePad");

//     // Видалення іншої частини
//     cart.removePart(suspension);
//     assertEqual(cart.getTotal(), 0.0, "testRemovePart - Видалення Suspension");
// }

// // Тестування методу display класу Engine
// void testEngineDisplay() {
//     std::shared_ptr<Engine> engine = std::make_shared<Engine>(5000, "V8 Engine");

//     // Перехоплення виводу в консоль
//     std::streambuf* originalCoutBuffer = std::cout.rdbuf();
//     std::ostringstream capturedOutput;
//     std::cout.rdbuf(capturedOutput.rdbuf());

//     engine->display();

//     // Відновлення початкового буфера
//     std::cout.rdbuf(originalCoutBuffer);

//     std::string expectedOutput = "Engine: V8 Engine, Price: 5000\n"
//     std::string expectedOutput = "Fuel System: Fuel System for V8 Engine, Price: 2000\n"
//                                  "Oil: Oil for V8 Engine, Price: 50\n"
//                                  "Radiator: Radiator for V8 Engine, Price: 150\n";

//     if (capturedOutput.str() != expectedOutput) {
//         std::cerr << "testEngineDisplay не пройдено: отримано \n" << capturedOutput.str()
//                   << "\nочікувалося \n" << expectedOutput << std::endl;
//     } else {
//         std::cout << "testEngineDisplay пройдено." << std::endl;
//     }
// }

// int main() {
//     testAddPart();
//     testRemovePart();
//     testEngineDisplay();

//     return 0;
// }

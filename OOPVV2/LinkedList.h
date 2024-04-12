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

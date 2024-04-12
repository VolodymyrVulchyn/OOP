#pragma once
#include <memory>
#include "Part.h"

class Node {
public:
    std::shared_ptr<Part> part; 
    std::unique_ptr<Node> next; 

    Node(std::shared_ptr<Part> p) : part(p), next(nullptr) {}
};

#include <vector>
#include <memory>
#include <algorithm> 
#include "Part.h"

// Клас для корзини покупок
class ShoppingCart {
private:
    std::vector<std::shared_ptr<Part>> parts; 
    std::vector<std::shared_ptr<Part>> removedParts; 
    
public:
    void addPart(const std::shared_ptr<Part>& part) { 
        parts.push_back(part);
    }

    void removePart(const std::shared_ptr<Part>& part) { 
        auto newEnd = std::remove_if(parts.begin(), parts.end(),
                                    [&part](const std::shared_ptr<Part>& p) { return p == part; });
        parts.erase(newEnd, parts.end());
    }

    double getTotal() const { 
        double total = 0.0;
        for (const auto& part : parts) {
            total += part->getPrice();
        }
        return total;
    }

    void displayCart() const { 
        for (const auto& part : parts) {
            part->display();
        }
    }

    // void displayRemovedParts() const { 
    //     for (const auto& part : removedParts) {
    //         part->display();
    //     }
    // }
};

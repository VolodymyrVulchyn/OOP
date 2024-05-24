#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QObject>
#include <QVector>
#include <algorithm>
#include <memory>
#include "Part.h"

class ShoppingCart : public QObject {
    Q_OBJECT
public:
    explicit ShoppingCart(QObject* parent = nullptr) : QObject(parent) {}

    void addPart(const std::shared_ptr<Part>& part) {
        parts.push_back(part);
    }

    void removePart(const std::shared_ptr<Part>& part) {
        parts.erase(std::remove(parts.begin(), parts.end(), part), parts.end());
    }

    void removePartByName(const QString& name) {
        parts.erase(std::remove_if(parts.begin(), parts.end(), [&](const auto& part) {
                        return part->getName() == name;
                    }), parts.end());
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

    const QVector<std::shared_ptr<Part>>& getParts() const { // Додано функцію getParts()
        return parts;
    }

private:
    QVector<std::shared_ptr<Part>> parts;
};

#endif // SHOPPINGCART_H

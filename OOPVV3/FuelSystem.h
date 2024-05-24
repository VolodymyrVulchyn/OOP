#ifndef FUELSYSTEM_H
#define FUELSYSTEM_H

#include "Part.h"
#include <QDebug> // Додайте цей рядок

class FuelSystem : public Part {
public:
    explicit FuelSystem(double price = 0.0, const QString& name = "", QObject* parent = nullptr)
        : Part(price, name, parent) {}

    void display() const override {
        qDebug() << "Fuel System: " << getName() << ", Price: " << getPrice();
    }
};

#endif // FUELSYSTEM_H

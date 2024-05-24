#ifndef COOLINGSYSTEM_H
#define COOLINGSYSTEM_H

#include "Part.h"

class CoolingSystem : public Part {
public:
    explicit CoolingSystem(double price = 0.0, const QString& name = "", QObject* parent = nullptr)
        : Part(price, name, parent) {}

    void display() const override {
        qDebug() << "Cooling System: " << getName() << ", Price: " << getPrice();
    }
};

#endif // COOLINGSYSTEM_H

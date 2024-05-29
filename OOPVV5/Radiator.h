#ifndef RADIATOR_H
#define RADIATOR_H

#include "Part.h"

class Radiator : public Part {
public:
    explicit Radiator(double price = 0.0, const QString& name = "", QObject* parent = nullptr)
        : Part(price, name, parent) {}

    void display() const override {
        qDebug() << "Radiator: " << getName() << ", Price: " << getPrice();
    }
};

#endif // RADIATOR_H

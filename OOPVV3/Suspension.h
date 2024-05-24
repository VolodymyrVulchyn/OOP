#ifndef SUSPENSION_H
#define SUSPENSION_H

#include "Part.h"

class Suspension : public Part {
public:
    explicit Suspension(double price = 0.0, const QString& name = "", QObject* parent = nullptr)
        : Part(price, name, parent) {}

    void display() const override {
        qDebug() << "Suspension: " << getName() << ", Price: " << getPrice();
    }
};

#endif // SUSPENSION_H

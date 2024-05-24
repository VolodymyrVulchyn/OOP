#ifndef LIGHTS_H
#define LIGHTS_H

#include "Part.h"

class Lights : public Part {
public:
    explicit Lights(double price = 0.0, const QString& name = "", QObject* parent = nullptr)
        : Part(price, name, parent) {}

    void display() const override {
        qDebug() << "Lights: " << getName() << ", Price: " << getPrice();
    }
};

#endif // LIGHTS_H

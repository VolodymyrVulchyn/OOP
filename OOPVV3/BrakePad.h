#ifndef BRAKEPAD_H
#define BRAKEPAD_H

#include "Part.h"

class BrakePad : public Part {
public:
    explicit BrakePad(double price = 0.0, const QString& name = "", QObject* parent = nullptr)
        : Part(price, name, parent) {}

    void display() const override {
        qDebug() << "Brake Pad: " << getName() << ", Price: " << getPrice();
    }
};

#endif // BRAKEPAD_H

#ifndef BRAKEDISC_H
#define BRAKEDISC_H

#include "Part.h"

class BrakeDisc : public Part {
public:
    explicit BrakeDisc(double price = 0.0, const QString& name = "", QObject* parent = nullptr)
        : Part(price, name, parent) {}

    void display() const override {
        qDebug() << "Brake Disc: " << getName() << ", Price: " << getPrice();
    }
};

#endif // BRAKEDISC_H

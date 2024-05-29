#ifndef OIL_H
#define OIL_H

#include "Part.h"

class Oil : public Part {
public:
    explicit Oil(double price = 0.0, const QString& name = "", QObject* parent = nullptr)
        : Part(price, name, parent) {}

    void display() const override {
        qDebug() << "Oil: " << getName() << ", Price: " << getPrice();
    }
};

#endif // OIL_H

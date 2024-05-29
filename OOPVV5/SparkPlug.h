#ifndef SPARKPLUG_H
#define SPARKPLUG_H

#include "Part.h"

class SparkPlug : public Part {
public:
    explicit SparkPlug(double price = 0.0, const QString& name = "", QObject* parent = nullptr)
        : Part(price, name, parent) {}

    void display() const override {
        qDebug() << "Spark Plug: " << getName() << ", Price: " << getPrice();
    }
};

#endif // SPARKPLUG_H

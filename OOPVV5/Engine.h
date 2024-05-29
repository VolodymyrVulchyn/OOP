#ifndef ENGINE_H
#define ENGINE_H

#include "Part.h"
#include "FuelSystem.h"
#include "Oil.h"
#include "Radiator.h"
#include <QVector>
#include <memory>

class Engine : public Part {
    Q_OBJECT
public:
    explicit Engine(double price = 0.0, const QString& name = "", QObject* parent = nullptr)
        : Part(price, name, parent), fuelSystem(new FuelSystem(2000, "Fuel System for " + name)),
        oil(new Oil(50, "Oil for " + name)), radiator(new Radiator(150, "Radiator for " + name)) {}

    void display() const override {
        qDebug() << "Engine: " << getName() << ", Price: " << getPrice() << ", ID: " << getId(); // Додамо виведення ідентифікатора
        fuelSystem->display();
        oil->display();
        radiator->display();
    }


    QVector<std::shared_ptr<Part>> getDependencies() const {
        return { fuelSystem, oil, radiator };
    }

private:
    std::shared_ptr<FuelSystem> fuelSystem;
    std::shared_ptr<Oil> oil;
    std::shared_ptr<Radiator> radiator;
};

#endif // ENGINE_H

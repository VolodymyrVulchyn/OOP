#ifndef PART_H
#define PART_H

#include <string>
#include <QObject>
#include "IdGenerator.h" // Додано підключення для IdGenerator

class Part : public QObject {
    Q_OBJECT
public:
    explicit Part(double p = 0.0, const QString& n = "", QObject* parent = nullptr)
        : QObject(parent), price(p), name(n), id(IdGenerator::getInstance().getNextId()) {} // Встановлення унікального ідентифікатора

    virtual ~Part() {}

    virtual double getPrice() const { return price; }
    virtual QString getName() const { return name; }
    int getId() const { return id; } // Метод для отримання ідентифікатора

    virtual void display() const = 0;

private:
    double price;
    QString name;
    int id; // Поле для зберігання унікального ідентифікатора
};

#endif // PART_H

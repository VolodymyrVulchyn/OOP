#ifndef PART_H
#define PART_H

#include <string>
#include <QObject>

class Part : public QObject {
    Q_OBJECT
public:
    explicit Part(double p = 0.0, const QString& n = "", QObject* parent = nullptr)
        : QObject(parent), price(p), name(n) {}

    virtual ~Part() {}

    virtual double getPrice() const { return price; }
    virtual QString getName() const { return name; }

    virtual void display() const = 0;

private:
    double price;
    QString name;
};

#endif // PART_H

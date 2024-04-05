#pragma once // Запобігає багаторазовому включенню цього заголовочного файлу

#include <string>
#include <iostream>

// Базовий клас для всіх запчастин
class Part {
protected:
    double price; // Ціна запчастини
    std::string name; // Назва запчастини

public:
    Part(double p, std::string n) : price(p), name(n) {} // Конструктор
    virtual ~Part() {} // Віртуальний деструктор

    virtual double getPrice() const { return price; } // Отримати ціну
    virtual std::string getName() const { return name; } // Отримати назву

    virtual void display() const = 0; // Абстрактний метод для відображення інформації про запчастину
};

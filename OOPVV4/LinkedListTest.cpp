#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include "LinkedList.h"
#include "Engine.h"
#include "Oil.h"
#include "BrakePad.h"
#include "BrakeDisc.h"

// функція для перевірки рівності двох чисел типу double і виведення результатів тесту
void assertEqual(double a, double b, const std::string& testName) {
    if (a == b) {
        std::cout << "[ПРОЙДЕНО] " << testName << std::endl;
    } else {
        std::cout << "[НЕ ПРОЙДЕНО] " << testName << " - Очікувано: " << b << ", Отримано: " << a << std::endl;
    }
}

// функція для перевірки рівності двох рядків і виведення результатів тесту
void assertEqual(const std::string& a, const std::string& b, const std::string& testName) {
    if (a == b) {
        std::cout << "[ПРОЙДЕНО] " << testName << std::endl;
    } else {
        std::cout << "[НЕ ПРОЙДЕНО] " << testName << " - Очікувано: " << b << ", Отримано: " << a << std::endl;
    }
}

// тест для методу addfront
void testAddFront() {
    // Створення списку
    LinkedList list;

    // cтворення деяких частин для додавання до списку
    auto engine = std::make_shared<Engine>(5000, "V8 Engine");
    auto oil = std::make_shared<Oil>(50, "Synthetic Motor Oil");
    auto brakePad = std::make_shared<BrakePad>(30, "Ceramic Brake Pads");

    // додавання частин до початку списку
    list.addFront(engine);
    list.addFront(oil);
    list.addFront(brakePad);

    // перенаправлення cout'а до stringstream для захоплення виводу display
    std::stringstream ss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    // виведення списку
    list.display();

    // відновлення std::cout до його початкового стану
    std::cout.rdbuf(oldCoutStreamBuf);
    std::string output = ss.str();

    // очікуваний рядок виводу
    std::string expected = "Brake Pad: Ceramic Brake Pads, Price: 30\nOil: Synthetic Motor Oil, Price: 50\nEngine: V8 Engine, Price: 5000\n";

    // перевірка, на збіг виводу з очікуваним результатом
    assertEqual(output, expected, "testAddFront");
}

// тест для методу remove
void testRemove() {
    // створення списку
    LinkedList list;

    // створення деяких запчастин для додавання до списку
    auto engine = std::make_shared<Engine>(5000, "V8 Engine");
    auto oil = std::make_shared<Oil>(50, "Synthetic Motor Oil");
    auto brakePad = std::make_shared<BrakePad>(30, "Ceramic Brake Pads");

    // додавання частин до початку списку
    list.addFront(engine);
    list.addFront(oil);
    list.addFront(brakePad);

    // видалення частини oil і перевірка, чи була вона видалена
    bool removed = list.remove(oil);
    assertEqual(removed, true, "testRemove (перше видалення)");

    // спроба видалити частину oil знову і перевірка результату
    removed = list.remove(oil);
    assertEqual(removed, false, "testRemove (друге видалення)");

    // перенаправлення cout'а до stringstream для захоплення виводу
    std::stringstream ss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    // виведення списку після видалення
    list.display();

    // відновлення std::cout до його початкового стану
    std::cout.rdbuf(oldCoutStreamBuf);
    std::string output = ss.str();

    // очікуваний рядок виводу після видалення
    std::string expected = "Brake Pad: Ceramic Brake Pads, Price: 30\nEngine: V8 Engine, Price: 5000\n";

    // перевірка, чи збігається вивід з очікуваним результатом
    assertEqual(output, expected, "testRemove (вивід після видалення)");
}

// тест для методу gettotal
void testGetTotal() {
    // створення списку
    LinkedList list;

    // створення деяких запчастин для додавання до списку
    auto engine = std::make_shared<Engine>(5000, "V8 Engine");
    auto oil = std::make_shared<Oil>(50, "Synthetic Motor Oil");
    auto brakePad = std::make_shared<BrakePad>(30, "Ceramic Brake Pads");

    // додавання частин до початку списку
    list.addFront(engine);
    list.addFront(oil);
    list.addFront(brakePad);

    // обчислення загальної вартості частин у списку
    double total = list.getTotal();

    // перевірка, чи збігається загальна сума з очікуваним результатом
    assertEqual(total, 5080, "testGetTotal");
}

// Головна функція для запуску тестів
int main() {
    testAddFront();
    testRemove();
    testGetTotal();
    return 0;
}

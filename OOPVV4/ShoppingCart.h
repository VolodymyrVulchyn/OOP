// #include <vector>
// #include <memory>
// #include <algorithm> // Include for std::remove and std::remove_if
// #include "Part.h"

// // Клас для корзини покупок
// class ShoppingCart {
// private:
//     std::vector<std::shared_ptr<Part>> parts; // Вектор для зберігання запчастин
//     std::vector<std::shared_ptr<Part>> removedParts; // Вектор для зберігання видалених запчастин
    
// public:
//     void addPart(const std::shared_ptr<Part>& part) { // Додати запчастину до корзини
//         parts.push_back(part);
//     }

//     void removePart(const std::shared_ptr<Part>& part) { // Видалити запчастину з корзини
//         // Використання std::remove_if для видалення елемента за умовою
//         auto newEnd = std::remove_if(parts.begin(), parts.end(),
//                                     [&part](const std::shared_ptr<Part>& p) { return p == part; });
//         parts.erase(newEnd, parts.end()); // Видалення всіх елементів після нового кінця вектора
//     }

//     double getTotal() const { // Обчислити загальну суму покупки
//         double total = 0.0;
//         for (const auto& part : parts) {
//             total += part->getPrice();
//         }
//         return total;
//     }

//     void displayCart() const { // Відобразити всі запчастини в корзині
//         for (const auto& part : parts) {
//             part->display();
//         }
//     }

//     // void displayRemovedParts() const { // Відобразити всі видалені запчастини
//     //     for (const auto& part : removedParts) {
//     //         part->display();
//     //     }
//     // }
// };

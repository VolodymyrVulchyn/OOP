// #include <iostream>
// #include <sstream>
// #include <memory>
// #include <string>
// #include "ShoppingCart.h"
// #include "Engine.h"
// #include "Oil.h"
// #include "BrakePad.h"
// #include "BrakeDisc.h"

// // Function to check equality of two double values and print test results
// void assertEqual(double a, double b, const std::string& testName) {
//     if (a == b) {
//         std::cout << "[PASSED] " << testName << std::endl;
//     } else {
//         std::cout << "[FAILED] " << testName << " - Expected: " << b << ", Got: " << a << std::endl;
//     }
// }

// // Function to check equality of two strings and print test results
// void assertEqual(const std::string& a, const std::string& b, const std::string& testName) {
//     if (a == b) {
//         std::cout << "[PASSED] " << testName << std::endl;
//     } else {
//         std::cout << "[FAILED] " << testName << " - Expected: " << b << ", Got: " << a << std::endl;
//     }
// }

// // Test for addPart method
// void testAddPart() {
//     ShoppingCart cart;

//     // Create some parts to add to the cart
//     auto engine = std::make_shared<Engine>(5000, "V8 Engine");
//     auto oil = std::make_shared<Oil>(50, "Synthetic Motor Oil");

//     // Add parts to the cart
//     cart.addPart(engine);
//     cart.addPart(oil);

//     // Redirect cout to stringstream to capture display output
//     std::stringstream ss;
//     std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
//     std::cout.rdbuf(ss.rdbuf());

//     // Display cart
//     cart.displayCart();

//     // Restore std::cout to its original state
//     std::cout.rdbuf(oldCoutStreamBuf);
//     std::string output = ss.str();

//     // Expected output string
//     std::string expected = "Engine: V8 Engine, Price: 5000\nOil: Synthetic Motor Oil, Price: 50\n";

//     // Check if the output matches the expected result
//     assertEqual(output, expected, "testAddPart");
// }

// // Test for removePart method
// void testRemovePart() {
//     ShoppingCart cart;

//     // Create some parts to add to the cart
//     auto engine = std::make_shared<Engine>(5000, "V8 Engine");
//     auto oil = std::make_shared<Oil>(50, "Synthetic Motor Oil");

//     // Add parts to the cart
//     cart.addPart(engine);
//     cart.addPart(oil);

//     // Remove a part from the cart and check if it was removed
//     cart.removePart(oil);
//     cart.removePart(engine);

//     // Redirect cout to stringstream to capture display output
//     std::stringstream ss;
//     std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
//     std::cout.rdbuf(ss.rdbuf());

//     // Display cart
//     cart.displayCart();

//     // Restore std::cout to its original state
//     std::cout.rdbuf(oldCoutStreamBuf);
//     std::string output = ss.str();

//     // Expected output string after removal
//     std::string expected = "";

//     // Check if the output matches the expected result
//     assertEqual(output, expected, "testRemovePart");
// }

// // Test for getTotal method
// void testGetTotal() {
//     ShoppingCart cart;

//     // Create some parts to add to the cart
//     auto engine = std::make_shared<Engine>(5000, "V8 Engine");
//     auto oil = std::make_shared<Oil>(50, "Synthetic Motor Oil");
//     auto brakePad = std::make_shared<BrakePad>(30, "Ceramic Brake Pads");

//     // Add parts to the cart
//     cart.addPart(engine);
//     cart.addPart(oil);
//     cart.addPart(brakePad);

//     // Calculate total price of parts in the cart
//     double total = cart.getTotal();

//     // Check if the total matches the expected result
//     assertEqual(total, 5080.0, "testGetTotal");
// }

// // Test for removePartByName method
// void testRemovePartByName() {
//     ShoppingCart cart;

//     // Create some parts to add to the cart
//     auto engine = std::make_shared<Engine>(5000, "V8 Engine");
//     auto oil1 = std::make_shared<Oil>(50, "Synthetic Motor Oil");
//     auto brakePad = std::make_shared<BrakePad>(30, "Synthetic Motor Oil");

//     // Add parts to the cart
//     cart.addPart(engine);
//     cart.addPart(oil1);
//     cart.addPart(brakePad);

//     // Remove part by name
//     cart.removePartByName("Synthetic Motor Oil");

//     // Redirect cout to stringstream to capture display output
//     std::stringstream ss;
//     std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
//     std::cout.rdbuf(ss.rdbuf());

//     // Display cart after removal
//     cart.displayCart();

//     // Restore std::cout to its original state
//     std::cout.rdbuf(oldCoutStreamBuf);
//     std::string output = ss.str();

//     // Expected output string after removing the oil part with the highest price
//     std::string expected = "Engine: V8 Engine, Price: 5000\nOil: Synthetic Motor Oil, Price: 50\n";

//     // Check if the output matches the expected result
//     assertEqual(output, expected, "testRemovePartByName");
// }

// // Main function to run the tests
// int main() {
//     testAddPart();
//     testRemovePart();
//     testGetTotal();
//     testRemovePartByName();
//     return 0;
// }

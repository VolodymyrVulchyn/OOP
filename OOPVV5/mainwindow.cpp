#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Engine.h"
#include "Oil.h"
#include "BrakeDisc.h"
#include "BrakePad.h"
#include "CoolingSystem.h"
#include "FuelSystem.h"
#include "Lights.h"
#include "Radiator.h"
#include "SparkPlug.h"
#include "Suspension.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->partComboBox->addItems({"Engine", "Oil", "Brake Disc", "Brake Pad", "Cooling System", "Fuel System", "Lights", "Radiator", "Spark Plug", "Suspension"});
    connect(ui->addToCartButton, &QPushButton::clicked, this, &MainWindow::addToCartClicked);
    connect(ui->removeFromCartButton, &QPushButton::clicked, this, &MainWindow::removeFromCartClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addToCartClicked() {
    double price = ui->priceLineEdit->text().toDouble();
    QString name = ui->nameLineEdit->text();
    std::shared_ptr<Part> part;

    // Check if the selected part exists
    if (ui->partComboBox->findText(name) != -1) {
        // Check if the selected part is a valid part for adding
        if (isValidPart(name)) {
            if (name == "Engine") {
                part = std::make_shared<Engine>(price, name);
            } else if (name == "Oil") {
                part = std::make_shared<Oil>(price, name);
            } else if (name == "Brake Disc") {
                part = std::make_shared<BrakeDisc>(price, name);
            } else if (name == "Brake Pad") {
                part = std::make_shared<BrakePad>(price, name);
            } else if (name == "Cooling System") {
                part = std::make_shared<CoolingSystem>(price, name);
            } else if (name == "Fuel System") {
                part = std::make_shared<FuelSystem>(price, name);
            } else if (name == "Lights") {
                part = std::make_shared<Lights>(price, name);
            } else if (name == "Radiator") {
                part = std::make_shared<Radiator>(price, name);
            } else if (name == "Spark Plug") {
                part = std::make_shared<SparkPlug>(price, name);
            } else if (name == "Suspension") {
                part = std::make_shared<Suspension>(price, name);
            }
        } else {
            QMessageBox::warning(this, "Invalid Part", "The entered part is not valid for adding to the cart.");
        }
    } else {
        QMessageBox::warning(this, "Invalid Part", "The entered part does not exist.");
    }

    // Check if the part was created successfully
    if (part) {
        cart.addPart(part);
        ui->cartTextEdit->append(QString("%1 - $%2 ID: %3").arg(part->getName()).arg(QString::number(part->getPrice(), 'f', 2)).arg(part->getId())); // Додамо виведення ідентифікатора у корзину
        updateTotalPrice();
    }
}

bool MainWindow::isValidPart(const QString &partName) {
    QStringList validParts = {"Engine", "Oil", "Brake Disc", "Brake Pad", "Cooling System", "Fuel System", "Lights", "Radiator", "Spark Plug", "Suspension"};
    return validParts.contains(partName);
}

void MainWindow::removeFromCartClicked() {
    QString nameToRemove = ui->nameToRemoveLineEdit->text();
    cart.removePartByName(nameToRemove);
    ui->cartTextEdit->clear();
    for (const auto& part : cart.getParts()) {
        ui->cartTextEdit->append(QString("%1 - $%2 ID: %3").arg(part->getName()).arg(QString::number(part->getPrice(), 'f', 2)).arg(part->getId())); // Додамо виведення ідентифікатора у корзину
    }
    updateTotalPrice();
}

void MainWindow::updateTotalPrice() {
    double totalPrice = 0.0;
    for (const auto& part : cart.getParts()) {
        totalPrice += part->getPrice();
    }
    ui->totalPriceLabel->setText("Total Price: $" + QString::number(totalPrice, 'f', 2));
}

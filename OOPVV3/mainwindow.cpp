// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Engine.h"
#include "Oil.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addToCartButton_clicked()
{
    double price = ui->priceLineEdit->text().toDouble();
    QString name = ui->nameLineEdit->text();

    // Додавання запчастин до корзини
    if (ui->partComboBox->currentText() == "Engine") {
        std::shared_ptr<Part> part = std::make_shared<Engine>(price, name);
        cart.addPart(part);
        ui->cartTextEdit->append(part->getName());
    } else if (ui->partComboBox->currentText() == "Oil") {
        std::shared_ptr<Part> part = std::make_shared<Oil>(price, name);
        cart.addPart(part);
        ui->cartTextEdit->append(part->getName());
    } // Додайте інші типи запчастин
}

void MainWindow::on_removeFromCartButton_clicked()
{
    QString nameToRemove = ui->nameToRemoveLineEdit->text();
    cart.removePartByName(nameToRemove);
    ui->cartTextEdit->clear();
    for (const auto& part : cart.getParts()) {
        ui->cartTextEdit->append(part->getName());
    }
}

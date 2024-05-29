#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ShoppingCart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addToCartClicked();
    void removeFromCartClicked();
    void updateTotalPrice();
    bool isValidPart(const QString &partName);

private:
    Ui::MainWindow *ui;
    ShoppingCart cart;
};

#endif // MAINWINDOW_H

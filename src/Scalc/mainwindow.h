#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <iostream>

#include "credit.h"
#include "graphics.h"

extern "C" {
#include "../s21_SmartCalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  graphics *g;
  credit *c;

 private slots:
  void press_button();
  void press_del();
  void press_ac();
  void press_func();
  void press_eq();
  void press_graph();
  void press_credit();
  void showMainWindow();
  void closeApplication();
};
#endif  // MAINWINDOW_H

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QCloseEvent>
#include <QMainWindow>
#include <QVector>

extern "C" {
#include "../s21_SmartCalc.h"
}

namespace Ui {
class graphics;
}

class graphics : public QMainWindow {
  Q_OBJECT

 signals:
  void backButtonClicked();
  void graphicsWindowClosed();

 public:
  explicit graphics(QWidget *parent = nullptr);
  ~graphics();
  void build_grafic(const QString &expression);

 protected:
  void closeEvent(QCloseEvent *event) override;

 private:
  Ui::graphics *ui;
  double xMin = -10;
  double xMax = 10;
  double yMin = -10;
  double yMax = 10;
  QString expression;
  void plotFunction(QString expression);

 private slots:
  void calcul();
  void update();
};

#endif  // GRAPHICS_H

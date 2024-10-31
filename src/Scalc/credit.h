#ifndef CREDIT_H
#define CREDIT_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class credit;
}

class credit : public QMainWindow {
  Q_OBJECT

 signals:
  void backClicked();
  void creditWindowClosed();

 public:
  explicit credit(QWidget *parent = nullptr);
  ~credit();

 private slots:
  void calcul();
  void update(double percent, double sum, int date, bool var);
  void calcul_credit();

 protected:
  void closeEvent(QCloseEvent *event) override;

 private:
  Ui::credit *ui;
  double annPayment(double sum, double rate, int date);
};

#endif  // CREDIT_H

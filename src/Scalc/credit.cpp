#include "credit.h"

#include "ui_credit.h"

credit::credit(QWidget *parent) : QMainWindow(parent), ui(new Ui::credit) {
  ui->setupUi(this);

  connect(ui->pushButton_back, SIGNAL(clicked()), this, SLOT(calcul()));
  connect(ui->pushButton_update, SIGNAL(clicked()), this,
          SLOT(calcul_credit()));
}

credit::~credit() { delete ui; }

void credit::calcul() {
  emit backClicked();
  hide();
}

void credit::closeEvent(QCloseEvent *event) { emit creditWindowClosed(); }

void credit::calcul_credit() {
  bool error;
  bool exit = false;

  QString value = ui->sum->text();
  double c_sum = value.toDouble(&error);
  if (c_sum <= 0 || error == false) {
    QMessageBox::critical(this, "Error", "Ошибка в поле кредита");
    exit = true;
  }

  value = ui->percent->text();
  double c_percent = value.toDouble(&error);
  if (c_percent <= 0 || error == false) {
    QMessageBox::critical(this, "Error", "Ошибка в поле процента");
    exit = true;
  }

  value = ui->date->text();
  int c_time = value.toInt(&error);
  if (c_time <= 0 || error == false) {
    QMessageBox::critical(this, "Error", "Ошибка в поле времени");
    exit = true;
  }

  if (exit == false) {
    bool var = true;
    if (ui->dif->isChecked()) var = false;
    update(c_percent, c_sum, c_time, var);
  }
}

void credit::update(double percent, double sum, int date, bool var) {
  ui->table->setRowCount(date);

  if (var == false) {
    double rate = 0;
    double monthly_rate = percent / 100 / 12;
    double sum_balance = sum;
    double pay = 0;

    for (int i = 0; sum_balance > 0; i++) {
      rate = sum_balance * monthly_rate;
      sum_balance = sum_balance - (sum / date);
      pay = sum / date + rate;

      ui->table->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
      ui->table->setItem(i, 1,
                         new QTableWidgetItem(QString::number(pay, 'f', 2)));
    }
  } else {
    double result = annPayment(sum, percent / 100, date);
    for (int i = 0; i < date; i++) {
      ui->table->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
      ui->table->setItem(i, 1,
                         new QTableWidgetItem(QString::number(result, 'f', 2)));
    }
  }
}

double credit::annPayment(double sum, double rate, int date) {
  double month_rate = rate / 12.0;
  double annFactor = (month_rate * pow(1 + month_rate, date)) /
                     (pow(1 + month_rate, date) - 1);
  return sum * annFactor;
}

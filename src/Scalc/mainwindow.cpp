#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "graphics.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_pl, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_mi, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_mu, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_di, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_br, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_deg, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_bl, SIGNAL(clicked()), this, SLOT(press_button()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(press_button()));

  connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(press_del()));
  connect(ui->pushButton_ac, SIGNAL(clicked()), this, SLOT(press_ac()));

  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(press_func()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(press_func()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(press_func()));
  connect(ui->pushButton_arcsin, SIGNAL(clicked()), this, SLOT(press_func()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(press_func()));
  connect(ui->pushButton_arccos, SIGNAL(clicked()), this, SLOT(press_func()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(press_func()));
  connect(ui->pushButton_arctan, SIGNAL(clicked()), this, SLOT(press_func()));
  connect(ui->pushButton_In, SIGNAL(clicked()), this, SLOT(press_func()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(press_func()));
  connect(ui->pushButton_eq, SIGNAL(clicked()), this, SLOT(press_eq()));

  connect(ui->pushButton_graph, SIGNAL(clicked()), this, SLOT(press_graph()));
  connect(ui->pushButton_credit, SIGNAL(clicked()), this, SLOT(press_credit()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::press_button() {
  QPushButton *button = (QPushButton *)sender();

  if (ui->result->text().isEmpty()) {
    ui->result->setText(button->text());
  } else {
    ui->result->setText(ui->result->text() + button->text());
  }
}

void MainWindow::press_del() {
  QString str = ui->result->text();
  if (!str.isEmpty()) {
    str.chop(1);
  }
  ui->result->setText(str);
}

void MainWindow::press_ac() { ui->result->setText(""); }

void MainWindow::press_func() {
  QPushButton *button = (QPushButton *)sender();
  ui->result->setText(ui->result->text() + button->text() + "(");
}

void MainWindow::press_eq() {
  char *expression = new char(ui->result->text().length());
  QByteArray barr = ui->result->text().toLatin1();
  strlcpy(expression, barr, ui->result->text().length() + 1);

  char *value_of_x_str = new char(ui->value_of_x->text().length());
  QByteArray barr_of_x = ui->value_of_x->text().toLatin1();
  strlcpy(value_of_x_str, barr_of_x, ui->value_of_x->text().length() + 1);

  if (ui->result->text().contains('x') &&
      (ui->value_of_x->text().length() == 0 ||
       !ui->value_of_x->text().toDouble())) {
    QMessageBox::critical(this, "error", "Некорректный ввод");
  } else {
    double result = 0.0;
    int error = calculator(expression, value_of_x_str, &result);

    if (error == 0) {
      QString valueAsString = QString::number(result, 'g', 15);
      ui->result->setText(valueAsString);
    } else if (error == 1) {
      QMessageBox::critical(this, "error", "Некорректный ввод");
    } else if (error == 2) {
      QMessageBox::critical(this, "error", "В Выражении более 255 символов");
    }
  }
  delete (expression);
  delete (value_of_x_str);
}

void MainWindow::press_graph() {
  hide();
  g = new graphics(this);
  connect(g, &graphics::backButtonClicked, this, &MainWindow::showMainWindow);
  connect(g, &graphics::graphicsWindowClosed, this,
          &QApplication::quit);  // Подключаем сигнал к слоту quit()

  QString input_str = ui->result->text();

  g->show();
  g->build_grafic(input_str);
}

void MainWindow::showMainWindow() { show(); }

void MainWindow::closeApplication() { close(); }

void MainWindow::press_credit() {
  hide();

  c = new credit(this);
  connect(c, &credit::backClicked, this, &MainWindow::showMainWindow);
  connect(c, &credit::creditWindowClosed, this, &QApplication::quit);

  c->show();
}

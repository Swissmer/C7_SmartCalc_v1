#include "graphics.h"

#include <qmath.h>

#include <QMessageBox>
#include <QVector>
#include <QtMath>

#include "ui_graphics.h"

graphics::graphics(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::graphics) {
  ui->setupUi(this);
  connect(ui->pushButton_calc, &QPushButton::clicked, this, &graphics::calcul);
  connect(ui->update, &QPushButton::clicked, this, &graphics::update);
}

graphics::~graphics() { delete ui; }

void graphics::calcul() {
  emit backButtonClicked();
  hide();
}

void graphics::closeEvent(QCloseEvent *event) { emit graphicsWindowClosed(); }

void graphics::build_grafic(const QString &expression) {
  this->expression = expression;
  plotFunction(expression);
}

void graphics::plotFunction(QString expression) {
  QByteArray byteArray = expression.toUtf8();
  char *expressionChar = byteArray.data();

  ui->widget->clearGraphs();
  QVector<double> X, Y;
  double d_step = 0.1;

  for (double x = xMin; x <= xMax; x += d_step) {
    char str_of_x[256] = "";
    memset(str_of_x, '\0', 256);
    snprintf(str_of_x, sizeof(str_of_x), "%lf", x);

    double result = 0.0;
    int error = calculator(expressionChar, str_of_x, &result);

    X.push_back(x);
    Y.push_back(result);
  }

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(X, Y);
  ui->widget->xAxis->setRange(xMin, xMax);
  ui->widget->yAxis->setRange(yMin, yMax);
  ui->widget->replot();
}

void graphics::update() {
  bool ok1, ok2, ok3, ok4;
  xMin = ui->min_x->text().toDouble(&ok1);
  xMax = ui->max_x->text().toDouble(&ok2);
  yMin = ui->min_y->text().toDouble(&ok3);
  yMax = ui->max_y->text().toDouble(&ok4);

  if (!ok1 || !ok2 || !ok3 || !ok4) {
    QMessageBox::critical(this, "Error", "Неверные значения границ");
    return;
  }
  plotFunction(this->expression);
}

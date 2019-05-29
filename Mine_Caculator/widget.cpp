#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_2_returnPressed()
{
    double a,b;
    a=ui->lineEdit->text().toDouble();
    b=ui->lineEdit_2->text().toDouble();
    switch(ui->comboBox->currentIndex())
    {
    case 0:
        ui->lineEdit_3->setText(QString::number(a+b));
        break;
    case 1:
        ui->lineEdit_3->setText(QString::number(a-b));
        break;
    case 2:
        ui->lineEdit_3->setText(QString::number(a*b));
        break;
    case 3:
        if(fabs(b)<=1e-9)
            ui->lineEdit_3->setText("Error");
        else
            ui->lineEdit_3->setText(QString::number(a/b));
        break;
    case 4:
        ui->lineEdit_3->setText(QString::number(pow(a,b)));
        break;
    }
}

void Widget::on_lineEdit_returnPressed()
{
    Widget::on_lineEdit_2_returnPressed();
}

void Widget::on_lineEdit_3_returnPressed()
{
    Widget::on_lineEdit_2_returnPressed();
}

void Widget::on_pushButton_clicked()
{
    Widget::on_lineEdit_2_returnPressed();
}

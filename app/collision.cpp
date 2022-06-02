#include "collision.h"
#include "ui_collision.h"

collision::collision(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::collision)
{
    ui->setupUi(this);
}

collision::~collision()
{
    delete ui;
}

void collision::on_return_col_clicked()
{
    parentWidget()->show();
    this->close();
}


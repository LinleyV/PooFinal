#include "modify.h"
#include "ui_modify.h"
#include "mainwindow.h"
#include <sstream>
#include <QtCore/QString>
#include <QErrorMessage>
#include <QMessageBox>
#include <QInputDialog>
#include "POO_Project/System_Class/System.h"
#include "POO_Project/Ball_Class/Balle.h"
#include "POO_Project/Integrateurs/Integrateur_EulerCromer/Cromer.h"
#include "POO_Project/Integrateurs/Integrateur_Newmark/Newmark.h"
#include "POO_Project/Integrateurs/Integrateur_RungKutta/Runge-Kutta.h"
Modify::Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
    ui->verticalLayoutWidget_2->hide();
    ui->verticalLayoutWidget_4->hide();
    ui->back_btn->setHidden(true);
    mw = nullptr;
    system = nullptr;
    add = nullptr;
    ui->col_btn->setHidden(true);
    ui->spinBox->setMaximum(10000);
}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_buttonBox_accepted()
{
    ui->verticalLayoutWidget->close();
    ui->verticalLayoutWidget_2->show();
    system = new System();
}


void Modify::on_buttonBox_rejected()
{
    mw = new MainWindow(this);
    hide();
    mw->show();
}
void Modify::on_add_btn_clicked()
{
    add = new ADD_(this, system);
    hide();
    add->show();
    std::stringstream out;
    out << *system;
    ui->textBrowser->insertPlainText(QString::fromStdString(out.str()));
}


void Modify::on_evolve_btn_clicked()
{
    if(system->get_pointer_mobile_object() == nullptr)
    {
         QMessageBox::information(this, tr("Error"), tr("Empty system!"));
    }
  else{
     ui->verticalLayoutWidget_2->hide();
  ui->verticalLayoutWidget_4->show();
   ui->back_btn->setHidden(false);
}
}

void Modify::on_update_clicked()
{
        std::stringstream out;
        out << *system;
        ui->textBrowser->clear();
        ui->textBrowser->insertPlainText(QString::fromStdString(out.str()));
}


void Modify::on_cromer_clicked()
{
    ui->back_btn->setHidden(true);
    int times = ui->spinBox->value();
    double dt = ui->doubleSpinBox->value();
    if(times == 0 or dt == 0)
    {
        QMessageBox::information(this, tr("Error"), tr("Incorect Values"));
    }
    else{
    Cromer integ(dt);
    for(int i = 1; i <= times; ++i)
    {
        system->RUN_SYST(integ);
        std::stringstream out;
        out << *system;
        ui->textBrowser->insertPlainText(QString::fromStdString(out.str()));
    }
    ui->verticalLayoutWidget_2->show();
    ui->verticalLayoutWidget_4->hide();
}
}

void Modify::on_quitt_clicked()
{
    QApplication::exit();
}


void Modify::on_nemark_clicked()
{
    ui->back_btn->setHidden(true);
    int times = ui->spinBox->value();
    double dt = ui->doubleSpinBox->value();
    Newmark integ(dt);
    if(times == 0 or dt == 0)
    {
        QMessageBox::information(this, tr("Error"), tr("Incorect Values"));
    }
    else{
    for(int i = 1; i <= times; ++i)
    {
        system->RUN_SYST(integ);
        std::stringstream out;
        out << *system;
        ui->textBrowser->insertPlainText(QString::fromStdString(out.str()));
    }
    ui->verticalLayoutWidget_2->show();
    ui->verticalLayoutWidget_4->hide();
}
}

void Modify::on_kutta_clicked()
{
    ui->back_btn->setHidden(true);
    int times = ui->spinBox->value();
    double dt = ui->doubleSpinBox->value();
    RungeKutta integ(dt);
    if(times == 0 or dt == 0)
    {
        QMessageBox::information(this, tr("Error"), tr("Incorect Values"));
    }
    else
    {
    for(int i = 1; i <= times; ++i)
    {
        system->RUN_SYST(integ);
        std::stringstream out;
        out << *system;
        ui->textBrowser->insertPlainText(QString::fromStdString(out.str()));
    }
    ui->verticalLayoutWidget_2->show();
    ui->verticalLayoutWidget_4->hide();
}
}

void Modify::on_back_btn_clicked()
{
    ui->back_btn->setHidden(true);
    ui->verticalLayoutWidget_4->hide();
    ui->verticalLayoutWidget_2->show();
}


void Modify::on_del_btn_clicked()
{
    if(system->get_pointer_force() == nullptr and system->get_pointer_mobile_object(0) == nullptr and system->get_pointer_obstacle(0) == 0)
    {
        QMessageBox::information(this, tr("Error"), tr("Nothing to delete"));
        return;
    }
    else
    {
        QString read = QInputDialog::getText(this, tr("Delete"),
                                             tr("Please specify the item you want to delete!"
                                                "FORCE, OBJECT, OBSTACLE followed by the position (separated by a space)"));
        QString aux;
        int number = read[read.size() - 1].digitValue() - 1;
        for(int i = 0; i < read.size(); ++i)
        {
            if(read[i] != ' ')
            {
                aux += read[i];
            }
            else
               {
                i++;
                break;
            }
        }
        if(aux == "FORCE")
        {
            system->delete_force(number);
        }
        if(aux == "OBJECT")
        {
            system->delete_object(number);
        }
        if(aux == "OBSTACLE")
        {
            system->delete_obstacle(number);
        }
    }
}


void Modify::on_col_btn_clicked()
{
    coll_ = new collision(this);
    hide();
    coll_->show();
}


#include "add_obstacle.h"
#include "ui_add_obstacle.h"
#include <QInputDialog>
#include "POO_Project/Brique_Class/Brique.h"
#include "POO_Project/Plan_Class/Plan.h"
#include <QMessageBox>
#include <sstream>
#include <QtCore/QString>

add_obstacle::add_obstacle(QWidget *parent, System* system) :
    QDialog(parent),
    ui(new Ui::add_obstacle), system(system), position({0,0,0}), lenght({0,0,0}), normal({0,0,0}), width({0,0,0})
{
    ui->setupUi(this);
    ui->verticalLayoutWidget_2->hide();
    ui->verticalLayoutWidget_3->hide();
    ui->verticalLayoutWidget_4->hide();
    ui->return_c->setEnabled(false);
}

add_obstacle::~add_obstacle()
{
    delete ui;
}

void add_obstacle::on_return_2_clicked()
{
    parentWidget()->show();
    this->close();
}


void add_obstacle::on_return_c_clicked()
{
    ui->verticalLayoutWidget_2->hide();
    ui->verticalLayoutWidget_3->hide();
    ui->horizontalLayoutWidget->show();
    ui->return_c->setEnabled(false);
    ui->go_btn->setHidden(true);
}


void add_obstacle::on_plan_clicked()
{
    obs_add = "plan";
    ui->horizontalLayoutWidget->hide();
    ui->return_c->setEnabled(true);
    ui->verticalLayoutWidget_3->show();
    ui->verticalLayoutWidget_4->show();
    ui->go_btn->setHidden(false);
}


void add_obstacle::on_brique_clicked()
{
    obs_add = "brique";
    ui->horizontalLayoutWidget->hide();
    ui->return_c->setEnabled(true);
    ui->verticalLayoutWidget_2->show();
    ui->verticalLayoutWidget_4->show();
    ui->go_btn->setHidden(false);
}


void add_obstacle::on_position__clicked()
{
    ui->return_c->setEnabled(false);
    bool ok;
    QString read = QInputDialog::getText(this, tr("Position"),tr("3 Coord please"), QLineEdit::Normal, tr("0 0 0"), &ok);
    if(!ok)
        return;
    int n = read.size();
    QString aux = "";
    read += " ";
    std::vector<double> list;
    int j = 0;
    while(read[j] == ' ')
        j++;
    for(int i = j ; i < n; ++i)
    {
        if(read[i] ==' ' and read[i + 1] != ' ')
        {
            list.push_back(aux.toDouble());
            aux = "";
        }
        else
        {
            if(read[i] != ' ')
            aux += read[i];
        }
    }
    if(list.size() != 3)
    list.push_back(aux.toDouble());
    Vecteur v({list[0], list[1], list[2]});
    position = v;
    ui->position_->setEnabled(false);
}


void add_obstacle::on_normal__clicked()
{
    ui->return_c->setEnabled(false);
    bool ok;
    QString read = QInputDialog::getText(this, tr("Normal"),tr("3 Coord please"), QLineEdit::Normal, tr("0 0 0"), &ok);
    if(!ok)
        return;
    int n = read.size();
    QString aux = "";
    read += " ";
    std::vector<double> list;
    int j = 0;
    while(read[j] == ' ')
        j++;
    for(int i = j ; i < n; ++i)
    {
        if(read[i] ==' ' and read[i + 1] != ' ')
        {
            list.push_back(aux.toDouble());
            aux = "";
        }
        else
        {
            if(read[i] != ' ')
            aux += read[i];
        }
    }
    if(list.size() != 3)
    list.push_back(aux.toDouble());
    Vecteur v({list[0], list[1], list[2]});
    normal = v;
    ui->normal_->setEnabled(false);
}


void add_obstacle::on_position_b_clicked()
{
    ui->return_c->setEnabled(false);
    bool ok;
    QString read = QInputDialog::getText(this, tr("Position"),tr("3 Coord please"), QLineEdit::Normal, tr("0 0 0"), &ok);
    if(!ok)
        return;
    int n = read.size();
    QString aux = "";
    read += " ";
    std::vector<double> list;
    int j = 0;
    while(read[j] == ' ')
        j++;
    for(int i = j ; i < n; ++i)
    {
        if(read[i] ==' ' and read[i + 1] != ' ')
        {
            list.push_back(aux.toDouble());
            aux = "";
        }
        else
        {
            if(read[i] != ' ')
            aux += read[i];
        }
    }
    if(list.size() != 3)
    list.push_back(aux.toDouble());
    Vecteur v({list[0], list[1], list[2]});
    position = v;
    ui->position_b->setEnabled(false);
}


void add_obstacle::on_lenght_1_clicked()
{
    ui->return_c->setEnabled(false);
    bool ok;
    QString read = QInputDialog::getText(this, tr("Lenght"),tr("3 Coord please"), QLineEdit::Normal, tr("0 0 0"), &ok);
    if(!ok)
        return;
    int n = read.size();
    QString aux = "";
    read += " ";
    std::vector<double> list;
    int j = 0;
    while(read[j] == ' ')
        j++;
    for(int i = j ; i < n; ++i)
    {
        if(read[i] ==' ' and read[i + 1] != ' ')
        {
            list.push_back(aux.toDouble());
            aux = "";
        }
        else
        {
            if(read[i] != ' ')
            aux += read[i];
        }
    }
    if(list.size() != 3)
    list.push_back(aux.toDouble());
    Vecteur v({list[0], list[1], list[2]});
    lenght = v;
    ui->lenght_1->setEnabled(false);
}


void add_obstacle::on_width_1_clicked()
{
    ui->return_c->setEnabled(false);
    bool ok;
    QString read = QInputDialog::getText(this, tr("Width"),tr("3 Coord please"), QLineEdit::Normal, tr("0 0 0"), &ok);
    if(!ok)
        return;
    int n = read.size();
    QString aux = "";
    read += " ";
    std::vector<double> list;
    int j = 0;
    while(read[j] == ' ')
        j++;
    for(int i = j ; i < n; ++i)
    {
        if(read[i] ==' ' and read[i + 1] != ' ')
        {
            list.push_back(aux.toDouble());
            aux = "";
        }
        else
        {
            if(read[i] != ' ')
            aux += read[i];
        }
    }
    if(list.size() != 3)
    list.push_back(aux.toDouble());
    Vecteur v({list[0], list[1], list[2]});
    width = v;
    ui->width_1->setEnabled(false);
}


void add_obstacle::on_height_1_clicked()
{
    ui->return_c->setEnabled(false);
    bool ok;
    QString read = QInputDialog::getText(this, tr("Height"),tr("1 Coord please"), QLineEdit::Normal, tr("0 0 0"), &ok);
    if(!ok)
        return;
    height = read.toDouble();
    ui->height_1->setEnabled(false);
}


void add_obstacle::on_go_btn_clicked()
{
    if(obs_add == "plan")
    {
        if(normal == Vecteur{0,0,0})
        {
            QMessageBox::information(this, tr("Error"), tr("Incorect Values"));
            return;
            ui->normal_->setEnabled(true);
        }
        else
        {
            Plan p(position, normal);
            system->add_Obstacle(p);
        }
    }
    if(obs_add == "brique")
    {
        if(lenght == Vecteur{0,0,0} or width ==  Vecteur{0,0,0} or height == 0)
        {
            QMessageBox::information(this, tr("Error"), tr("Incorect Values"));
            return;
            if(lenght == Vecteur{0,0,0})
                ui->lenght_1->setEnabled(true);
            if(width == Vecteur{0,0,0})
                ui->width_1->setEnabled(true);
            if(height == 0)
                ui->height_1->setEnabled(true);
        }
        else
        {
            Brique b(position, lenght, width, height);
            system->add_Obstacle(b);
        }
    }
    std::stringstream out;
    out << *system;
    ui->textBrowser->insertPlainText(QString::fromStdString(out.str()));
    on_return_2_clicked();

}


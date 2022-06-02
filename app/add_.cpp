#include "add_.h"
#include "ui_add_.h"
#include <sstream>
#include <QtCore/QString>
#include <QInputDialog>
#include <QMessageBox>
#include "POO_Project/Ball_Class/Balle.h"
#include "POO_Project/Week_4_Pendule/Pendule.h"
#include "POO_Project/Spherical_Pendulum/PenduleSpherique.h"
#include "POO_Project/Ressort_Class/Ressort.h"
#include "add_obstacle.h"
ADD_::ADD_(QWidget *parent, System *system) :
    QDialog(parent), system(system),
    ui(new Ui::ADD_), position({0,0,0}), velocity({0,0,0}), intensity({0,0,0}), origin({0,0,0}), direction({0,0,0})
{
    ui->setupUi(this);
    ui->gridLayoutWidget->hide();
    ui->verticalLayoutWidget_2->hide();
    ui->horizontalLayoutWidget_2->hide();
    ui->textBrowser->setPlainText("Current SYSTEM!");
    ui->verticalLayoutWidget_4->hide();
    ui->verticalLayoutWidget_5->hide();
    ui->return_c->setHidden(true);

    ui->mass_->setDecimals(15);
    ui->lenght_->setDecimals(10);
    ui->radius_->setDecimals(10);
    ui->coeff_->setDecimals(10);
    ui->friction_->setDecimals(10);
    ui->return_btn->setHidden(true);
    ui->go_btn->setHidden(true);
}

ADD_::~ADD_()
{
    delete ui;
}

void ADD_::on_obj_m_btn_clicked()
{
    ui->horizontalLayoutWidget->hide();
    ui->gridLayoutWidget->show();
    ui->return_c->setHidden(false);
}


void ADD_::on_ball_btn_clicked()
{
    ui->gridLayoutWidget->hide();
    ui->verticalLayoutWidget_2->show();
    ui->pos->setText("3 Coordinates!");
    ui->vel->setText("3 Coordinates!");
    to_add = "ball";
    ui->return_btn->setHidden(false);
    ui->go_btn->setHidden(false);
}


void ADD_::on_mass__editingFinished()
{

}


void ADD_::on_return_btn_clicked()
{
    ui->return_btn->setHidden(true);
    ui->go_btn->setHidden(true);
    ui->gridLayoutWidget->show();
    ui->verticalLayoutWidget_2->hide();
    ui->horizontalLayoutWidget_2->hide();
    ui->verticalLayoutWidget_4->hide();
    to_add = "0";
}


void ADD_::on_go_btn_clicked()
{
    double mass = ui->mass_->value();
    double radius = ui->radius_->value();
    double lenght = ui->lenght_->value();
    double coeff = ui->coeff_->value();
    double friction = ui->friction_->value();
    if(to_add == "ball")
    {
        if(mass == 0 or radius == 0)
        {
             QMessageBox::information(this, tr("Error"), tr("Incorect Values"));
             return;
        }
        Balle b(position, velocity, {0,0,0}, radius, mass);
        system->add_Mobile_Object(b);
    }
    if(to_add == "pendulum")
    {
        if(direction == Vecteur{0,0,0} or lenght == 0)
        {
            QMessageBox::information(this, tr("Error"), tr("Incorect Values"));
            return;
        }
        Pendule p(position.get_vector()[0], velocity.get_vector()[0], {0,0,0}, radius, mass, origin, direction, lenght, coeff);
        system->add_Mobile_Object(p);
    }
    if(to_add == "spherical_pendulum")
    {
        if(direction == Vecteur{0,0,0} or lenght == 0)
        {
            QMessageBox::information(this, tr("Error"), tr("Incorect Values"));
            return;
        }
        PenduleSpherique p(position.get_vector()[0], velocity.get_vector()[0], position.get_vector()[1], velocity.get_vector()[1]
                , {0,0,0}, radius, mass, origin, direction, lenght, coeff);
        system->add_Mobile_Object(p);
    }
    if(to_add == "ressort")
    {
        if(direction == Vecteur{0,0,0} or coeff == 0)
        {
            QMessageBox::information(this, tr("Error"), tr("Incorect Values"));
            return;
        }
        Ressort r (position, velocity, {0,0,0}, mass, friction, coeff, direction, origin);
        system->add_Mobile_Object(r);
        ui->friction_->setHidden(true);
        ui->label_3->setHidden(true);
    }
    std::stringstream out;
    out << *system;
    ui->textBrowser->insertPlainText(QString::fromStdString(out.str()));
    on_return_btn_clicked();
    ui->pos_->setEnabled(true);
    ui->vel_->setEnabled(true);
    ui->origin_->setEnabled(true);
    ui->direction_->setEnabled(true);
    ui->lenght->setHidden(false);
    ui->lenght_->setHidden(false);
     ui->return_2->setHidden(false);
     ui->return_c->setHidden(false);
}

void ADD_::on_return_2_clicked()
{
    parentWidget()->show();
    this->close();
}


void ADD_::on_vel__clicked()
{
     ui->return_2->setHidden(true);
    ui->return_c->setHidden(true);
    ui->return_btn->setHidden(true);
    if(to_add == "ball"){
        bool ok;
    QString read = QInputDialog::getText(this, tr("Velocity"),tr("3 Coord plsease"), QLineEdit::Normal, tr("0 0 0"), &ok);
    if(!ok){
        ui->return_c->setHidden(false);
        ui->return_btn->setHidden(false);
         ui->return_2->setHidden(false);
        return;
    }
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
    if(list.size() != 3 )
    list.push_back(aux.toDouble());
    Vecteur v({list[0], list[1], list[2]});
    velocity = v;
    ui->vel_->setEnabled(false);
}
   if(to_add == "pendulum")
   {
       bool ok;
       QString read = QInputDialog::getText(this, tr("Velocity"),tr("One coord please"), QLineEdit::Normal, tr("0"), &ok);
       if(!ok){
           ui->return_c->setHidden(false);
           ui->return_btn->setHidden(false);
           ui->return_2->setHidden(false);
           return;
       }
       int j = 0;
       while(read[j] == ' ')
           j++;
       double value = read.toDouble();
       Vecteur v({value});
       velocity = v;
       ui->vel_->setEnabled(false);
   }
   if(to_add == "spherical_pendulum")
   {
       bool ok;
       QString read = QInputDialog::getText(this, tr("Velocity"),tr("2 Angles"), QLineEdit::Normal, tr("0 0"), &ok);
       if(!ok)
       {
           ui->return_c->setHidden(false);
           ui->return_btn->setHidden(false);
           ui->return_2->setHidden(false);
           return;
       }
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
       if(list.size() != 2)
       list.push_back(aux.toDouble());
       Vecteur v({list[0], list[1]});
       velocity = v;
       ui->vel_->setEnabled(false);
   }
   if(to_add == "ressort")
   {
       bool ok;
       QString read = QInputDialog::getText(this, tr("Velocity"),tr("One coord please"), QLineEdit::Normal, tr("0"), &ok);
       if(!ok)
       {
           ui->return_c->setHidden(false);
           ui->return_btn->setHidden(false);
           ui->return_2->setHidden(false);
           return;
       }
       std::vector<double> list;
       int j = 0;
       while(read[j] == ' ')
           j++;
       double value = read.toDouble();
       Vecteur v({value});
       velocity = v;
       ui->vel_->setEnabled(false);
   }
}
void ADD_::on_pos__clicked()
{
    ui->return_c->setHidden(true);
    ui->return_btn->setHidden(true);
    ui->return_2->setHidden(true);
    bool ok;
    if(to_add == "ball"){
        QString read = QInputDialog::getText(this, tr("Position"),tr("3 Coord plsease"), QLineEdit::Normal, tr("0 0 0"), &ok);
        if(!ok)
        {
            ui->return_c->setHidden(false);
            ui->return_btn->setHidden(false);
            ui->return_2->setHidden(false);
            return;
        }
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
    ui->pos_->setEnabled(false);
}
   if(to_add == "pendulum")
{
    QString read = QInputDialog::getText(this, tr("Position"),tr("One coord please"), QLineEdit::Normal, tr("0"), &ok);
    if(!ok)
    {
        ui->return_c->setHidden(false);
        ui->return_btn->setHidden(false);
        ui->return_2->setHidden(false);
        return;
    }
    int j = 0;
    while(read[j] == ' ')
        j++;
    double value = read.toDouble();
    Vecteur v({value});
    position = v;
    ui->pos_->setEnabled(false);
}
   if(to_add == "spherical_pendulum")
   {
       QString read = QInputDialog::getText(this, tr("Position"),tr("Two coord please"), QLineEdit::Normal, tr("0 0"), &ok);
       if(!ok)
       {
           ui->return_c->setHidden(false);
           ui->return_btn->setHidden(false);
           ui->return_2->setHidden(false);
           return;
       }
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
       if(list.size() != 2)
       list.push_back(aux.toDouble());
       Vecteur v({list[0], list[1]});
       position = v;
       ui->pos_->setEnabled(false);
   }
   if(to_add == "ressort")
   {
       QString read = QInputDialog::getText(this, tr("Position"),tr("One coord please"), QLineEdit::Normal, tr("0"), &ok);
       if(!ok)
       {
           ui->return_c->setHidden(false);
           ui->return_btn->setHidden(false);
           ui->return_2->setHidden(false);
           return;
       }
       int j = 0;
       while(read[j] == ' ')
           j++;
       double value = read.toDouble();
       Vecteur v({value});
       position = v;
       ui->pos_->setEnabled(false);
   }
}
void ADD_::on_force_btn_clicked()
{
    ui->gridLayoutWidget->hide();
    ui->horizontalLayoutWidget->hide();
    ui->horizontalLayoutWidget_2->show();
    ui->return_c->setHidden(false);
    to_add = "force";
}


void ADD_::on_go_force_clicked()
{
     ui->return_2->setHidden(true);
    ui->return_c->setHidden(true);
    ui->return_btn->setHidden(true);
    bool ok;
    QString read = QInputDialog::getText(this, tr("Intensity"),tr("3 Coord please"), QLineEdit::Normal, tr("0 0 -9.81"), &ok);
    if(!ok)
    {
        ui->return_c->setHidden(false);
        ui->return_btn->setHidden(false);
        ui->return_2->setHidden(false);
        return;
    }
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
    while(list.size() < 3)
        list.push_back(0);
    list.push_back(aux.toDouble());
    Vecteur v({list[0], list[1], list[2]});
    if(v == Vecteur{0,0,0})
        v = {0,0,-9.81};
    intensity = v;
    ui->go_force->setEnabled(false);
}


void ADD_::on_ok_force_clicked()
{
    if(intensity == Vecteur{0,0,0})
    {
        QMessageBox::information(this, tr("Error"), tr("Incorect Values"));
    }
    else{
    ForceField f(intensity);
    system->add_force(f);
    std::stringstream out;
    out << *system;
    ui->textBrowser->insertPlainText(QString::fromStdString(out.str()));
    on_return_btn_clicked();
    ui->gridLayoutWidget->hide();
    ui->horizontalLayoutWidget->show();
     ui->return_2->setHidden(false);
    }
}


void ADD_::on_pend_btn_clicked()
{
    ui->return_btn->setHidden(false);
    ui->go_btn->setHidden(false);
    ui->gridLayoutWidget->hide();
    ui->verticalLayoutWidget_2->show();
    to_add = "pendulum";
    ui->pos->setText("the angle!");
    ui->vel->setText("angular speed");
    ui->verticalLayoutWidget_4->show();
}


void ADD_::on_direction_clicked()
{
}


void ADD_::on_origin_clicked()
{

}


void ADD_::on_direction__clicked()
{
     ui->return_2->setHidden(true);
    ui->return_c->setHidden(true);
    ui->return_btn->setHidden(true);
    bool ok;
    QString read = QInputDialog::getText(this, tr("Direction"),tr("3 Coord please"), QLineEdit::Normal, tr("0 0 0"), &ok);
    if(!ok)
    {
        ui->return_c->setHidden(false);
        ui->return_btn->setHidden(false);
        ui->return_2->setHidden(false);
        return;
    }
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
    list.push_back(aux.toDouble());
    Vecteur v({list[0], list[1], list[2]});
    direction = v;
    ui->direction_->setEnabled(false);
}


void ADD_::on_origin__clicked()
{
     ui->return_2->setHidden(true);
    ui->return_c->setHidden(true);
    ui->return_btn->setHidden(true);
    bool ok;
    QString read = QInputDialog::getText(this, tr("Origin"),tr("3 Coord please"), QLineEdit::Normal, tr("0 0 0"), &ok);
    if(!ok)
    {
        ui->return_c->setHidden(false);
        ui->return_btn->setHidden(false);
        ui->return_2->setHidden(false);
        return;
    }
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
    list.push_back(aux.toDouble());
    Vecteur v({list[0], list[1], list[2]});
    origin = v;
    ui->origin_->setEnabled(false);
}


void ADD_::on_pend_s_btn_clicked()
{
    ui->return_btn->setHidden(false);
    ui->go_btn->setHidden(false);
    ui->gridLayoutWidget->hide();
    ui->verticalLayoutWidget_2->show();
    ui->pos->setText("2 Angles!");
    ui->vel->setText("2 Angles!");
    to_add = "spherical_pendulum";
    ui->verticalLayoutWidget_4->show();
}


void ADD_::on_res_btn_clicked()
{
    ui->return_btn->setHidden(false);
    ui->go_btn->setHidden(false);
    ui->gridLayoutWidget->hide();
    ui->verticalLayoutWidget_2->show();
    ui->pos->setText("1 Coord->x!");
    ui->vel->setText("1 Coord->Vx");
    to_add = "ressort";
    ui->verticalLayoutWidget_4->show();
    ui->verticalLayoutWidget_5->show();
    ui->lenght->setHidden(true);
    ui->lenght_->setHidden(true);
    ui->friction_->setHidden(true);
    ui->label_3->setHidden(true);
}
void ADD_::on_pushButton_clicked()
{
}

void ADD_::on_return_c_clicked()
{
    ui->return_btn->setHidden(true);
    ui->go_btn->setHidden(true);
    ui->gridLayoutWidget->hide();
    ui->verticalLayoutWidget_2->hide();
    ui->horizontalLayoutWidget_2->hide();
    ui->textBrowser->setPlainText("Current SYSTEM!");
    ui->verticalLayoutWidget_4->hide();
    ui->verticalLayoutWidget_5->hide();
    ui->horizontalLayoutWidget->show();
    ui->return_c->setHidden(true);
    ui->return_2->setEnabled(true);
}


void ADD_::on_obs_btn_clicked()
{
    //ui->return_c->setHidden(false);
    add_o = new add_obstacle(this, system);
    hide();
    add_o->show();
}


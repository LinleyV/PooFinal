#ifndef ADD_OBSTACLE_H
#define ADD_OBSTACLE_H

#include <QDialog>
#include "add_.h"
#include "POO_Project/System_Class/System.h"
namespace Ui {
class add_obstacle;
}

class add_obstacle : public QDialog
{
    Q_OBJECT

public:
    explicit add_obstacle(QWidget *parent = nullptr, System* system = nullptr);
    ~add_obstacle();

private slots:
    void on_return_2_clicked();

    void on_return_c_clicked();

    void on_plan_clicked();

    void on_brique_clicked();

    void on_position__clicked();

    void on_normal__clicked();

    void on_position_b_clicked();

    void on_lenght_1_clicked();

    void on_width_1_clicked();

    void on_height_1_clicked();

    void on_go_btn_clicked();

private:
    Ui::add_obstacle *ui;
    ADD_* add;
    System* system;
    QString obs_add;
    Vecteur lenght;
    Vecteur width;
    Vecteur position;
    Vecteur normal;
    double height;
};

#endif // ADD_OBSTACLE_H

#ifndef ADD__H
#define ADD__H

#include <QDialog>
#include "POO_Project/System_Class/System.h"
class add_obstacle;
namespace Ui {
class ADD_;
}

class ADD_ : public QDialog
{
    Q_OBJECT

public:
    explicit ADD_(QWidget *parent = nullptr, System* system = nullptr);
    ~ADD_();

private slots:
    void on_obj_m_btn_clicked();

    void on_ball_btn_clicked();

    void on_mass__editingFinished();

    void on_return_btn_clicked();

    void on_go_btn_clicked();

    void on_return_2_clicked();

    void on_pushButton_clicked();

    void on_vel__clicked();

    void on_pos__clicked();

    void on_force_btn_clicked();

    void on_go_force_clicked();

    void on_ok_force_clicked();

    void on_pend_btn_clicked();

    void on_direction_clicked();

    void on_origin_clicked();

    void on_direction__clicked();

    void on_origin__clicked();

    void on_pend_s_btn_clicked();

    void on_res_btn_clicked();

    void on_return_c_clicked();

    void on_obs_btn_clicked();

private:
    Ui::ADD_ *ui;
    add_obstacle* add_o;
    System *system;
    QString to_add;
    Vecteur position;
    Vecteur velocity;
    Vecteur intensity;
    Vecteur origin;
    Vecteur direction;
};

#endif // ADD__H

#ifndef MODIFY_H
#define MODIFY_H
#include <QDialog>
#include "add_.h"
#include "collision.h"
namespace Ui {
class Modify;
}
class MainWindow;
class Modify : public QDialog
{
    Q_OBJECT

public:
    explicit Modify(QWidget *parent = nullptr);
    ~Modify();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_add_btn_clicked();

    void on_evolve_btn_clicked();

    void on_update_clicked();

    void on_cromer_clicked();

    void on_quitt_clicked();

    void on_nemark_clicked();

    void on_kutta_clicked();

    void on_back_btn_clicked();

    void on_del_btn_clicked();

    void on_col_btn_clicked();

private:
    Ui::Modify *ui;
    MainWindow* mw;
    ADD_* add;
    System *system;
    collision* coll_;
};

#endif // MODIFY_H

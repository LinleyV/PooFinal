#ifndef COLLISION_H
#define COLLISION_H

#include <QDialog>

namespace Ui {
class collision;
}

class collision : public QDialog
{
    Q_OBJECT

public:
    explicit collision(QWidget *parent = nullptr);
    ~collision();

private slots:
    void on_return_col_clicked();

private:
    Ui::collision *ui;
};

#endif // COLLISION_H

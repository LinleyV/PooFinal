#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class Second_Window; }
QT_END_NAMESPACE

class Second_Window :public QMainWindow
{
    Q_OBJECT
public:
    Second_Window(QWidget *parenr = nullptr);
    ~Second_Window();
private:
    Ui::Second_Window *ui;
};

#endif // SECOND_WINDOW_H

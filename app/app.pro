#-------------------------------------------------
#
# Project created by QtCreator 2022-06-02T19:47:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    POO_Project/Ball_Class/Balle.cpp \
    POO_Project/Brique_Class/Brique.cpp \
    POO_Project/Constantes/Constantes.cpp \
    POO_Project/Dessinable_Class/Dessinable.cpp \
    POO_Project/ForceField_class/ChampsForces.cpp \
    POO_Project/Integrateurs/Integrateur_Euler/Integrateur_Euler.cpp \
    POO_Project/Integrateurs/Integrateur_EulerCromer/Cromer.cpp \
    POO_Project/Integrateurs/Integrateur_Newmark/Newmark.cpp \
    POO_Project/Integrateurs/Integrateur_RungKutta/Runge-Kutta.cpp \
    POO_Project/Integrateurs/Integrateurs.cpp \
    POO_Project/ObjetMobile/ObjetMobile.cpp \
    POO_Project/ObjetSimple_class/ObjetSimple.cpp \
    POO_Project/Obstacles/Obstacles.cpp \
    POO_Project/Plan_Class/Plan.cpp \
    POO_Project/PortionPlan/PortionPlan.cpp \
    POO_Project/Print_Class/Print.cpp \
    POO_Project/Ressort_Class/Ressort.cpp \
    POO_Project/Spherical_Pendulum/PenduleSpherique.cpp \
    POO_Project/SupportADessin/SupportADessin.cpp \
    POO_Project/System_Class/System.cpp \
    POO_Project/Vector_Class/New_Vector_Week_3_Final/Vecteur.cpp \
    POO_Project/Vent_Class/Vent.cpp \
    POO_Project/Ventilator_Class/Ventilator.cpp \
    POO_Project/Week_4_Pendule/Pendule.cpp \
    add_.cpp \
    add_obstacle.cpp \
    collision.cpp \
    modify.cpp \

HEADERS += \
        mainwindow.h \
    POO_Project/Ball_Class/Balle.h \
    POO_Project/Brique_Class/Brique.h \
    POO_Project/ComposedObjects_Class/ComposedObjects.h \
    POO_Project/Constantes/Constantes.h \
    POO_Project/Dessinable_Class/Dessinable.h \
    POO_Project/ForceField_class/ChampsForces.h \
    POO_Project/Integrateurs/Integrateur_Euler/Integrateur_Euler.h \
    POO_Project/Integrateurs/Integrateur_EulerCromer/Cromer.h \
    POO_Project/Integrateurs/Integrateur_Newmark/Newmark.h \
    POO_Project/Integrateurs/Integrateur_RungKutta/Runge-Kutta.h \
    POO_Project/Integrateurs/Integrateurs.h \
    POO_Project/ObjetMobile/ObjetMobile.h \
    POO_Project/ObjetSimple_class/ObjetSimple.h \
    POO_Project/Obstacles/Obstacles.h \
    POO_Project/Plan_Class/Plan.h \
    POO_Project/PortionPlan/PortionPlan.h \
    POO_Project/Print_Class/Print.h \
    POO_Project/Ressort_Class/Ressort.h \
    POO_Project/Spherical_Pendulum/PenduleSpherique.h \
    POO_Project/SupportADessin/SupportADessin.h \
    POO_Project/System_Class/System.h \
    POO_Project/Vector_Class/New_Vector_Week_3_Final/Vecteur.h \
    POO_Project/Vent_Class/Vent.h \
    POO_Project/Ventilator_Class/Ventilator.h \
    POO_Project/Week_4_Pendule/Pendule.h \
    add_.h \
    add_obstacle.h \
    collision.h \
    modify.h \

FORMS += \
        mainwindow.ui \
    add_.ui \
    add_obstacle.ui \
    collision.ui \
    mainwindow.ui \
    modify.ui

RESOURCES += \
    res.qrc

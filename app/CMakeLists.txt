cmake_minimum_required(VERSION 3.5)

project(App VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        modify.cpp
        modify.h
        modify.ui
        res.qrc
        ../../POO_Project/System_Class/System.cpp
        ../../POO_Project/Ball_Class/Balle.cpp
        ../../POO_Project/System_Class/System.h
        ../../POO_Project/Ball_Class/Balle.h
        ../../POO_Project/Vector_Class/New_Vector_Week_3_Final/Vecteur.cpp
        ../../POO_Project/Vector_Class/New_Vector_Week_3_Final/Vecteur.h
        ../../POO_Project/ObjetMobile/ObjetMobile.cpp
        ../../POO_Project/ObjetMobile/ObjetMobile.h
        ../../POO_Project/Integrateurs/Integrateur_EulerCromer/Cromer.cpp
        ../../POO_Project/Integrateurs/Integrateur_EulerCromer/Cromer.h
        ../../POO_Project/Constantes/Constantes.cpp
        ../../POO_Project/Constantes/Constantes.h
        ../../POO_Project/ForceField_class/ChampsForces.cpp
        ../../POO_Project/ForceField_class/ChampsForces.h
        ../../POO_Project/Integrateurs/Integrateurs.cpp
        ../../POO_Project/Integrateurs/Integrateurs.h
        ../../POO_Project/Integrateurs/Integrateur_Euler/Integrateur_Euler.cpp
        ../../POO_Project/Integrateurs/Integrateur_Euler/Integrateur_Euler.h
        ../../POO_Project/Integrateurs/Integrateur_RungKutta/Runge-Kutta.cpp
        ../../POO_Project/Integrateurs/Integrateur_RungKutta/Runge-Kutta.h
        ../../POO_Project/Integrateurs/Integrateur_Newmark/Newmark.cpp
        ../../POO_Project/Integrateurs/Integrateur_Newmark/Newmark.h
        ../../POO_Project/Week_4_Pendule/Pendule.cpp
        ../../POO_Project/Week_4_Pendule/Pendule.h
        ../../POO_Project/Spherical_Pendulum/PenduleSpherique.cpp
        ../../POO_Project/Spherical_Pendulum/PenduleSpherique.h
        ../../POO_Project/Ressort_Class/Ressort.cpp
        ../../POO_Project/Ressort_Class/Ressort.h
        ../../POO_Project/Brique_Class/Brique.cpp
        ../../POO_Project/Brique_Class/Brique.h
        ../../POO_Project/Plan_Class/Plan.cpp
        ../../POO_Project/Plan_Class/Plan.h
        ../../POO_Project/PortionPlan/PortionPlan.cpp
        ../../POO_Project/PortionPlan/PortionPlan.h
        ../../POO_Project/Obstacles/Obstacles.cpp
        ../../POO_Project/Obstacles/Obstacles.h
        add_obstacle.cpp
        add_obstacle.h
        add_obstacle.ui
        add_.cpp
        add_.h
        add_.ui
        collision.cpp
        collision.h
        collision.ui


)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(App
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET App APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(App SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(App
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(App PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(App PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(App)
endif()

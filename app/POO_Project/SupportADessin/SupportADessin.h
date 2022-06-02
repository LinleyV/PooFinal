#pragma once
//#if ! defined INCLUDED_FILES
//#define INCLUDED_FILES
//#include "../ObjetMobile/ObjetMobile.h"
//#include "../System Class/System.h"
//#include "../Obstacles/Obstacles.h"
//#endif
class ObjetMobile;
class System;
class Obstacle;
class ForceField;
class SupportADessin
{
public:
	virtual ~SupportADessin() = default;
	virtual void dessine(System const&) = 0;
	virtual void dessine(ObjetMobile const&) = 0;
	virtual void dessine(Obstacle const&) = 0;
	virtual void dessine(ForceField const&) = 0;
    SupportADessin& operator=(SupportADessin const&) = delete;
};


#pragma once
#include "../ObjetMobile/ObjetMobile.h"
#include "../Vector_Class/New_Vector_Week_3_Final/Vecteur.h"
class Integrateurs
{
protected:
	double dt;
    const ObjetMobile *object;
public:
	Integrateurs(double dt)
		:dt(dt),
		object(nullptr)
	{}
	void set_object(const ObjetMobile* ptr);
	virtual ObjetMobile* first_order() = 0;
	virtual ObjetMobile* second_order() = 0;
};


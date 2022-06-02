#pragma once
#include "../Integrateurs.h"
class Cromer : public Integrateurs
{
public:
	Cromer(double dt)
		:Integrateurs(dt)
	{}
	virtual ObjetMobile* second_order() override;
	virtual ObjetMobile* first_order() override;
};
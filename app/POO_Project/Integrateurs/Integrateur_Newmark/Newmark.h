#pragma once
#include "../Integrateurs.h"
class Newmark : public Integrateurs
{
public:
	Newmark(double dt)
		:Integrateurs(dt)
	{}
	virtual ObjetMobile* second_order() override;
	virtual ObjetMobile* first_order() override { return nullptr; }
};


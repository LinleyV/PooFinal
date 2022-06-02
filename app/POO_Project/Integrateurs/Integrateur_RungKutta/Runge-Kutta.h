#pragma once
#include "../Integrateurs.h"

class RungeKutta : public Integrateurs
{
public:
		RungeKutta(double dt)
			:Integrateurs(dt) 
		{}
		virtual ObjetMobile* first_order() override;
		virtual ObjetMobile* second_order() override;
};

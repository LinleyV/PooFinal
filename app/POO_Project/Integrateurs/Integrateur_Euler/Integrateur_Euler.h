#pragma once
#include "../Integrateurs.h"
class Integrateur_Euler : public Integrateurs
{
public:
	using Integrateurs::Integrateurs;
	virtual ObjetMobile* first_order() override;
private:
	virtual ObjetMobile* second_order() override
	{
		return nullptr;
	}
};
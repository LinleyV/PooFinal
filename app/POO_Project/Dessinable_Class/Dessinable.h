#pragma once
//#include "Dessinable.h"
class SupportADessin;
class Dessinable
{

public:
	virtual void dessine_sur(SupportADessin& support) = 0;
};


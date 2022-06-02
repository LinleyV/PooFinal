#pragma once
#include "../Brique_Class/Brique.h"
#include "../ForceField_class/ChampsForces.h"
#include "../Vent_Class/Vent.h"
#include "../ComposedObjects_Class/ComposedObjects.h"
class Ventilator:public ComposedObjects
{
private:
	/*Brique wall;
	ForceField blast_zone_XD;
	double sigma;
	Vecteur speed;
	Vecteur calculate_speed(double);
	Vent* blast_zone;
	Brique* brique;*/
public:
	Ventilator(Vent vent, Brique brique)
		:ComposedObjects(nullptr, brique.clone(), vent.clone())
	{
	}
	~Ventilator()
	{
	}
	Ventilator* clone() const { return new Ventilator(*this); }
	//bool is_in_range(ObjetMobile const&) const;
	//void calculate_intensity(ObjetMobile const&);
	//void modify_force_mobile_object(ObjetMobile&);
	// void add_to_system(System& system) const { brique->add_to_system(system); }
};


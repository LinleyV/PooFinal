#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include "../Constantes/Constantes.h"
#include "../ObjetMobile/ObjetMobile.h"
#include "../SupportADessin/SupportADessin.h"
double extern const PI;
class Balle : public ObjetMobile
{
public:

	Balle(Vecteur position, Vecteur velocity,
		Vecteur force, double radius, double mass)
		// attributs that belong to the super class
		:ObjetMobile(position, velocity, force, radius, mass) 
	{}
	Balle(double radius, double mass)
		// attributs that belong to the super-class
		:ObjetMobile(radius, mass)
	{}
	virtual Vecteur evolve() override;
	virtual Balle* clone() const override;
	virtual void dessine_sur(SupportADessin& support) override
	{
		support.dessine(*this);
	}
	virtual Balle* prepare_collision() { return this; }
	virtual void update_collision(Balle* ptr) override { this->set_new_pos(ptr->get_position()); this->set_new_speed(ptr->get_velocity()); }
	virtual bool collision(ObjetMobile& other, double alpha = 0.8, double miu = 0.01, double dt = 0);
	/*virtual bool collision(Balle& balle, double alpha, double miu, double dt = 0) { return ObjetMobile::collision(balle, alpha, miu, dt); }*/
	std::ostream& print(std::ostream& output) const override;
	virtual void add_force(Vecteur const& f) override;
};
#pragma once
#
#include "../Vector_Class/New_Vector_Week_3_Final/Vecteur.h"
#include "../SupportADessin/SupportADessin.h"
#include "../ObjetSimple_class/ObjetSimple.h"
#include "../Constantes/Constantes.h"
extern const Vecteur g;
//#include "../System_Class/System.h"
class System;
class Balle;
class ObjetMobile : public ObjetSimple
{
protected:
	Vecteur position;
	Vecteur velocity;
	Vecteur force;
	double radius;
	double mass;
public:
	ObjetMobile(Vecteur position, Vecteur velocity,
		Vecteur force, double radius, double mass)
		:position(position), velocity(velocity), force(force),
		radius(radius), mass(mass)
	{}
	ObjetMobile(double radius, double mass)
		:position(0,0,0), velocity(0,0,0), force(0,0,0),
		radius(radius), mass(mass)
	{}
	virtual Vecteur get_position() const;
	virtual Vecteur get_velocity() const;
	virtual Vecteur get_force() const;
	double find_density() const;
	double get_mass() const;
	double get_radius() const;
	virtual void add_force(Vecteur const& df);
	virtual bool collision(ObjetMobile&, double alpha = 0.8, double miu = 0.01, double dt = 0);
	virtual Balle* prepare_collision() = 0;
	virtual void update_collision(Balle*) = 0;
	virtual std::ostream& print(std::ostream&output) const;
	virtual Vecteur evolve() = 0;
	void set_new_force(const Vecteur& force);
	void set_new_speed(const Vecteur& speed);
	void set_new_pos(const Vecteur& pos);
	virtual ObjetMobile* clone() const  = 0;
	void dessine_sur(SupportADessin& support)
	{ support.dessine(*this); }
	//virtual void add_to_system(System& system) const { system.add_Mobile_Object(*this); }
	virtual ~ObjetMobile()
	{}
};
std::ostream& operator<<(std::ostream& output, const ObjetMobile& objet);


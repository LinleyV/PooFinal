#pragma once
#include <iostream>
#include "../Vector_Class/New_Vector_Week_3_Final/Vecteur.h"
//#include "../System_Class/System.h"
#include "../ObjetMobile/ObjetMobile.h"
#include "../ObjetSimple_class/ObjetSimple.h"
class System;
class Obstacle : public ObjetSimple
{
protected:
		double mass;
		Vecteur position;
		size_t force;

public:
		Obstacle(Vecteur position={0.0, 0.0, 0.0}, double mass=0.0) // default constructor
		:mass(mass), position(position), force(-1)
		{}
		Obstacle(Obstacle const& obs)  // copy constructor
		:mass(obs.mass), position(obs.position), force(force)
		{}
		void set_force(size_t f) { force = f; }
		size_t get_force()const { return force; }
		virtual Obstacle* clone() const = 0;
		virtual std::ostream& print(std::ostream& output) const;
		//void agit_sur(ObjetMobile&);
		virtual double distance(const ObjetMobile&) const = 0;
		virtual Vecteur point_le_plus_proche(const ObjetMobile&) const = 0;
		Vecteur get_position() const;
		virtual void dessine_sur(SupportADessin& support) override
		{ support.dessine(*this); }
		bool collision(ObjetMobile&, double l = 0, double m = 0, double dt = 0);
		//virtual void add_to_system(System& system) const { system.add_Obstacle(*this); }
		virtual ~Obstacle()
		{}
};


#pragma once
#include <iostream>
#include "../ObjetMobile/ObjetMobile.h"
#include "../Obstacles/Obstacles.h"
#include "../Vector_Class/New_Vector_Week_3_Final/Vecteur.h"
#include "../PortionPlan/PortionPlan.h"

class Brique : public PortionPlan
{
private:
	std::vector<PortionPlan> brick;
	Vecteur largeur;
	Vecteur length;
	double height;
	Vecteur pos;

public:
	Brique(Vecteur position, Vecteur length, Vecteur large, double height)  // constructor from parameters
		:brick(6), height(height), length(length), pos(position),
		largeur(large - ((large * length.unitaire()) * length.unitaire()))
	{
		PortionPlan face1(position, length, largeur);
		PortionPlan face2(position, (-1) * height * (length ^ largeur).unitaire(), length);
		PortionPlan face3(position, largeur, (-1) * height * (length ^ largeur).unitaire());
		PortionPlan face4(position + length, (-1) * height * (length ^ largeur).unitaire(), largeur);
		PortionPlan face5(position + largeur, length, (-1) * height * (length ^ largeur).unitaire());
		PortionPlan face6(position + (-1) * height * (length ^ largeur).unitaire(), largeur, length);
		brick[0] = face1;
		brick[1] = face2;
		brick[2] = face3;
		brick[3] = face4;
		brick[4] = face5;
		brick[5] = face6;
	}
	double distance(const ObjetMobile&) const override;
	Vecteur point_le_plus_proche(const ObjetMobile&) const override;
	bool appartient(const Vecteur&) const;
	Vecteur longueur() const;
	Vecteur large() const;
	double hauteur() const;
	Vecteur position() const;
	std::vector<PortionPlan> get_brick() const;
	virtual void dessine_sur(SupportADessin& support) override
		{
			support.dessine(*this);
		}
	virtual Brique* clone() const override
		{
			return new Brique(*this);
		}

};

std::ostream& operator<<(std::ostream&, const Brique&);


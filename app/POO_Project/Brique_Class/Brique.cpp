#include <iostream>
#include <cmath>
#include "Brique.h"
#include "../Vector_Class/New_Vector_Week_3_Final/Vecteur.h"
#include <math.h>

Vecteur Brique::position() const
{
	return pos;
}

std::vector<PortionPlan> Brique::get_brick() const
{
	return brick;
}

Vecteur Brique::longueur() const
{
	return length;
}
Vecteur Brique::large() const
{
	return largeur;
}
double Brique::hauteur() const
{
	return height;
}

std::ostream& operator<<(std::ostream& output, const Brique& brique) //printing the brick's informations
{
	my_vector Largeur = (brique.large()).get_vector();
	my_vector Longueur = (brique.longueur()).get_vector();
	my_vector Position = (brique.position()).get_vector();

	std::cout << "un mur brique" << std::endl;

	for (size_t x(0); x < (brique.position()).size(); ++x)
	{
		output << Position[x] << " ";
	}
	output << "# origine brique\n";

	for (size_t x(0); x < (brique.longueur()).size(); ++x)
	{
		output << Longueur[x] << " ";
	}
	output << "# longueur brique\n";

	for (size_t x(0); x < (brique.large()).size(); ++x)
	{
		output << Largeur[x] << " ";
	}
	output << "# largeur brique\n";

	output << brique.hauteur() << "# hauteur brique\n";

	return output;
}

double Brique::distance(const ObjetMobile& obj) const // distance between the closest point and the object
{
	return (obj.get_position() - Brique::point_le_plus_proche(obj)).norme() - obj.get_radius();
}

Vecteur Brique::point_le_plus_proche(const ObjetMobile& obj) const // calculates the closest point of the obstacle
{
	Vecteur v_init(brick[0].point_le_plus_proche(obj));
	Vecteur p(obj.get_position());
	for (size_t i(1); i < 6; ++i)
	{
		Vecteur v(3);
		v = brick[i].point_le_plus_proche(obj);
		if ((v - p).norme() < (v_init - p).norme())
		{
			v_init = v;
		}
	}
	return v_init;
}

bool Brique::appartient(const Vecteur& p) const
{
	bool final(false);
	for (const auto& face : brick)
	{
		if (face.PortionPlan::appartient(p))
		{
			std::cout << " A " << std::endl;
			final = true;
		}
	}
	return final;
}

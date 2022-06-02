#include "ObjetMobile.h"
#include <iostream>
#include <cmath>
#include "../Constantes/Constantes.h"

#include <iomanip>
extern const double PI;
std::ostream& operator<<(std::ostream& output, const ObjetMobile& objet)
{
	objet.print(output);
	return output;
}
double ObjetMobile::find_density()const
{
	double desity = get_mass();
	double volume = 4 * PI / 3 * pow(get_radius(), 3);
	return desity / volume;
}
double ObjetMobile::get_mass() const
{
	return mass;
}
double ObjetMobile::get_radius() const
{
	return radius;
}
Vecteur ObjetMobile::get_force() const
{
	return force;
}
Vecteur ObjetMobile::get_position() const
{
	return position;
}
Vecteur ObjetMobile::get_velocity() const
{
return velocity;
}
void ObjetMobile::add_force(Vecteur const& df)
{
	if (df == g)
		force += df * get_mass();
	else
		force += df;
	return;
}
std::ostream& ObjetMobile::print(std::ostream& output) const
{
	output << '\n';
	output << this->get_mass() << " # masse \n";
	output << this->get_radius() << " # rayon\n";
	/*output << std::fixed << std::setprecision(2) << this->find_density() << " # masse volumetrique\n";
	output.unsetf(std::ios::fixed);*/
	output << std::resetiosflags(std::ios::fixed | std::ios::showpoint);
	output << this->get_position() << " # position\n";
	output << this->get_velocity() << " # vitesse\n";
	output << this->get_force() << " # force\n";
	return output;
}
void ObjetMobile::set_new_speed(const Vecteur& speed)
{
	this->velocity = speed;
}
void ObjetMobile::set_new_pos(const Vecteur& pos)
{
	this->position = pos;
}void ObjetMobile::set_new_force(const Vecteur& force)
{
	this->force = force;
}
bool ObjetMobile::collision(ObjetMobile& object, double alpha, double miu, double dt)
{
	Vecteur n = this->get_position() - object.get_position();
	if (n.norme() > this->get_radius() + object.get_radius())
		return false;
    /*if(this->get_velocity().unitaire() * object.get_velocity().unitaire() < 0)
        return false;*/
	n = n.unitaire();
	double lambda = (1 + alpha) * object.get_mass() / (this->get_mass() + object.get_mass());
	double fn1 = this->get_force() * n;
	double fn2 = object.get_force() * n;
	if (fn1 < 0)
	{
		this->set_new_force(this->get_force() - fn1 * n);
		object.set_new_force(object.get_force() + fn1 * n);
	}
	if (fn2 > 0)
	{
		this->set_new_force(this->get_force() + fn2 * n);
		object.set_new_force(object.get_force() - fn2 * n);
	}
	double speed = (object.get_velocity() - this->get_velocity()) * n;
	Vecteur relative = this->get_velocity() - object.get_velocity() + speed * n;
	double expression = 7 * miu * (1 + alpha) * speed;
	Vecteur delta_v(0);
	if (expression >= 2 * relative.norme())
	{
		delta_v = lambda * speed * n - (2 * object.get_mass() / 7 * (this->get_mass() + object.get_mass())) * relative;
	}
	else
	{
		delta_v = lambda * speed * (n - miu * relative.unitaire());
	}
	this->set_new_speed(this->get_velocity() + delta_v);
	object.set_new_speed(object.get_velocity() - this->get_mass() / object.get_mass() * delta_v);
	return true;
}

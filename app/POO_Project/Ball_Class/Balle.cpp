#include "Balle.h"
#include "../ObjetMobile/ObjetMobile.h"
#include "../Integrateurs/Integrateur_EulerCromer/Cromer.h"
#include <iostream>
#include <iomanip>
Vecteur Balle::evolve()
{
	Vecteur result(this->get_force());
	double coeff = 1 / this->get_mass();
	result *= coeff;
	return result;
}
std::ostream& Balle::print(std::ostream& output) const
{
	output << "we have a ball:";
	ObjetMobile::print(output);
	return output;

}
void Balle::add_force(Vecteur const& f)
{
	if (f != g)
		ObjetMobile::add_force(f);
	else
	{
		ObjetMobile::add_force(g*(get_mass() - 4 * PI * 1.2 * pow(get_radius(), 3) / 3));
	}
}
Balle* Balle::clone() const
{
	return new Balle(*this);
}
bool Balle::collision(ObjetMobile& other, double alpha, double miu, double dt)
{
	Balle* pointer = prepare_collision();
	Balle* ptr = other.prepare_collision();
	bool col = pointer->ObjetMobile::collision(*ptr, alpha, miu);
	if (col) {
		/*this->set_new_force((pointer->get_force() * u_theta) / u_theta.norme2() * u_theta);
		this->set_new_pos(pointer->get_position());
		this->set_new_speed(pointer->get_velocity());*/
		Cromer integ(dt);
		integ.set_object(pointer);
		integ.second_order();
		update_collision(pointer);
		integ.set_object(ptr);
		integ.second_order();
		other.update_collision(ptr);
	}
	delete pointer;
	pointer = nullptr;
	return col;
}
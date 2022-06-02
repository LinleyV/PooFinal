#include "Ressort.h"
#include "../Ball_Class/Balle.h"
#include "../Integrateurs/Integrateur_EulerCromer/Cromer.h"
std::ostream& Ressort::print(std::ostream& output) const
{
	output << "a ressort : \n";
	ObjetMobile::print(output);
	return output;
}
Vecteur Ressort::evolve()
{
	double result = this->get_force() * direction - k * this->get_position().get_vector()[0] - coeff * this->get_velocity().get_vector()[0];
	result *= 1 / this->get_mass();
	return Vecteur({ result });
}
Ressort* Ressort::clone()const
{
	return new Ressort(*this);
}
bool Ressort::collision(ObjetMobile& obj, double alpha, double miu, double dt)
{
	Balle* pointer = prepare_collision();
	bool col = pointer->ObjetMobile::collision(*obj.prepare_collision(), alpha, miu, dt);
	if (col)
	{
		Cromer integ(dt);
		integ.set_object(pointer);
		integ.second_order();
		update_collision(pointer);
	}
	return col;
}
Balle* Ressort::prepare_collision()
{
	return new Balle(get_position_bout(), get_velocity_bout(), evolve().get_vector()[0] * get_direction(), 0.1, mass);
}
void Ressort::update_collision(Balle* pointer)
{
	this->set_new_pos(1 / get_direction().norme() * (pointer->get_position() - get_origin()));
	this->set_new_speed(1 / get_direction().norme() * pointer->get_velocity());
}
#include <iostream>
#include <cmath>
#include "Obstacles.h"
#include "../../POO_Project/Integrateurs/Integrateur_EulerCromer/Cromer.h"
#include "../Ball_Class/Balle.h"
using namespace std;
extern const double epsilon;
/* void Obstacle::agir_sur(ObjetMobile& obj)
{
	
} */

bool Obstacle::collision(ObjetMobile& object, double alpha, double miu, double dt)
{
	Balle* ptr = object.prepare_collision();
	Vecteur n = ptr->get_position() - point_le_plus_proche(*ptr); // this->getpos - *pointer.getpop
	if (distance(*ptr) > 0)
			return false;
	//if (distance(*ptr) - ptr->get_radius() >= 0) {
	////	
	if ((ptr->get_velocity() * n > 0.001))
	return false;
	//}
	n = n.unitaire();
	double fn = ptr->get_force() * n;
	if (fn < 0)
	{
		ptr->set_new_force(ptr->get_force() - fn * n);
	}
	double speed = -(ptr->get_velocity() * n);
	Vecteur relative = ptr->get_velocity() + speed * n;
	double expression = 7 * miu * (1 + alpha) * speed;
	Vecteur delta_v(0);
	if (expression >= 2 * relative.norme())
	{
		delta_v = (1 + alpha) * speed * n - ((2.0 / 7.0) * relative);
	}
	else
	{
		delta_v = (1 + alpha) * speed * (n - miu * relative.unitaire());
	}
	ptr->set_new_speed(ptr->get_velocity() + delta_v);
    Cromer integ(dt);
    integ.set_object(ptr);
    integ.second_order();
	/// <summary>
	/// HERE IS THE ERROR !!!!! U RETURN WHAT EN FAIT!!!
	/// </summary>
	/// <param name="object"></param>
	/// <param name="alpha"></param>
	/// <param name="miu"></param>
	/// <param name="dt"></param>
	/// <returns></returns>
	object.update_collision(ptr);
	return true;
}
//double Obstacle::distance(const ObjetMobile& obj) const
//{
//	double retour(0.0);
//	Vecteur v(point_le_plus_proche(obj));
//	for(size_t x(0); x < v.size(); ++x)
//	{
//		retour += pow(((position.get_vector())[x]-(v.get_vector())[x]),2);
//	}
//	return (sqrt(retour) - obj.get_radius());
//}
Vecteur Obstacle::get_position() const
{
	return position;
}
std::ostream& Obstacle::print(std::ostream& output) const
{
	output << this->get_position() << " origine\n";
	return output;
}



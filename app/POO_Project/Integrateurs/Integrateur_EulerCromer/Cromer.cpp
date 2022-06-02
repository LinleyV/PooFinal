#include "Cromer.h"
#include "../Integrateur_Euler/Integrateur_Euler.h"
ObjetMobile* Cromer::first_order()
{
	Integrateur_Euler integ(dt);
	return integ.first_order();
}
ObjetMobile* Cromer::second_order()
{
	ObjetMobile* integrate_object = object->clone();
	integrate_object->set_new_speed(integrate_object->get_velocity() + integrate_object->evolve() * dt);
	integrate_object->set_new_pos(integrate_object->get_position() + integrate_object->get_velocity() * dt);
	return integrate_object;
}
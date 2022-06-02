#include "Integrateur_Euler.h"
ObjetMobile* Integrateur_Euler::first_order()
{
	ObjetMobile* integrate_object = object->clone();
	integrate_object->set_new_pos(integrate_object->get_position() + integrate_object->get_position() * dt);
	integrate_object->set_new_speed(integrate_object->get_velocity() + integrate_object->evolve() * dt);
	return integrate_object;
}
#include "Newmark.h"
#include "../../Constantes/Constantes.h"
extern const double epsilon;
ObjetMobile* Newmark::second_order()
{
	ObjetMobile* integrate_object = object->clone();
	ObjetMobile* aux = object->clone();
	Vecteur velocity(integrate_object->get_velocity());
	Vecteur position(integrate_object->get_position());
	Vecteur s(integrate_object->evolve());
	Vecteur q(integrate_object->get_velocity());
	do
	{
		q = position;
		aux->set_new_pos(q);
		aux->set_new_speed(velocity);
		Vecteur r(aux->evolve());
		velocity = integrate_object->get_velocity() + dt / 2 * (r + s);
		position = integrate_object->get_position() + dt * integrate_object->get_velocity() + dt * dt / 3 * (1 / 2 * r + s);
	} while ((position - q).norme() >= epsilon);
	integrate_object->set_new_pos(position);
	integrate_object->set_new_speed(velocity);
	return integrate_object;
}
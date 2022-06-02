#include "Vent.h"
#include <cmath>
bool Vent::is_in_range(ObjetMobile const& object) const
{
	Vecteur origin = get_origin();
	Vecteur x = object.get_position();
	Vecteur diff = origin - x;
	Vecteur n = get_normal();
	Vecteur el = get_l().unitaire();
	Vecteur eL = get_L().unitaire();
	double l = get_l().norme();
	double L = get_L().norme();
	if (!(diff * n > 0 and diff * n < sigma))
		return false;
	if (!(diff * el > 0 and diff * el < l))
		return false;
	if (!(diff * eL > 0 and diff * el < L))
		return false;
	return true;
}
void Vent::calculate_intensity(ObjetMobile const& object)
{
	if (!is_in_range(object))
		return;
	Vecteur n = get_normal();
	double vel = pow(get_air_flow(),2);
	double R = object.get_radius() * object.get_radius();
	set_intensity(3.77 * vel * R * n);
}
void Vent::modify_force_mobile_object(ObjetMobile& object)
{
	object.add_force(get_intensity());
}

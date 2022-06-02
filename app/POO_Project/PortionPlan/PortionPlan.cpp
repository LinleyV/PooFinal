#include "PortionPlan.h"
class PortionPlan;

Vecteur PortionPlan::point_le_plus_proche(const ObjetMobile& obj) const
{
	Vecteur x2(obj.get_position() + (((get_position() - obj.get_position()) * normal) * normal));
	double Xkl((x2 - get_position()) * el), XkL((x2 - get_position()) * eL);

	if (XkL > length)
		x2 -= ((XkL - length) * eL);
	else {
		if (XkL < 0.0)
			x2 -= (XkL * eL);
	}
	if (Xkl > large)
		x2 -= (Xkl - large) * el;
	else {
		if (Xkl < 0.0)
			x2 -= (Xkl * el);
	}
	return x2;
}

double PortionPlan::distance(const ObjetMobile& obj) const
{
    return (obj.get_position()-point_le_plus_proche(obj)).norme() - obj.get_radius();
}

Vecteur PortionPlan::get_position() const
{
    return Obstacle::get_position();
}

bool PortionPlan::appartient(const Vecteur& vp) const
{
	my_vector v(vp.get_vector());
	if (v[0] >= ((get_position()).get_vector())[0] && v[0] <= ((get_position()).get_vector())[0] + length &&
		v[1] >= ((get_position()).get_vector())[1] && v[1] <= ((get_position()).get_vector())[1] + large)
		return true;
	return false;
}

std::vector<Vecteur> PortionPlan::coins() const
{
	std::vector<Vecteur> result;
	result.push_back(position);
	result.push_back(position + (length * eL));
	result.push_back(position + (large * el));
	result.push_back(position + (length * eL) + (large * el));
	return result;
}

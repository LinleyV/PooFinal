#include "Ventilator.h"
//Vecteur Ventilator::calculate_speed(double speed)
//{
//	Vecteur result = wall.normal();
//	result *= speed;
//	return result;
//}
//bool Ventilator::is_in_range(ObjetMobile const& object) const
//{
//	Vecteur origin = wall.get_position();
//	Vecteur x = object.get_position();
//	Vecteur diff = origin - x;
//	Vecteur n = speed.unitaire();
//	Vecteur el = wall.get_largeur().unitaire();
//	Vecteur eL = wall.get_longueur().unitaire();
//	double l = wall.get_largeur().norme();
//	double L = wall.get_longueur().norme();
//	if (!(diff * n > 0 and diff * n < sigma))
//		return false;
//	if (!(diff * el > 0 and diff * el < l))
//		return false;
//	if (!(diff * eL > 0 and diff * el < L))
//		return false;
//	return true;
//}
//void Ventilator::calculate_intensity(ObjetMobile const& object)
//{
//	if (!is_in_range(object))
//		return;
//	Vecteur n = speed.unitaire();
//	double vel = speed * speed;
//	double R = object.get_radius() * object.get_radius();
//	blast_zone_XD.set_intensity(3.77 * vel * R * n);
//}
//void Ventilator::modify_force_mobile_object(ObjetMobile& object)
//{
//	object.add_force(blast_zone_XD.get_intensity());
//}
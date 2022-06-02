#include "ChampsForces.h"
#include <cmath>
#include "../Constantes/Constantes.h"
extern const Vecteur g;
extern const double PI;
void ForceField::interacts_on_gravity(ObjetMobile& obj)
{
	double scalaire = obj.get_mass() - 4 * PI * 1.2 * pow(obj.get_radius(), 3) / 3;
	Vecteur F = scalaire * g;
	obj.add_force(F);
}
Vecteur ForceField::get_interacts_on_gravity(ObjetMobile& obj)
{
	double scalaire = obj.get_mass() - 4 * PI * 1.2 * pow(obj.get_radius(), 3) / 3;
	Vecteur F = scalaire * g;
	return F;
}
void ForceField::interacts_on(ObjetMobile& obj)
{
	obj.add_force(intensity);
}
Vecteur ForceField::get_intensity() const
{
	return intensity;
}
std::ostream& operator<<(std::ostream& output, ForceField const& f)
{
	output << f.get_intensity();
	return output;
}
void ForceField::set_intensity(Vecteur const& v)
{
	intensity = v;
}

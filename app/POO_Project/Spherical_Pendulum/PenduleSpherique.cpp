#include "PenduleSpherique.h"
#include "../Constantes/Constantes.h"
#include "../Integrateurs/Integrateur_EulerCromer/Cromer.h"
extern const Vecteur g;
std::ostream& PenduleSpherique::print(std::ostream& output) const
{
	output << "a spherical pendulum (3D): \n";
	ObjetMobile::print(output);
	return output;
}
Vecteur PenduleSpherique::evolve()
{
	double theta = this->get_position().get_vector()[0];
	double phi = this->get_position().get_vector()[1];
	double theta_p = this->get_velocity().get_vector()[0];
	double phi_p = this->get_velocity().get_vector()[1];
	double first = sin(theta) * (cos(theta) * phi_p * phi_p - g.get_vector()[2] / get_lenght());
	double second = -2 * cos(theta) / sin(theta) * theta_p * theta_p * phi_p * phi_p;
	Vecteur result({ first, second });
	return result;
}
PenduleSpherique* PenduleSpherique::clone()const
{
	return new PenduleSpherique(*this);
}

Vecteur PenduleSpherique::update_uphi() const
{
	double p2 = get_position().get_vector()[1];
	return Vecteur(sin(p2) * get_direction() + cos(p2) * get_direction() ^ g.unitaire());
}
Vecteur PenduleSpherique::update_urho() const
{
	double p1 = get_position().get_vector()[0];
	double p2 = get_position().get_vector()[1];
	return Vecteur(sin(p1) * cos(p2) * get_direction() + sin(p1) * sin(p2) * get_direction() ^ (~g) + cos(p1) * ~g);
}
Vecteur PenduleSpherique::update_utheta() const
{
	double p1 = get_position().get_vector()[0];
	double p2 = get_position().get_vector()[1];
	return Vecteur(cos(p1) * cos(p2) * get_direction() + cos(p1) * sin(p2) * get_direction() ^ (~g) - sin(p1) * ~g);
}

Vecteur PenduleSpherique::get_position_memory() const
{
	double p1 = get_theta();
	double p2 = get_phi();
	return Vecteur(get_origin() + get_lenght() * cos(p1) * ~g
		+ get_lenght() * sin(p1) * cos(p2) * get_direction()
		+ get_lenght() * sin(p1) * sin(p2) * get_direction() ^ ~g);
}

Vecteur PenduleSpherique::get_velocity_memory() const
{
	double p1 = get_theta();
	double p2 = get_phi();
	double pp1 = get_theta_p();
	double pp2 = get_phi_p();
	return Vecteur(-pp1 * sin(p1) * ~g
		+ (pp1 * cos(p1) * cos(p2) - pp2 * sin(p1) * sin(p2)) * get_direction()
		+ (pp1 * cos(p1) * sin(p2) + pp2 * sin(p1) * cos(p2)) * get_direction() ^ ~g);
}

bool PenduleSpherique::collision(ObjetMobile&other, double alpha, double miu, double dt)
{
	Balle* pointer = prepare_collision();
	bool col = get_memory()->ObjetMobile::collision(*other.prepare_collision(), alpha, miu);
	if (col) {
		/*this->set_new_force(get_memory()->get_force());
		this->set_new_pos(get_memory()->get_position());
		this->set_new_speed(get_memory()->get_velocity());*/
		Cromer integ(dt);
		integ.set_object(pointer);
		integ.second_order();
		update_collision(pointer);
	}
	delete pointer;
	pointer = nullptr;
	/*this->set_new_pos(Vecteur{ get_theta(), get_phi() });
	this->set_new_speed(Vecteur{ get_theta_p(), get_phi_p() });*/
	return col;
}
Vecteur PenduleSpherique::get_expression()
{
	urho = update_urho();
	uphi = update_uphi();
	utheta = update_utheta();
	double p1 = get_position().get_vector()[0];
	double p2 = get_position().get_vector()[1];
	double pp1 = get_velocity().get_vector()[0];
	double pp2 = get_velocity().get_vector()[1];
	double f1 = evolve().get_vector()[0];
	double f2 = evolve().get_vector()[1];
    Vecteur result(
		get_mass() * get_lenght() *
		(
			(-pp1 * pp1 - pp2 * pp2 * sin(p1)) * urho
			+
			(f1 - pp2 * pp2 * sin(p1) * cos(p1)) * utheta
			+
			(f2 * sin(p1) - 2 * pp1 * pp2 * cos(p1)) * uphi

			)
	);
	return (result * uphi) * uphi + (result * utheta) * utheta;
}
void PenduleSpherique::update_collision(Balle* b)
{
	double y = b->get_position().get_vector()[1];
	double z = b->get_position().get_vector()[2];
	double theta = 1 - z / get_lenght();
	theta = acos(theta);
	double phi = y / get_lenght();
	phi = asin(phi / sin(theta));
	double vz = b->get_velocity().get_vector()[2];
	double theta_p = vz / (get_lenght() * sin(theta));
	double v = b->get_velocity().norme2();
	double phi_p = v / pow(get_lenght(), 2);
	phi_p -= pow(theta_p, 2);
	phi_p /= pow(sin(theta), 2);
	phi_p = sqrt(phi_p);
	this->set_new_pos({ theta, phi });
	this->set_new_speed({ theta_p, phi_p });
}
Balle* PenduleSpherique::prepare_collision()
{
	Balle* pointer = get_memory();
	pointer->set_new_pos(get_position_memory());
	pointer->set_new_speed(get_velocity_memory());
	Vecteur expression(get_expression());
	get_memory()->set_new_force(expression);
	return pointer;
}
/// <summary>
/// this two functions need to be done!
/// by convention we let the angles at the initial moment on the phi coordinates be 0
/// </summary>
/// <returns></returns>
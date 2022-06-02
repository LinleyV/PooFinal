#include "Pendule.h"
#include "../Constantes/Constantes.h"
#include "../Ball_Class/Balle.h"
#include "../../POO_Project/Integrateurs/Integrateur_EulerCromer/Cromer.h"
#include <cmath>
extern const Vecteur g;
std::ostream& Pendule::print(std::ostream& output) const
{
	output << "a pendulum: " << '\n';
	output << get_origin() << "# origin\n";
	output << get_direction() << "# direction\n";
	output << get_lenght() << "# lenght\n";
	output << get_coeff() << "# coeff friction\n";
	output << get_position_memory() << "# position bout pendule\n";
	output << get_velocity_memory() << "# vitesse bout pendule";
	ObjetMobile::print(output);
	return output;
}
Vecteur Pendule::evolve()
{
	double angle = get_position().get_vector()[0];
	double omega = get_velocity().get_vector()[0];
	Vecteur force = get_force();
	double expression = cos(angle) * force * get_direction();
	expression -= sin(angle) * force * g.unitaire();
	expression -= get_coeff() / get_lenght() * omega;
	expression /= get_mass();
	expression /= get_lenght();
	return Vecteur( {expression} );
}
//Vecteur Pendule::set_direction(const Vecteur& vec)
//{
//	if (vec == g)
//		return Vecteur(0, 1, 0);
//	double first_component = vec.get_vector()[0];
//	double second_component = vec.get_vector()[1];
//	double third_component = vec.get_vector()[2];
//	Vecteur result(-third_component, second_component, first_component);
//	result *= 1 / result.norme();
//	return result;
//}
Pendule* Pendule::clone() const
{
	return new Pendule(*this);
}
double Pendule::get_angle(Balle* ball)
{
	double dist = sqrt(pow(ball->get_position().get_vector()[0] - get_origin().get_vector()[0], 2) + pow(ball->get_position().get_vector()[1] - get_origin().get_vector()[1], 2) + pow(ball->get_position().get_vector()[2] - get_origin().get_vector()[2], 2));
	double dist2 = sqrt(pow(ball->get_position().get_vector()[0] - get_origin().get_vector()[0], 2) + pow(ball->get_position().get_vector()[2] - get_origin().get_vector()[2], 2));
	return acos(dist2 / dist);
}
double Pendule::get_omega(Balle* ball)
{
	double sens = 1;
	/*for (const auto& element : ball->get_velocity().get_vector())
		if (element < 0)
		{
			sens = -1;
			break;
		}*/
	return sens * ball->get_velocity().norme() / get_lenght();
}
Vecteur Pendule::get_position_memory() const
{
	Vecteur result(get_origin());
	result += get_lenght() * cos(get_theta()) * g.unitaire();
	result += get_lenght() * sin(get_theta()) * get_direction();
	return result;
}
Vecteur Pendule::get_velocity_memory() const
{
	Vecteur result(cos(get_theta()) * get_direction() - sin(get_theta()) * g.unitaire());
	result *= get_lenght() * get_theta_p();
	return result;
}
bool Pendule::collision(ObjetMobile& other, double alpha, double miu, double dt)
{
	Balle* pointer = prepare_collision();
	Balle* ptr = other.prepare_collision();
	bool col = pointer->ObjetMobile::collision(*ptr, alpha, miu);
	if(col){
	/*this->set_new_force((pointer->get_force() * u_theta) / u_theta.norme2() * u_theta);
	this->set_new_pos(pointer->get_position());
	this->set_new_speed(pointer->get_velocity());*/
		Cromer integ(dt);
		integ.set_object(pointer);
		integ.second_order();
		update_collision(pointer);
		integ.set_object(ptr);
		integ.second_order();
		other.update_collision(ptr);
	}
	delete pointer;
	pointer = nullptr;
	return col;
	/*this->set_new_pos(Vecteur{ get_theta() });
	this->set_new_speed(Vecteur{ get_theta_p() });*/

}
Balle* Pendule::prepare_collision()
{
	Balle* pointer = get_memory();
	pointer->set_new_pos(get_position_memory());
	pointer->set_new_speed(get_velocity_memory());
	Vecteur u_theta(-cos(get_theta()) * get_direction() + sin(get_theta()) * g.unitaire()
	);
	Vecteur total_force(
		cos(get_theta()) * get_direction() - sin(get_theta()) * g.unitaire()
	);
	total_force *= evolve().get_vector()[0];
	total_force -= pow(get_theta_p(), 2) * (sin(get_theta()) * get_direction() + cos(get_theta()) * g.unitaire());
	total_force *= get_mass() * get_lenght();
	Vecteur expression((total_force * u_theta) / u_theta.norme2() * u_theta);
	pointer->set_new_force(expression);
	return pointer;
}
void Pendule::update_collision(Balle* pointer)
{
	this->set_new_pos({ get_angle(pointer) });
	this->set_new_speed({ get_omega(pointer) });
}
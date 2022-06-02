#include <iostream>
#include "Plan.h"

Vecteur Plan::point_le_plus_proche(const ObjetMobile& obj) const
{
	Vecteur x2(obj.get_position() + ((position - obj.get_position()) * normal) * normal);
	return x2;
}
double Plan::distance(const ObjetMobile& obj) const
{
	return (point_le_plus_proche(obj) - obj.get_position()).norme() - obj.get_radius();
}
Vecteur Plan::get_normal() const
{
	return normal;
}
std::ostream& operator<<(std::ostream& output, Plan const& plan)
{
	/*my_vector origin = (plan.get_position()).get_vector();
	my_vector normale = (plan.normal()).get_vector(); 
	for(size_t x(0); x < origin.size(); ++x)
	{
		output << origin[x] << " ";
	}
	output << "# origine plan" << std::endl;

	for(size_t x(0); x < normale.size(); ++x)
	{
		output << normale[x] << " ";
	}
	output << "# normale plan" << std::endl;
	*/
	
	output << plan.get_position();
	output << "# origine plan" << std::endl;
	
	output << plan.get_normal();
	output << "# normale plan" << std::endl;
	
	return output;
	
}
std::ostream& Plan::print(std::ostream& output) const
{
	output << *this;
	return output;
}


#pragma once
#include "../Vector_Class/New_Vector_Week_3_Final/Vecteur.h"
#include "../ObjetMobile/ObjetMobile.h"
#include "../Constantes/Constantes.h"
extern const Vecteur g;
class ForceField:public ObjetSimple
{
private:
	Vecteur intensity;
	size_t obstacle;
public:
	ForceField(Vecteur force = g)
		:intensity(force), obstacle(-1)
	{}
	size_t get_obstacle()const { return obstacle; }
	void set_obstacle(size_t obs) { obstacle = obs; }
	virtual void dessine_sur(SupportADessin& supp) override { supp.dessine(*this); }
	void interacts_on(ObjetMobile& obj);
	void interacts_on_gravity(ObjetMobile&);
	Vecteur get_interacts_on_gravity(ObjetMobile&);
	Vecteur get_intensity()const;
	void set_intensity(Vecteur const&);
	virtual bool is_in_range(ObjetMobile const&) const { return true; }
	virtual void calculate_intensity(ObjetMobile const&) {}
	virtual void modify_force_mobile_object(ObjetMobile&object) { object.add_force(get_intensity()); }
	ForceField* clone() const { return new ForceField(*this); }
};
std::ostream& operator<<(std::ostream& output, ForceField const& f);
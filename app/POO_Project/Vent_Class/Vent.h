#pragma once
#include "../ForceField_class/ChampsForces.h"
class Vent:public ForceField
{
private:
	Vecteur origin;
	Vecteur normal;
	Vecteur l;
	Vecteur L;
	double sigma;
	double air_flow;
public:
	Vent(Vecteur origin, Vecteur normal, Vecteur l, Vecteur L, double sigma, double v)
		:origin(origin), normal(normal), l(l), L(L), sigma(sigma), air_flow(v)
	{}
	Vecteur get_origin() const { return origin; }
	Vecteur get_normal() const { return normal; }
	Vecteur get_l() const { return l; }
	Vecteur get_L() const { return L; }
	double get_sigma() const { return sigma; }
	double get_air_flow() const { return air_flow; }
	virtual bool is_in_range(ObjetMobile const&) const override;
	virtual void calculate_intensity(ObjetMobile const&) override;
	virtual void modify_force_mobile_object(ObjetMobile&) override;
	//virtual void add_to_system(System&) const;
	Vent* clone() const { return new Vent(*this); }
};


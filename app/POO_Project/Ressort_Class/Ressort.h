#pragma once
#include "../ObjetMobile/ObjetMobile.h"
class Ressort : public ObjetMobile
{
private:
	Vecteur direction;
	Vecteur origin;
	double coeff;
	double k;
public:
	Ressort(Vecteur pos, Vecteur vel, Vecteur f, double mass, double coeff, double k, Vecteur direction, Vecteur origin)
		:ObjetMobile(pos, vel, f, 0.1, mass), coeff(coeff), k(k), direction(direction), origin(origin)
	{}
	virtual Vecteur evolve() override;
	virtual std::ostream& print(std::ostream&) const override;
	virtual Ressort* clone() const override;
	Vecteur get_direction() const { return direction; }
	Vecteur get_origin() const { return origin; }
	bool collision(ObjetMobile&, double alpha = 0.8, double miu = 0.01, double dt = 0) override;
	virtual void dessine_sur(SupportADessin& support) override
	{
		support.dessine(*this);
	}
	Vecteur get_position_bout() const { return get_origin() + get_position().get_vector()[0] * get_direction(); }
	Vecteur get_velocity_bout() const {
		return get_velocity().get_vector()[0] * get_direction();
	}
	virtual Balle* prepare_collision() override;
	virtual void update_collision(Balle*) override;
};


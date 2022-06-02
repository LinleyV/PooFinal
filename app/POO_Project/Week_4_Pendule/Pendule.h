#pragma once
#include "../ObjetMobile/ObjetMobile.h"
#include "../Ball_Class/Balle.h"
#include "../Constantes/Constantes.h"
extern const Vecteur g;
class Pendule : public ObjetMobile
{

protected:
	Vecteur origin;
	Vecteur direction;
	double coeff;
	double L;
	Balle* memory;
	Balle* get_memory() const { return new Balle(*memory); }
	double get_angle(Balle*);
	double get_omega(Balle*);
	//Vecteur set_direction(const Vecteur& vec);
public:
	Pendule(double position, double velocity, Vecteur force, double radius, double mass,
		Vecteur origin, Vecteur direction, double L, double coeff = 0)
		:ObjetMobile({ position }, { velocity }, force, radius, mass), origin(origin), direction(direction), L(L), coeff(coeff),
		memory(new Balle(get_position_memory(), get_velocity_memory(), get_force(), radius, mass))
	{}
	virtual Vecteur evolve() override;
	virtual std::ostream& print(std::ostream& output) const override;
	virtual void dessine_sur(SupportADessin& support) override
	{
		support.dessine(*this);
	}
	virtual Balle* prepare_collision() override;
	virtual void update_collision(Balle*) override;
	virtual Pendule* clone() const override;
	Vecteur get_origin() const { return origin; }
	Vecteur get_direction() const { return direction; }
	double get_coeff() const { return coeff; }
	double get_lenght() const { return L; }
	double get_theta() const { return get_position().get_vector()[0]; }
	double get_theta_p() const { return get_velocity().get_vector()[0]; }
	Vecteur get_position_memory() const;
	Vecteur get_velocity_memory() const;
	bool collision(ObjetMobile&, double alpha = 0.8, double miu = 0.01, double dt = 0) override;
};
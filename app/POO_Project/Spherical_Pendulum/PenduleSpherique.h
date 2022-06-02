#pragma once
#include "../Week_4_Pendule/Pendule.h"
class PenduleSpherique:public Pendule
{
private:
	Vecteur urho;
	Vecteur utheta;
	Vecteur uphi;
	Vecteur get_expression();
	void update_coord(Balle*);
public:
	PenduleSpherique(double theta, double theta_p, double phi, double phi_p, Vecteur force, double radius, double mass,
		Vecteur origin, Vecteur direction, double L, double coeff = 0)
		:Pendule(theta, theta_p, force, radius, mass, origin, direction, L, coeff),
		urho(0,0,0), uphi(0,0,0), utheta(0,0,0)
	{
		Vecteur pos_complete(get_position());
		pos_complete.augmente(phi);
		this->set_new_pos(pos_complete);
		Vecteur velo = get_velocity();
		velo.augmente(phi_p);
		set_new_speed(velo);
		urho = update_urho();
		uphi = update_uphi();
		utheta = update_utheta();
	}
	Vecteur update_urho() const;
	Vecteur update_uphi() const;
	Vecteur update_utheta() const;
	Vecteur get_position_memory() const;
	Vecteur get_velocity_memory() const;
	double get_phi() const { return get_position().get_vector()[1]; }
	double get_phi_p() const { return get_velocity().get_vector()[1]; }
	bool collision(ObjetMobile&, double alpha = 0.8, double miu = 0.01, double dt = 0) override;
	virtual Vecteur evolve() override;
	virtual std::ostream& print(std::ostream& output) const override;
	virtual PenduleSpherique* clone() const override;
	virtual void dessine_sur(SupportADessin& support) override
	{
		support.dessine(*this);
	}
	virtual Balle* prepare_collision() override;
	void update_collision(Balle*) override;
};


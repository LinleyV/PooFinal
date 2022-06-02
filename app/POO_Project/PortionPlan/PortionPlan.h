#pragma once
#include "../Obstacles/Obstacles.h"
class PortionPlan : public Obstacle
{
public: 
		PortionPlan(const Vecteur& p={0.0,0.0,0.0}, const Vecteur& L={1.0,0.0,0.0}, const Vecteur& l = { 0.0,1.0,0.0 })
			:Obstacle(p),length(L.norme()), large(l.norme()), eL(L.unitaire()), el(l.unitaire()), 
			normal((L.unitaire()).prod_vect(l.unitaire()))
		{}
		Vecteur point_le_plus_proche(const ObjetMobile&) const override;
		double distance(const ObjetMobile&) const override;
		Vecteur get_position() const;
		bool appartient(const Vecteur&) const;
		std::vector<Vecteur> coins() const;
		virtual void dessine_sur(SupportADessin& support) override
		{
			support.dessine(*this);
		}
		virtual Obstacle* clone() const override
		{
			return new PortionPlan(*this);
		}

protected:
		double length;
		double large;
		Vecteur normal;
		Vecteur eL;
		Vecteur el;
};


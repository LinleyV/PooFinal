#pragma once
#include <iostream>
#include <cmath>
#include "../Vector_Class/New_Vector_Week_3_Final/Vecteur.h"
#include "../Obstacles/Obstacles.h"
#include "../ObjetMobile/ObjetMobile.h"
#include <bits/stdc++.h>
class Plan : public Obstacle
{
private:
		Vecteur normal;

public:
		Plan(Vecteur position, Vecteur normale, double mass=INT_MAX)
		:Obstacle(position, mass), normal(normale)
		{
            if(normale.norme() == 0.0)
			{
                throw "Vector is the vector null";
			}
			//throw "not_normal";
		}
		
		//Plan(Plan& plan) = delete;
		
		Vecteur point_le_plus_proche(const ObjetMobile& obj) const override;
		double distance(const ObjetMobile&) const override;
		Vecteur get_normal() const;
		virtual std::ostream& print(std::ostream& output) const override;
		virtual void dessine_sur(SupportADessin& support) override
		{
			support.dessine(*this);
		}
		virtual Plan* clone() const override
		{
			return new Plan(*this);
		}
};

std::ostream& operator<<(std::ostream&, Plan const&);


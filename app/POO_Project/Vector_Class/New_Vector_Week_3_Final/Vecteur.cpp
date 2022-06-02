#include "Vecteur.h"
//#include "Exception.h"
#include <vector> // this library is used for declaring the vector and for functions that work with vectors as .size()
#include <iostream>
#include <cmath> // this is for sqrt
#include <iomanip> // this is for set precision, in order to cout numbers with an exact amount of 2 decimals
void Vecteur::augmente(double valeur) // the function that adds a dimension to out vector
{
	vecteur.push_back(valeur);
}
bool Vecteur::set_coord(size_t position, double valeur) // this function changes the coordonate at the position 'position' with the value 'valeur'
{
	if (position >= vecteur.size()) // the test verifies if the searched position really exist or not and we decided to make it bool in case we need to now in the future program if we could actually modify or not
	{
		std::cout << "Component does not exist...\n";
		return false;
	}
	vecteur[position] = valeur;
	return true;
}
void Vecteur::affiche(std::ostream& sortie) const // the print function
{
	//sortie << "(";
	for (size_t i = 0; i < vecteur.size() - 1; ++i)
	{
		//sortie << std::fixed << std::showpoint;
		sortie << /*std::setprecision(2) <<*/ vecteur[i] << ", ";
		sortie.clear();
	}
	sortie << vecteur[vecteur.size() - 1] /*<< ")"*/;
}
bool Vecteur::compare(const Vecteur& vecteur) const // this function campares two vectors. We chose to consider that two vectors are equal only if they have the same dimension. (in physics it doesn`t make sens to compare a 2D mouvement with a 3D one
{
	if (!this->test_taille(vecteur))
		return false;
	for (size_t i = 0; i < vecteur.vecteur.size(); ++i)
	{
		if (vecteur.vecteur[i] != this->vecteur[i])
		{
			return false;
		}
	}
	return true;
}
bool Vecteur::test_taille(const Vecteur& vecteur) const // this is an auxiliary function created in order to help us modularise the problem and its a private method
{
	if (this->vecteur.size() != vecteur.vecteur.size())
	{
		return false;
	}
	return true;
}
Vecteur Vecteur::addition(const Vecteur& vecteur) const // this function makes the addition of two vectors. Again, we chose to consider that the vectors must have the same dimension.
{
	if (!this->test_taille(vecteur))
	{
		throw ("Size mismatch"); // here we decided to throw an exception of string type, that we will treat later.
	}
	Vecteur somme(vecteur);
	for (size_t i = 0; i < vecteur.vecteur.size(); ++i)
	{
		somme.vecteur[i] += this->vecteur[i];
	}
	return somme;
}
Vecteur Vecteur::oppose()const // the function that calculates the oposing vector, is just a multiplication by '-1'
{
	Vecteur result(this->mult(-1));
	return result;
}
Vecteur Vecteur::soustraction(const Vecteur& autre) const // we considered that the substraction is just an addition with the 'inversed' vector
{
	Vecteur result = this->addition(autre.oppose());
	return result;

}
Vecteur Vecteur::mult(double scalaire) const // the multiplication function where we took each of the vector`s components and multiplied them with the value 'scalaire'
{
	Vecteur result(0);
	for (const auto& element : vecteur)
	{
		if (element != 0)
		{
			result.vecteur.push_back(scalaire * element);
		}
		else
			result.vecteur.push_back(0.0);

	}
	return result;
}
double Vecteur::norme()const // // the norm is easily calculated when we have the norm2 of the vector
{
	return sqrt(norme2());
}
double Vecteur::norme2() const // the function calculates the vector norm2, using the math formula
{
	double result = 0;
	for (const auto& element : vecteur)
	{
		result += element * element;
	}
	return result;
}
bool Vecteur::is_3D() const // this method was made for the vectorial product, its a private method and it helps us verify if a certain vector is 3 dimensional or not
{
	if (this->vecteur.size() != 3)
	{
		return false;
	}
	return true;
}
double Vecteur::prod_scal(const Vecteur& autre) const // when we calculate a scalar product we need(maybe not in this formula) the angle between the 2 vectors. Therefore, we decided to consider only the vectors that have the same dimension, where we can define properly the angle
{
	if (!this->test_taille(autre))
	{
		throw ("Size mismatch");
	}
	double result(0.0);
	for (size_t i = 0; i < this->vecteur.size(); ++i)
	{
		result += (autre.vecteur[i] * this->vecteur[i]);
	}
	return result;

}
Vecteur Vecteur::unitaire() const //this method calculates the unit vector, meaning it has the same direction as the initial vector but a norm equal to one
{
	double norme_v = this->norme();
	if (norme_v == 0)
        return Vecteur({0,0,0}); // we verified that the vector is non-null so that we won`t divide by '0'
	double inverse = 1 / norme_v;
	Vecteur result(this->mult(inverse));
	return result;
}
Vecteur Vecteur::prod_vect(const Vecteur& autre) const // for this method we ought to make the hypothesis that the vectors are 3D. If that`s not the case we will throw an exception.
{
	if (!autre.is_3D() or !this->is_3D())
	{
		throw("Couldn't do the vectorial product, vector is not 3D !");
	}
	double first_component = this->vecteur[1] * autre.vecteur[2] - this->vecteur[2] * autre.vecteur[1];
	double second_component = this->vecteur[2] * autre.vecteur[0] - this->vecteur[0] * autre.vecteur[2];
	double third_component = this->vecteur[0] * autre.vecteur[1] - this->vecteur[1] * autre.vecteur[0];
	Vecteur result({ first_component, second_component, third_component });
	return result;
}
Vecteur& Vecteur::operator+=(const Vecteur& autre)
{
	*this = this->addition(autre);
	return *this;
}
const Vecteur operator+(Vecteur vec, const Vecteur& autre)
{
	return vec += autre;
}
bool operator==(const Vecteur& vec, const Vecteur& autre)
{
	return vec.compare(autre);
}
bool operator!=(const Vecteur& vec, const Vecteur& autre)
{
	return !(vec == autre);
}
std::ostream& operator<<(std::ostream& sortie, Vecteur const& vec)
{
	vec.affiche(sortie);
	return sortie;
}
Vecteur& Vecteur::operator*=(double scal)
{
	*this = this->mult(scal);
	return *this;
}
const Vecteur operator*(Vecteur vec, double scal)
{
	return vec *= scal;
}
const Vecteur operator*(double scal, Vecteur vec)
{
	return vec * scal;
}
Vecteur& Vecteur::operator-=(Vecteur const& autre)
{
	*this = this->soustraction(autre);
	return *this;
}
const Vecteur operator-(Vecteur vec1, Vecteur const& vec2)
{
	return vec1 + (-1.0 * vec2); // return vec1 -= vec2; 
}
const Vecteur operator^(Vecteur vec1, Vecteur const& vec2)
{
	return vec1.prod_vect(vec2);
}
const Vecteur operator~(Vecteur const& vec)
{
	return vec.unitaire();
}
double Vecteur::operator*=(const Vecteur& vec)
{
	double retour(0.0);
	retour = this->prod_scal(vec);
	return retour;
}
const double operator*(Vecteur vec, Vecteur const& autre)
{
	return vec *= autre;
}
my_vector Vecteur::get_vector() const
{
	return vecteur;
}
size_t Vecteur::size() const
{
	return vecteur.size();
}

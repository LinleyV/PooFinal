#pragma once
#include <vector>
#include <iostream>
#include <initializer_list>
typedef std::vector<double> my_vector; // we  used a typedef for the vector
class Vecteur
{
private:
	// attributs
	my_vector vecteur;
	// private methods
	bool test_taille(const Vecteur& vecteur)const;
	bool is_3D() const;
public:
	// constructors:
	Vecteur(size_t dim) // 0 vector of a certain dimension
	{
		vecteur.clear();
		for (size_t x = 0; x < dim; ++x)
		{
			vecteur.push_back(0.0);
		}
	}
	Vecteur(double x, double y, double z) // 3D constructor from coordinates
	{
		vecteur.push_back(x);
		vecteur.push_back(y);
		vecteur.push_back(z);
	}
	Vecteur(std::initializer_list<double> list)
		:vecteur(list)
	{}
	~Vecteur() // destructor
	{
		///std::cout << "We will render this variable unusable because of an error in the program...\n";
	}
	// Public methods:
	void augmente(double);
	bool set_coord(size_t, double);
	void affiche(std::ostream&) const;
	bool compare(const Vecteur& vecteur) const;
	Vecteur oppose() const;
	Vecteur addition(const Vecteur& vecteur) const;
	Vecteur soustraction(const Vecteur& vecteur) const;
	Vecteur mult(double scalaire) const;
	double prod_scal(const Vecteur& autre) const;
	double norme() const;
	double norme2() const;
	Vecteur unitaire() const;
	Vecteur prod_vect(const Vecteur& autre) const;
	Vecteur& operator+=(const Vecteur& autre);
	Vecteur& operator*=(double scal);
	Vecteur& operator-=(Vecteur const& autre);
	double operator*=(const Vecteur& vec);
	size_t size() const;
	my_vector get_vector() const;
};
bool operator==(const Vecteur& vec, const Vecteur& autre);
bool operator!=(const Vecteur& vec, const Vecteur& autre);
std::ostream& operator<<(std::ostream& sortie, Vecteur const& vec);
const Vecteur operator+(Vecteur vec, const Vecteur& autre);
const Vecteur operator*(Vecteur vec, double scal);
const Vecteur operator*(double scal, Vecteur vec);
const Vecteur operator-(Vecteur vec1, Vecteur const& vec2);
const Vecteur operator^(Vecteur vec1, Vecteur const& vec2);
const Vecteur operator~(Vecteur const& vec);
const double operator*(Vecteur vec, Vecteur const& autre);

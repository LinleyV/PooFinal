#pragma once
//#if !defined INCLUDED_FILES
//#define INCLUDED_FILES
#include "../ObjetMobile/ObjetMobile.h"
#include "../Obstacles/Obstacles.h"
#include "../Integrateurs/Integrateurs.h"
#include "../ComposedObjects_Class/ComposedObjects.h"
#include "../ForceField_class/ChampsForces.h"
#include <vector>
#include <iostream>
//#endif
//class ObjetMobile;
//class Obstacle;
//class ComposedObjects;
class System
{
private:
	std::vector<ObjetMobile*> collection_objects;
	std::vector<Obstacle*> collection_obstacles;
	std::vector<ForceField*> collection_force;
	size_t find_obstacle(ForceField* f)const;
	size_t find_force(Obstacle*)const;

public:
	~System()
	{
		for (size_t i = 0; i < collection_objects.size(); ++i)
			delete collection_objects[i];
		for (size_t i = 0; i < collection_obstacles.size(); ++i)
			delete collection_obstacles[i];
		collection_obstacles.clear();
	}
	std::ostream& affiche_objet(std::ostream& output = std::cout) const;
	std::ostream& affiche_force(std::ostream& output = std::cout) const;
	std::ostream& affiche_obstacle(std::ostream& output = std::cout) const;
	std::ostream& affiche_system(std::ostream& output = std::cout) const;
	void add_Mobile_Object(ObjetMobile const &object);
	void add_force(ForceField const&);
	void delete_force(size_t);
    ForceField* get_pointer_force(size_t index = 0) const;
	void set_pointer_force(size_t, ForceField const&);
	void add_Obstacle(Obstacle const& obs);
	void add_composed_object(ComposedObjects const&);
	void set_pointer_mobile_object(size_t index, ObjetMobile*);
	ObjetMobile* get_pointer_mobile_object(size_t index = 0) const;
	void set_pointer_obstacle(size_t index, Obstacle*);
	Obstacle* get_pointer_obstacle(size_t index = 0) const;
	void delete_object(size_t index);
	void delete_obstacle(size_t index);
	void update_forces(ObjetMobile* obj);
    void RUN_SYST(Integrateurs&, double alpha = 0.8, double miu = 0.01, bool first = false);
	void RUN(Integrateurs&, int times, bool first = false);
};
std::ostream& operator<<(std::ostream& output, System const&);

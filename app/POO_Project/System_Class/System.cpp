#include "System.h"
void System::add_Mobile_Object(ObjetMobile const& object)
{
	ObjetMobile* pointer = object.clone();
	for (const auto& el : collection_force)
	{
		pointer->add_force(el->get_intensity());
	}
	collection_objects.push_back(pointer);
}
void System::add_Obstacle(Obstacle const& obs)
{
	Obstacle* pointer = obs.clone();
	collection_obstacles.push_back(pointer);
}
void System::add_composed_object(ComposedObjects const& c)
{
	ObjetMobile* object = c.get_object();
	Obstacle* obstacle = c.get_obstacle();
	ForceField* f = c.get_force_f();
	/*for(const auto& element:collection_objects)
	if (f->is_in_range(*element))
	{
		f->calculate_intensity(*element);
		f->modify_force_mobile_object(*element);
	}*/
	if (object != nullptr)
		add_Mobile_Object(*object);
	if (obstacle != nullptr) {
		//collection_obstacles.push_back(obstacle);
		add_Obstacle(*obstacle);
		if (f != nullptr)
		{
			f->set_obstacle(collection_obstacles.size() - 1);
		}
	}
	if (f != nullptr) {
		//collection_force.push_back(f);
		add_force(*f);
		if(obstacle != nullptr){
			collection_obstacles[collection_obstacles.size() - 1]->set_force(collection_force.size() - 1);
		}
	}
}
std::ostream& System::affiche_objet(std::ostream& output) const
{
	if (collection_objects.empty())
		return output;
	output << "The mobile objects in our system: \n";
	for (const auto& el : collection_objects)
		el->print(output);
	return output;
}
std::ostream& System::affiche_obstacle(std::ostream& output) const
{
	if (collection_obstacles.empty())
		return output;
	output << "The obstacles in our system: \n";
	for (const auto& el : collection_obstacles)
		el->print(output);
	return output;
}
std::ostream& System::affiche_force(std::ostream& output) const
{
	if (collection_force.empty())
		return output;
	output << "the forces in our system: \n";
	for (const auto& el : collection_force)
		output << *el;
	return output;
}
std::ostream& System::affiche_system(std::ostream& output) const
{
	output << "\n";
	affiche_objet(output);
	output << '\n';
	affiche_obstacle(output);
	output << '\n';
	affiche_force(output);
	return output;
}
std::ostream& operator<<(std::ostream& output, System const& syst)
{
	syst.affiche_system(output);
	return output;
}
ObjetMobile* System::get_pointer_mobile_object(size_t index) const
{
	if(!(index>= 0 and index < collection_objects.size()))
		return nullptr;
	return collection_objects[index]->clone();
}
Obstacle* System::get_pointer_obstacle(size_t index) const
{
	if (!(index >= 0 and index < collection_objects.size()))
		return nullptr;
	return collection_obstacles[index]->clone();
}
void System::set_pointer_mobile_object(size_t index, ObjetMobile* ptr)
{
	if (!(index >= 0 and index < collection_objects.size()))
		return;
	
	delete collection_objects[index];
	collection_objects[index] = ptr;
}
void System::set_pointer_obstacle(size_t index, Obstacle* ptr)
{
	if (!(index >= 0 and index < collection_objects.size()))
		return;
	delete collection_obstacles[index];
	collection_obstacles[index] = ptr;
}
void System::delete_object(size_t index)
{
	if (!(index >= 0 and index < collection_objects.size()))
		return;
	for (size_t i = index + 1; i < collection_objects.size(); i++)
	{
		delete collection_objects[i - 1];
		collection_objects[i - 1] = collection_objects[i];
	}
	delete collection_objects[collection_objects.size() - 1];
	collection_objects.pop_back();
}
void System::delete_obstacle(size_t index)
{
	if (!(index >= 0 and index < collection_obstacles.size()))
		return;
	for (size_t i = index + 1; i < collection_obstacles.size(); i++)
	{
		if (collection_obstacles[i - 1]->get_force() < collection_force.size() and collection_obstacles[i - 1]->get_force() >= 0)
		{
			size_t n = collection_obstacles[i - 1]->get_force();
			collection_force[n]->set_obstacle(collection_obstacles.size() + 10);
			delete_force(n);
		}
		delete collection_obstacles[i - 1];
		collection_obstacles[i - 1] = collection_obstacles[i];
	}
	size_t i = collection_obstacles.size();
	if (collection_obstacles[i - 1]->get_force() < collection_force.size() and collection_obstacles[i - 1]->get_force() >= 0)
	{
		size_t n = collection_obstacles[i - 1]->get_force();
		collection_force[n]->set_obstacle(collection_obstacles.size() + 10);
		delete_force(n);
	}
	delete collection_obstacles[i - 1];
	collection_obstacles.pop_back();
}
void System::RUN_SYST(Integrateurs& I, double alpha, double miu, bool first)
{
	/*Vecteur total_force({ 0,0,0 });
	bool is_g_field(false);
	for (const auto& f : collection_force)
	{
		if (f->get_intensity() != g)
			total_force += f->get_intensity();
		else
			is_g_field = true;
	}*/
	for (size_t i = 0; i < collection_objects.size(); ++i)
	{
        bool shock = false;
		collection_objects[i]->set_new_force({ 0,0,0 });
		update_forces(collection_objects[i]);
		for (size_t j = i + 1; j < collection_objects.size(); ++j)
		{
			collection_objects[j]->set_new_force({ 0,0,0 });
			update_forces(collection_objects[j]);
            bool col = collection_objects[j]->collision(*collection_objects[i], alpha, miu);
            if(col)
            {
                shock = true;
            }
			/*else {
				I.set_object(collection_objects[j]);
				if (first == true)
					this->set_pointer_mobile_object(j, I.first_order());
				else
					this->set_pointer_mobile_object(j, I.second_order());
			}*/
		}
        for (size_t k = 0; k < collection_obstacles.size(); ++k)
        {
           bool col =  collection_obstacles[k]->collision(*collection_objects[i], alpha, miu);
           if(col){
               shock = true;
           }
        }
		I.set_object(collection_objects[i]);
        if(shock == false){
		if(first == true)
			this->set_pointer_mobile_object(i, I.first_order());
		else
			this->set_pointer_mobile_object(i, I.second_order());
        }
	}
}
void System::add_force(ForceField const& f)
{
	collection_force.push_back(new ForceField(f));
	for (auto& el : collection_objects)
		el->add_force(f.get_intensity());
}
ForceField* System::get_pointer_force(size_t index) const
{
    if (index < 0 or index >= collection_force.size())
		return nullptr;
	return collection_force[index]->clone();
}
void System::set_pointer_force(size_t i, ForceField const& f)
{
	if (i < collection_force.size())
	{
		delete collection_force[i];
		collection_force[i] = new ForceField(f);
	}
}
void System::delete_force(size_t index)
{
	if (index < collection_force.size())
	{
		for (size_t i = index + 1; i < collection_force.size(); i++)
		{
			if (collection_force[i - 1]->get_obstacle() < collection_obstacles.size() and collection_force[i - 1]->get_obstacle() >= 0)
			{
				size_t n = collection_force[i - 1]->get_obstacle();
				collection_obstacles[n]->set_force(collection_force.size() + 10);
				delete_force(n);
			}
			delete collection_force[i - 1];
			collection_force[i - 1] = collection_force[i];
		}
		size_t i = collection_force.size();
		if (collection_force[i - 1]->get_obstacle() < collection_obstacles.size() and collection_force[i - 1]->get_obstacle() >= 0)
		{
			size_t n = collection_force[i - 1]->get_obstacle();
			collection_obstacles[n]->set_force(collection_force.size() + 10);
			delete_force(n);
		}
		delete collection_force[collection_force.size() - 1];
		collection_force.pop_back();
	}
}
void System::RUN(Integrateurs& integ, int times, bool first)
{
	for (int i = 1; i <= times; ++i)
	{
		RUN_SYST(integ, first);
		affiche_system();
	}
}
void System::update_forces(ObjetMobile* obj)
{
	for (const auto& f : collection_force)
	{
		if (f->is_in_range(*obj))
			f->modify_force_mobile_object(*obj);
	}
}
//size_t System::find_obstacle(ForceField* f) const
//{
//	for (size_t i = 0; i < collection_obstacles.size() ; ++i)
//	{
//		if (collection_obstacles[i]->get_force() == f)
//			return i;
//	}
//	return collection_obstacles.size() + 10;
//}
//size_t System::find_force(Obstacle* obs) const
//{
//	for (size_t i = 0; i < collection_force.size(); ++i)
//	{
//		if (collection_force[i]->get_obstacle() == obs)
//			return i;
//	}
//	return collection_force.size() + 10;
//}
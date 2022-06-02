#pragma once
class ObjetMobile;
class Obstacle;
class ForceField;
class ComposedObjects
{
private:
	ObjetMobile* object;
	Obstacle* obstacle;
	ForceField* force_f;
public:
	ComposedObjects(ObjetMobile* objet = nullptr, Obstacle* obstacle = nullptr, ForceField* force_f = nullptr)
		:object(objet), obstacle(obstacle), force_f(force_f)
	{}
	ObjetMobile* get_object() const { return object; }
	Obstacle* get_obstacle() const { return obstacle; }
	ForceField* get_force_f() const { return force_f; }
	virtual ~ComposedObjects() = default;
	//virtual void add_to_system(System&) const = 0;
};


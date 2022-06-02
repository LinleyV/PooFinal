#include "Runge-Kutta.h"

ObjetMobile* RungeKutta::first_order()
{
	ObjetMobile* objet = object->clone();
	Vecteur position(objet->get_position()); // P (position) at Tn-1=t (before integration)
	Vecteur k1(objet->evolve());//t, position)); // first Runge-Kutta coefficient
	Vecteur k2(objet->evolve());//t+ dt/2, position + (dt/2)*k1)); // second Runge-Kutta coefficient
	Vecteur k3(objet->evolve());//t+ dt/2, position + (dt/2)*k2)); // third Runge-Kutta coefficient
	Vecteur k4(objet->evolve());//t+dt, position + dt*k3)); // fourth Runge-Kutta coefficient
	position += (dt/6)*(k1+2*k2+2*k3+k4); // new position at t+dt
	objet->set_new_pos(position); // new ObjetMobile at Tn=Tn-1 + dt=t+dt
	return objet;
}

ObjetMobile* RungeKutta::second_order()
{
	ObjetMobile* objet = object->clone();
	Vecteur position(objet->get_position()); // P (position) at Tn-1=t (before integration)
	Vecteur velocity(objet->get_velocity()); // P' (velocity) at Tn-1 (before integration)
	Vecteur k1(velocity); // first Runge-Kutta coefficient
	Vecteur K1(objet->evolve());//t, position, velocity)); // k1', derivative of k1
	Vecteur k2(velocity + (dt/2) * K1);
	Vecteur K2(objet->evolve());// t + dt / 2, position + (k1 * (dt / 2)), velocity + (K1 * (dt / 2)));
	Vecteur k3(velocity + (K2*(dt/2)));
	Vecteur K3(objet->evolve());// t + dt / 2, position + (k2 * (dt / 2)), velocity + (K2 * (dt / 2))));
	Vecteur k4(velocity + dt*K3);
	Vecteur K4(objet->evolve());// t + dt, position + dt * k3, velocity + dt * K3));
	position = position+(dt/6)*(k1+2*k2+2*k3+k4); // new position at Tn
	velocity = velocity+(dt/6)*(K1+2*K2+2*K3+K4); // new velocity at Tn
	objet->set_new_pos(position);
	objet->set_new_speed(velocity);// new ObjetMobile at Tn=Tn-1 + dt=t+dt
	return objet;
}

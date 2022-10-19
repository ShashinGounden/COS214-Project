#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
	protected:
	int power;

	public:
	Weapon(int P);
	int fire();
	~Weapon();
};
#endif

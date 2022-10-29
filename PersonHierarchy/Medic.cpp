#include "Medic.h"

Medic::Medic(int id, int i, std::string s) : Person(id, i, s) {}

Medic::~Medic() {}

Person *Medic::clone()
{
    return new Medic(getID(), getHealth(), getSkill());
}

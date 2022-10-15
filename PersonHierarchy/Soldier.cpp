#include "Soldier.h"

Soldier::Soldier(int i) : Person(i)
{
    id = i;
}

Soldier::~Soldier()
{
    std::cout << "ID: " << id << " Deleted\n";
}

void Soldier::Attack()
{
    if (id % 5 == 0)
    {
        std::cout << "ATTACK!\n";
    }
}

void Soldier::applyMedication() {}

void Soldier::Retreat()
{
    if (id % 9 == 0)
    {
        std::cout << "RETREAT!\n";
    }
}

int Soldier::getID()
{
    return id;
}
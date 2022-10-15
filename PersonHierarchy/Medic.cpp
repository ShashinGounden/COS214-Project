#include "Medic.h"

Medic::Medic(int i) : Person(i)
{
    id = i;
}

Medic::~Medic()
{
    std::cout << "ID: " << id << " Deleted\n";
}

void Medic::Attack()
{
    if (id % 2 == 0)
    {
        std::cout << "Prepares to aid injured soldiers\n";
    }
}

void Medic::applyMedication()
{
    if (id % 3 == 0)
    {
        std::cout << "Applies bandages to wounded soldier\n";
    }
    else if (id % 5 == 0)
    {
        std::cout << "Applies morphine to injured soldier\n";
    }
    else
    {
        std::cout << "Sutures soldiers wounds\n";
    }
}

void Medic::Retreat()
{
    if (id % 13 == 0)
    {
        std::cout << "RETREAT!\n";
    }
}

int Medic::getID()
{
    return id;
}
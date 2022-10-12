#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "../Country/Country.h"

class Person : public Country
{
public:
    Person();
    ~Person();

    //virtual void Attack() = 0;
    virtual void applyMedication() = 0;
    //virtual void Retreat() = 0;

    int getID();

    // Person* clone();

private:
    int CurrentID = 0;
};

#endif
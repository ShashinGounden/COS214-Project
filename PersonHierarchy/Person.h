#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
public:
    Person(int);
    virtual ~Person();

    virtual void Attack() = 0;
    virtual void applyMedication() = 0;
    virtual void Retreat() = 0;

    virtual int getID() = 0;
    // Person* clone();
};

#endif
#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
public:
    Person();
    ~Person();

    virtual void attack() = 0;
    virtual void applyMedication() = 0;
    virtual void retreat() = 0;

    int getID();

private:
    int CurrentID = 0;
};

#endif
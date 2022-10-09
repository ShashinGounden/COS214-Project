#include "MedicUnitIterator.h"

MedicUnitIterator::MedicUnitIterator(std::list<Person*> list) : ArmyIterator(list){
    unit = list;
    curr = unit.front();
}

MedicUnitIterator::~MedicUnitIterator(){
    delete unit;
}

Person* MedicUnitIterator::first(){
    return unit.front();
}

Person* MedicUnitIterator::next(){
    for(auto it = unit.begin(); it != unit.end(); it++){
        if((*it) == curr){ // NEED TO ADD What to compare to here!
            it++;
            return (*it);
        }
    }
    std::cout<<"Reached end of Unit!\n";
    return nullptr;
}

bool MedicUnitIterator::hasNext(){
    if(curr == *unit.end()){
        return false;
    }else return true;
}

Person* MedicUnitIterator::current(){
    return curr;
}

void MedicUnitIterator::increment(){
    if(hasNext()){
        curr = next(); // current will be pointed to next person in unit
    }else{
        curr = first(); // current can point back to the front of the list
    }
}
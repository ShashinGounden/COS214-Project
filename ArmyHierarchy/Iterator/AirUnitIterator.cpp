#include "AirUnitIterator.h"

/**
 * @brief Construct a new Air Unit Iterator:: Air Unit Iterator object
 * 
 * @param list 
 */
AirUnitIterator::AirUnitIterator(std::list<Person*> list) : ArmyIterator(list){
    unit = list;
    curr = unit.front();
}

/**
 * @brief 
 * 
 * @return Person* 
 */
Person* AirUnitIterator::first(){
    return unit.front();
}

/**
 * @brief 
 * 
 * @return Person* 
 */
Person* AirUnitIterator::next(){
    for(auto it = unit.begin(); it != unit.end(); it++){
        if((*it) == curr){ // NEED TO ADD What to compare to here!
            it++;
            return (*it);
        }
    }
    std::cout<<"Reached end of Unit!\n";
    return nullptr;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool AirUnitIterator::hasNext(){
    if(curr == *unit.end()){
        return false;
    }else return true;
}

/**
 * @brief 
 * 
 * @return Person* 
 */
Person* AirUnitIterator::current(){
    return curr;
}

/**
 * @brief 
 * This it to change current to next
 */
void AirUnitIterator::increment(){
    if(hasNext()){
        curr = next();
    }else{
        curr = first();
    }
}
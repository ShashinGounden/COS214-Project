#include "Alliance.h"
#include <random>

Alliance::Alliance() {

    //Initialise list of responses
    responses.push_back("one");
    responses.push_back("two");
    responses.push_back("three");
    responses.push_back("four");
    responses.push_back("five");

}

Alliance::~Alliance() {
    allianceList.clear();
}

void Alliance::addAlliance(Country *c) {
    allianceList.push_back(c);
}

void Alliance::removeAlliance(Country *c) {
    allianceList.remove(c);
}

void Alliance::update() {
    int listLength = responses.size();

    int random = rand() % listLength;

    int counter = 0;
    for (auto i = responses.begin(); i != responses.end(); ++i)
    {
        if(counter == random)
        {
            std::cout << *i << std::endl ;
        }
    }

}
#include "Alliance.h"
#include <random>

/**
 * @brief Construct a new Alliance:: Alliance object
 * 
 */
Alliance::Alliance()
{
    //@Todo: Add responses and Test

    // Initialise list of responses
    responses.push_back(" joins one of the biggest alliances formed during the war.");
    responses.push_back(" joins new allies as tensions rises in thew West");
    responses.push_back("three");
    responses.push_back("four");
    responses.push_back("five");
}

/**
 * @brief Destroy the Alliance:: Alliance object
 * 
 */
Alliance::~Alliance()
{
    allianceList.clear();
}

/**
 * @brief function to add a country object to the alliance list
 * 
 * @param c 
 */
void Alliance::addAlliance(Country *c)
{
    allianceList.push_back(c);
}

/**
 * @brief function to remove a country object from the alliance list
 * 
 * @param c 
 */
void Alliance::removeAlliance(Country *c)
{
    allianceList.remove(c);
}

/**
 * @brief 
 * 
 */
void Alliance::update()
{
    // Get the length of the list for responses list and the alliance list
    int responselistLength = responses.size();
    int countrylistLength = allianceList.size();

    // ensure that the list of alliances are not empty
    if (countrylistLength == 0)
    {
        std::cout << "Governments are still too skeptical about joining Alliances." << std::endl;
        return;
    }
    // Generate a random index to select a random response and country to form an update()
    int randomResponse = rand() % responselistLength;
    int randomCountry = rand() % countrylistLength;

    // Output string for the final output/update
    std::string output = "";

    // Iterate through the country list until the index has been reached and add the country to output
    int counterCountry = 0;
    for (auto x = allianceList.begin(); x != allianceList.end(); ++x)
    {
        if (counterCountry == randomCountry)
        {
            Country *c = *x;
            output += c->getName();
        }
        counterCountry++;
    }

    // Iterate through the responses list until the index has been reached and add the country to output
    int counterResponses = 0;
    for (auto i = responses.begin(); i != responses.end(); ++i)
    {
        if (counterResponses == randomResponse)
        {
            output += *i; // add a country name
        }
        counterResponses++;
    }

    std::cout << output << std::endl;
}
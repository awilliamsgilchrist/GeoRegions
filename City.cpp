//
// Created by Stephen Clyde on 3/4/17.
//

#include "City.h"

// TODO: Implement functionality of City class
//Done
City::City(const std::string data[]) : Region(CityType, data)
{
    validate();
}
//ENDOF TODO
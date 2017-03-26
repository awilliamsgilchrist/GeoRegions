//
// Created by Stephen Clyde on 3/13/17.
//

#include "RegionTester.h"

#include "../Region.h"

#include <iostream>
#include <fstream>

void RegionTester::testCreateFromStream()
{
    std::cout << "RegionTester::testCreateFromStream" << std::endl;

    // Load a file with just the world in it
    {
        std::string inputFile = "SampleData/sampleData-1.txt";
        std::ifstream inputStream(inputFile);
        Region* region = Region::create(inputStream);
        if (region==nullptr)
        {
            std::cout << "Failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (region->getType()!=Region::RegionType::WorldType)
        {
            std::cout << "Failed to create correct type of region from " << inputFile << std::endl;
            std::cout << "\tExpected World region type, but created a " << region->getRegionLabel() << std::endl;
            return;
        }
    }

    // Load a file with the and four nations
    {
        std::string inputFile = "SampleData/sampleData-2.txt";
        std::ifstream inputStream(inputFile);
        Region* world = Region::create(inputStream);
        if (world==nullptr)
        {
            std::cout << "Failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (world->getType()!=Region::RegionType::WorldType)
        {
            std::cout << "Failed to create correct type of region from " << inputFile << std::endl;
            std::cout << "\tExpected World region type, but created a " << world->getRegionLabel() << std::endl;
            return;
        }

        if (world->getSubRegionCount()!=4)
        {
            std::cout << "Failed to load the four expected nations from " << inputFile << std::endl;
            std::cout << "\tExpected 4 nations, but loaded a " << world->getSubRegionCount() << std::endl;
            return;
        }

        for (unsigned int nationIndex=0; nationIndex < world->getSubRegionCount(); nationIndex++)
        {
            Region* nation = world->getSubRegionByIndex(nationIndex);
            if (nation->getType()!=Region::RegionType::NationType)
            {
                std::cout << "Failed to create correct type of sub-region in the world from " << inputFile << std::endl;
                std::cout << "\tExpected nation sub-region type, but created a " << nation->getRegionLabel() << std::endl;
                return;
            }
        }
    }

}

void RegionTester::testCreateFromString()
{
    std::cout << "RegionTester::testCreateFromString" << std::endl;

    {
        std::string inputString = "2,Tiny Country,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Country region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny Country\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "3,Tiny State,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::StateType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected State region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny State") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny State\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "4,Tiny County,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CountyType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected County region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny County") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "5,Tiny City,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CityType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected City region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny City") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny City\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(inputString);
        if (region != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

    {
        std::string inputString = "2,30,20";
        Region *region = Region::create(inputString);
        if (region != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

}

void RegionTester::testCreateFromTypeAndString()
{
    std::cout << "RegionTester::testCreateFromTypeAndString" << std::endl;

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(Region::NationType,inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Nation region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny State,30,20";
        Region *region = Region::create(Region::RegionType::StateType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::StateType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected State region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny State") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny State\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny County,30,20";
        Region *region = Region::create(Region::RegionType::CountyType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CountyType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected County region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny County") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny City,30,20";
        Region *region = Region::create(Region::RegionType::CityType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CityType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected City region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny City") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny City\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny Country,30";
        Region *r1 = Region::create(Region::NationType,inputString);
        if (r1 != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

    {
        std::string inputString = "2";
        Region *r1 = Region::create(Region::NationType, inputString);
        if (r1 != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

}

void RegionTester::testGettersAndSetters()
{
    std::cout << "RegionTester::testGettersAndSetters" << std::endl;

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(Region::NationType,inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Nation region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }

        region->setName("Really Tiny County");
        if (region->getName() != "Really Tiny County") {
            std::cout << "Failed to set the name for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Really Tiny County\", but got \"" << region->getName() << "\"" << std::endl;
            return;
        }

        region->setPopulation(5);
        if (region->getPopulation()!=5) {
            std::cout << "Failed to set the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 5, but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        region->setArea(2);
        if (region->getArea()!=2) {
            std::cout << "Failed to set the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 2, but got \"" << region->getArea() << "\"" << std::endl;
            return;
        }
    }
}

void RegionTester::testSubRegions()
{
    std::cout << "RegionTester::testSubRegions" << std::endl;

    // TODO: Add test cases for managing sub-regions
    //Done

    //NOTE: There is no test case for the function Region::appendChild(), because all other test cases
    //rely on it being correct, and the function is trivial. Therefore, we take its effectiveness as a given.

    Region* testRegion = Region::create(Region::RegionType::WorldType, "World,10,10");
    testRegion->appendChild(Region::create(Region::RegionType::NationType, "Nation1,10,10"));
    testRegion->appendChild(Region::create(Region::RegionType::NationType, "Nation2,10,10"));
    testRegion->appendChild(Region::create(Region::RegionType::NationType, "Nation3,10,10"));
    Region* testNation = Region::create(Region::RegionType::NationType, "Nation4,10,10");
    testNation->appendChild(Region::create(Region::RegionType::StateType, "State1,5,10"));
    testRegion->appendChild(testNation);

    const std::string FAILURE = "Failure";
    const std::string SUCCESS = "Success!";
    std::string testResult;

    std::cout << "Test case for findID(): ";
    testResult = (testRegion->findID(19) == testNation) ? SUCCESS : FAILURE;
    std::cout << testResult << std::endl;

    std::cout << "Test case for findParentByChildID(): ";
    testResult = (testRegion->findParentByChildID(20) == testNation) ? SUCCESS : FAILURE;
    std::cout << testResult << std::endl;

    std::cout << "Test case for getSubRegionCount(): ";
    testResult = (testRegion->getSubRegionCount() == 4) ? SUCCESS : FAILURE;
    std::cout << testResult << std::endl;

    std::cout << "Test case for getSubRegionByIndex(): ";
    testResult = (testRegion->getSubRegionByIndex(3) == testNation) ? SUCCESS : FAILURE;
    std::cout << testResult << std::endl;

    std::cout << "Test case for removeSubRegion(): ";
    testRegion->removeSubRegion(testNation);
    testResult = (testRegion->getSubRegionCount() == 3) ? SUCCESS : FAILURE;
    std::cout << testResult << std::endl;

    //ENDOF TODO
}

void RegionTester::testComputeTotalPopulation()
{
    std::cout << "RegionTester::testComputeTotalPopulation" << std::endl;
    std::string testMessage = "";

    // TODO: Add test cases for computeTotalPopulation
    //Done
    Region* testRegion = Region::create(Region::RegionType::WorldType, "TestWorld,0,800");
    std::cout << "Test case for one region: ";
    testMessage = testRegion->computeTotalPopulation() == 0 ? "Success!" : "Returned incorrect value";
    std::cout << testMessage << std::endl;
    Region* testSubRegion1 = Region::create(Region::RegionType::NationType, "TestNation1,30,50");
    Region* testSubRegion2 = Region::create(Region::RegionType::NationType, "TestNation2,50,50");
    testRegion->appendChild(testSubRegion1);
    testRegion->appendChild(testSubRegion2);
    std::cout << "Test case for one region with two children: ";
    testMessage = testRegion->computeTotalPopulation() == 80 ? "Success!" : "Returned incorrect value";
    std::cout << testMessage << std::endl;
    Region* grandSubRegion1 = Region::create(Region::RegionType::StateType, "TestState 1,20,60");
    Region* grandSubRegion2 = Region::create(Region::RegionType::StateType, "TestState 1,40,60");
    testSubRegion1->appendChild(grandSubRegion1);
    testSubRegion1->appendChild(grandSubRegion2);
    std::cout << "Test case for one region with two children and two grandchildren: ";
    testMessage = testRegion->computeTotalPopulation() == 140 ? "Success!" : "Returned incorrect value";
    std::cout << testMessage << std::endl;
    //ENDOF TODO
}

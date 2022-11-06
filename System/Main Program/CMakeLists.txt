cmake_minimum_required(VERSION 3.14)

project(COS214-Project VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()
add_executable(
        mainTester
        UnitTests/test.cc
        UnitTests/PhaseTest.cc
        UnitTests/TransportTest.cc
        UnitTests/ArmyTest.cc
        UnitTests/GroundUnitTest.cc
        UnitTests/MedicTest.cc
        UnitTests/MedicFactory.cc
        ./ArmyHierarchy/Iterator/AirUnitIterator.cpp
        ./ArmyHierarchy/Iterator/ArmyIterator.cpp
        ./ArmyHierarchy/Iterator/GroundUnitIterator.cpp
        ./ArmyHierarchy/Iterator/MedicUnitIterator.cpp
        ./ArmyHierarchy/Transport/Aircraft.cpp
        ./ArmyHierarchy/Transport/AircraftMaker.cpp
        ./ArmyHierarchy/Transport/ArmouredTruck.cpp
        ./ArmyHierarchy/Transport/ArmouredTruckMaker.cpp
        ./ArmyHierarchy/Transport/TankMaker.cpp
        ./ArmyHierarchy/Transport/Tank.cpp
        ./ArmyHierarchy/Transport/TransportBuilder.cpp
        ./ArmyHierarchy/Transport/Transport.cpp
        ./ArmyHierarchy/AirUnit.cpp
        ./ArmyHierarchy/Army.cpp
        ./ArmyHierarchy/GroundUnit.cpp
        ./ArmyHierarchy/MedicUnit.cpp
        ./ArmyHierarchy/Unit.cpp
        ./Country/Alliance.cpp
        ./Country/Artillery.cpp
        ./Country/Country.cpp
        ./Country/Nuke.cpp
        ./Country/WMD.cpp
        ./PersonHierarchy/PersonFactory/MedicFactory.cpp
        ./PersonHierarchy/PersonFactory/PersonFactory.cpp
        ./PersonHierarchy/PersonFactory/SoldierFactory.cpp
        ./PersonHierarchy/Medic.cpp
        ./PersonHierarchy/Person.cpp
        ./PersonHierarchy/Soldier.cpp
        ./Phase/Phase.cpp
        ./Phase/Deter.cpp
        ./Phase/Dominate.cpp
        ./Phase/Seize.cpp
        ./WarTheater/Airspace.cpp
        ./WarTheater/Sea.cpp
        ./WarTheater/WarTheater.cpp
        ./WeaponHierarchy/Bazooka.cpp
        ./WeaponHierarchy/Cal45short.cpp
        ./WeaponHierarchy/Colt12B.cpp
        ./WeaponHierarchy/ExplosiveFactory.cpp
        ./WeaponHierarchy/ExplosiveProduct.cpp
        ./WeaponHierarchy/GasBomb.cpp
        ./WeaponHierarchy/M1Garand.cpp
        ./WeaponHierarchy/M1917Enfield.cpp
        ./WeaponHierarchy/PistolFactory.cpp
        ./WeaponHierarchy/PistolProduct.cpp
        ./WeaponHierarchy/RifleFactory.cpp
        ./WeaponHierarchy/RifleProduct.cpp
        ./WeaponHierarchy/Weapon.cpp
        ./WeaponHierarchy/WeaponFactory.cpp)
add_executable(${PROJECT_NAME}
        main.cpp
        ./ArmyHierarchy/Iterator/AirUnitIterator.cpp
        ./ArmyHierarchy/Iterator/ArmyIterator.cpp
        ./ArmyHierarchy/Iterator/GroundUnitIterator.cpp
        ./ArmyHierarchy/Iterator/MedicUnitIterator.cpp
        ./ArmyHierarchy/Transport/Aircraft.cpp
        ./ArmyHierarchy/Transport/AircraftMaker.cpp
        ./ArmyHierarchy/Transport/ArmouredTruck.cpp
        ./ArmyHierarchy/Transport/ArmouredTruckMaker.cpp
        ./ArmyHierarchy/Transport/TankMaker.cpp
        ./ArmyHierarchy/Transport/Tank.cpp
        ./ArmyHierarchy/Transport/TransportBuilder.cpp
        ./ArmyHierarchy/Transport/Transport.cpp
        ./ArmyHierarchy/AirUnit.cpp
        ./ArmyHierarchy/Army.cpp
        ./ArmyHierarchy/GroundUnit.cpp
        ./ArmyHierarchy/MedicUnit.cpp
        ./ArmyHierarchy/Unit.cpp
        ./Country/Alliance.cpp
        ./Country/Artillery.cpp
        ./Country/Country.cpp
        ./Country/Nuke.cpp
        ./Country/WMD.cpp
        ./PersonHierarchy/PersonFactory/MedicFactory.cpp
        ./PersonHierarchy/PersonFactory/PersonFactory.cpp
        ./PersonHierarchy/PersonFactory/SoldierFactory.cpp
        ./PersonHierarchy/Medic.cpp
        ./PersonHierarchy/Person.cpp
        ./PersonHierarchy/Soldier.cpp
        ./Phase/Phase.cpp
        ./Phase/Deter.cpp
        ./Phase/Dominate.cpp
        ./Phase/Seize.cpp
        ./WarTheater/Airspace.cpp
        ./WarTheater/Sea.cpp
        ./WarTheater/WarTheater.cpp
        ./WeaponHierarchy/Bazooka.cpp
        ./WeaponHierarchy/Cal45short.cpp
        ./WeaponHierarchy/Colt12B.cpp
        ./WeaponHierarchy/ExplosiveFactory.cpp
        ./WeaponHierarchy/ExplosiveProduct.cpp
        ./WeaponHierarchy/GasBomb.cpp
        ./WeaponHierarchy/M1Garand.cpp
        ./WeaponHierarchy/M1917Enfield.cpp
        ./WeaponHierarchy/PistolFactory.cpp
        ./WeaponHierarchy/PistolProduct.cpp
        ./WeaponHierarchy/RifleFactory.cpp
        ./WeaponHierarchy/RifleProduct.cpp
        ./WeaponHierarchy/Weapon.cpp
        ./WeaponHierarchy/WeaponFactory.cpp
        )


target_link_libraries(
        mainTester
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mainTester)
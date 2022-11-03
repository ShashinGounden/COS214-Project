OBJS = PersonHierarchy/Person.o PersonHierarchy/Soldier.o PersonHierarchy/Medic.o PersonHierarchy/PersonFactory/PersonFactory.o PersonHierarchy/PersonFactory/SoldierFactory.o PersonHierarchy/PersonFactory/MedicFactory.o ArmyHierarchy/Transport/Transport.o ArmyHierarchy/Transport/TransportBuilder.o ArmyHierarchy/Transport/TankMaker.o ArmyHierarchy/Transport/Tank.o ArmyHierarchy/Transport/ArmouredTruckMaker.o ArmyHierarchy/Transport/ArmouredTruck.o ArmyHierarchy/Transport/AircraftMaker.o ArmyHierarchy/Transport/Aircraft.o ArmyHierarchy/Iterator/ArmyIterator.o ArmyHierarchy/Iterator/AirUnitIterator.o ArmyHierarchy/Iterator/MedicUnitIterator.o ArmyHierarchy/Iterator/GroundUnitIterator.o ArmyHierarchy/Unit.o ArmyHierarchy/AirUnit.o ArmyHierarchy/GroundUnit.o ArmyHierarchy/MedicUnit.o WeaponHierarchy/WeaponFactory.o WeaponHierarchy/Weapon.o WeaponHierarchy/RifleProduct.o WeaponHierarchy/RifleFactory.o WeaponHierarchy/M1917Enfield.o WeaponHierarchy/M1Garand.o WeaponHierarchy/ExplosiveProduct.o WeaponHierarchy/ExplosiveFactory.o WeaponHierarchy/Bazooka.o WeaponHierarchy/GasBomb.o WeaponHierarchy/PistolProduct.o WeaponHierarchy/PistolFactory.o WeaponHierarchy/Cal45short.o WeaponHierarchy/Colt12B.o Country/WMD.o Country/Artillery.o Country/Nuke.o Phase/Phase.o Phase/Deter.o Phase/Dominate.o Phase/Seize.o WarTheater/Airspace.o WarTheater/Sea.o WarTheater/WarTheater.o Country/Alliance.o ArmyHierarchy/Army.o Country/Country.o main.o # Other object files go here
CXX = g++
CFLAGS = -g -Wall -std=c++17
TARGET = main

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run:
	./main

clean:
	rm -f $(TARGET) $(OBJS)
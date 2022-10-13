OBJS = PersonHierarchy/Person.o PersonHierarchy/Soldier.o PersonHierarchy/Civilian.o PersonHierarchy/Medic.o PersonHierarchy/PersonFactory/PersonFactory.o PersonHierarchy/PersonFactory/CivilianFactory.o PersonHierarchy/PersonFactory/SoldierFactory.o PersonHierarchy/PersonFactory/MedicFactory.o ArmyHierarchy/Iterator/ArmyIterator.o ArmyHierarchy/Iterator/AirUnitIterator.o ArmyHierarchy/Iterator/MedicUnitIterator.o ArmyHierarchy/Iterator/GroundUnitIterator.o ArmyHierarchy/Unit.o ArmyHierarchy/AirUnit.o ArmyHierarchy/GroundUnit.o ArmyHierarchy/MedicUnit.o ArmyHierarchy/Army.o Country/Country.o  main.o #Other object files go here
CXX = g++
CFLAGS = -g -Wall
TARGET = main

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run:
	./main

clean:
	rm -f $(TARGET) $(OBJS)
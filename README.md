# COS214-Project

## TO DO:

- Each need at least 10 commits
- Due dates and responsibilities, 4 October and 1 Nov
- Add Doxygen comments to code

DESIGN PATTERNS USED:

1. State
2. Observer
3. Builder
4. Prototype
5. Decorator
6. Strategy
7. Template Method
8. Factory Method
9. Abstract Factory Method
10. Iterator

MAIN REQUIREMENTS:

1. Components of war:

- War theatres
- Transportation
- Phases of war
- Changes to war engine
- More

2. Should have design mode (interactive) and real mode (simulation).

## DOXYGEN

What to document?

- Everything!

## Implementation

Soldiers - Medics - Pilots conversion (funds/10, funds/250, funds/500)

- for Attack() function

State will have a damage multiplier

Attack function can determine which unit attacks (ground or air) and returns that damage

returned damage will be minused from medics heal total to get netDamage
then delete an amount of soldiers from unit according to the netDamage

Fight returns an damage from weapon - int
Heal returns an int

can get rid of getHealth and takeDamage

For airUnit damage total amount - calculated from aircraft damage not attack
- Add Aircraft list - use Builder to make each Aircraft

funds can be used to add more troops after a attack has been made
can increase funds with an alliance getFunds or rand() function

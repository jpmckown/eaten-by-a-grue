MAPS
-
Maps are grid based. Only one entity can occupy a map tile at one time.

GAME LOOP
- 
The game loop operates on the player making one action per turn. Once an
action has been chosen by the player a turn is processed, moving all other 
entities in the world.

TIME
-
Each turn will equal about 10 minutes of time, meaning 6 moves equal an hour 
in the game world. Time is an important factor for all world entities.

FOOD
-
Food will be consumed and carry a calorie value, calories are used by the player
each turn, with a given action modifying the value.

DISTANCE
- 
Create distance that cause long travel time. The idea is to require provisions in order
to make a long journey.

BATTLE
-
1.) Resolving a hit
* Attacker chooses or is resolved by RNG what part of the target is going to be hit. ie Head, torso, leg, etc...
* When making an attack the attackers skill in weapon along with other attributes increase the change for making a hit
* A defender uses their defense attributes,i.e. evade, parry, block - This reduces the chance to hit
* Use RNG to resolve a successful hit - RNG + (attacker modifiers) > (defender modifiers) + BASE_DEFENSE_VALUE. If the hit fails then it ends there.

2.) Handle successful hit
* Armor negates damage. Heavier armor has more protection at a cost of weight.
* (attackers weapon damage) + (attacker modifiers) > (defenders armor value) + (defender modifiers) = successful wound
* Once a wound is made, the body part hit results in a RNG of what happens. A higher RNG results in a more devastating outcome 
A higher wound roll on a targets head would result in death. While a leg would be crippling or worse.

Note: There aren't really hitpoints. An entity losing critical parts is what results in killing something.
Battle is a focus of trying to score a hit and using the right weapon to penetrate the targets armor
An attacker needs to be mindful of scoring hits, while being able to have enough defense to negate injury

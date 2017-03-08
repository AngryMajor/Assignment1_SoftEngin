/*
this is a header file to contain all the types we define throughout the project
*/

typedef enum SlotTypes{FlatGround,Hill,City}SlotTypes;//defineing the slot types to integers for easyer use

typedef struct MapSlot {
	
	SlotTypes thisSlotType;//stors an int represening the slot type
	int PlayerHere;//stors the index from the player list of the player who is in this slot, 
	
} MapSlot;//end of map slot struct

struct players
{
	int type;
	char name[32];
	int life_points;
	int smartness;
	int strength;
	int magic_skills;
	int luck;
	int dexterity;
	int mapslot;//holds the index of the map slot this player is in
};

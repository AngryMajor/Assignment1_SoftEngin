/*
This is a header file to contain all the types we define throughout the project
*/

typedef enum SlotTypes{FlatGround,Hill,City}SlotTypes;  //Defining the slot types to integers for easier use

typedef struct MapSlot {
	
	SlotTypes thisSlotType;  //stores an integer representing the slot type
	int PlayerHere;  //Stores the index from the player list of the player who is in this slot, 
	
} MapSlot;  //End of map slot struct

struct player
{
	int type;
	char name[32];
	int life_points;
	int smartness;
	int strength;
	int magic_skills;
	int luck;
	int dexterity;
	int mapslot;  //Holds the index of the map slot this player is in
};

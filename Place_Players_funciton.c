
#include<stdio.h>


/*
taken from other file
*/
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

/*
taken from other file
*/

typedef struct MapSlot {
	
	SlotTypes thisSlotType;//stors an int represening the slot type
	int PlayerHere;//stors the index from the player list of the player who is in this slot, 
	
} MapSlot;//end of map slot struct

void PlacePlayer(struct player, int players size, struct MapSlot, int mapsize);
void EnterSlot(struct PlayerStruct *Player, int SlotType)

/*
Dummy main for testing
*/

int main(){
	srand
}//end of main

/*
places each player in a random index location in the map
takes the map and player arrays as well as ints of there sizes as input
returns nothing but changes the location variables in the map and the players
note srand must be called before running this function
*/
void PlacePlayer(struct player CurrPlayer[], int playersSize, struct MapSlot MapArray[], int MapSize){
	
	int SlotsTaken[playersSize] = {0};//holds the slots already taken between runs of the funciton
	
	//run through each player
	for(int i=0;i<playersSize;i++){
		//pic a slot
		static int slotChoise = rand()%MapSize;
		
		//chekc that that slot has not been taken
		for(int j = 0;j<i;j++){
			while(SlotsTaken[j] = )
		}//end of j loop
	}//end of i loop
	
}//end of place player

/*
dummy functions for testing only 
*/
void EnterSlot(struct PlayerStruct *Player, int SlotType){
	printf("EnterSlot");	
}

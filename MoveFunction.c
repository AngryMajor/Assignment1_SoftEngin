#include <stdio.h>

#define PlayerLocation (*Player).index

/*
Dummy Player strut for testing
*/

struct PlayerStruct{
	
	int index;
	
};//nd of player struct

typedef struct MapSlot {
	
	int SlotType;//stors an int represening the slot type, 0=flat ground, 1=hill, 2=city
	int PlayerHere;//stors the index from the player list of the player who is in this slot, 
	
}MapSlot;//end of map slot struct


void EnterSlot(struct PlayerStruct *Player, int SlotType);
void ExitSlot(struct PlayerStruct *Player, int SlotType);
void Move(struct PlayerStruct *Player, MapSlot MapSlots[], int EnterSlot, int ExitSlot);


int main(){
	
	int MapSize = 3;
	
	MapSlot MapSlots[MapSize];
	struct PlayerStruct Dummy;
	Dummy.index = 1;
	
	int MoveTo= 2;
	
	Move(&Dummy, MapSlots, MoveTo, Dummy.index);
}//end of main


void Move(struct PlayerStruct *Player, MapSlot MapSlots[], int enterSlot, int exitSlot){
	
	ExitSlot(Player, exitSlot);
	
	MapSlots[exitSlot].PlayerHere = PlayerLocation;
	PlayerLocation = enterSlot;
	MapSlots[enterSlot].PlayerHere = PlayerLocation;
	
	EnterSlot(Player, enterSlot);
	
	printf("%d",PlayerLocation);
	
}//end of move


void EnterSlot(struct PlayerStruct *Player, int SlotType){
	printf("EnterSlot");	
}


void ExitSlot(struct PlayerStruct *Player, int SlotType){
	printf("EixtSlot");
}



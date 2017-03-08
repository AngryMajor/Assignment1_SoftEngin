#include <stdio.h>
#include "OurTypes.h"

#define PlayerLocation (*Player).index




void EnterSlot(struct PlayerStruct *Player, int SlotType);
void ExitSlot(struct PlayerStruct *Player, int SlotType);
void Move(struct PlayerStruct *Player, MapSlot MapSlots[], int EnterSlot, int ExitSlot);


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



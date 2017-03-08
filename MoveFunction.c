#include "OurTypes.h"
#include "OurFunctions.h"

#define PlayerLocation (*Player).index

typedef struct MapSlot {
	
	int SlotType;  //Stores an integer representing the slot type, 0 = flat ground, 1 = hill, 2 = city
	int PlayerHere;  //Stores the index from the player list of the player who is in this slot, 
	
}MapSlot;  //End of map slot struct


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
}  //End of main


void Move(struct PlayerStruct *Player, MapSlot MapSlots[], int enterSlot, int exitSlot){
	
	ExitSlot(Player, exitSlot);
	
	MapSlots[exitSlot].PlayerHere = PlayerLocation;
	PlayerLocation = enterSlot;
	MapSlots[enterSlot].PlayerHere = PlayerLocation;
	
	EnterSlot(Player, enterSlot);
	
	printf("%d",PlayerLocation);
	
}  //End of move


void EnterSlot(struct PlayerStruct *Player, int SlotType){
	printf("EnterSlot");	
}


void ExitSlot(struct PlayerStruct *Player, int SlotType){
	printf("EixtSlot");
}



//Defines to make it easyer to change player struct
#define PlayerDex (*Player).dex
#define PlayerStr (*Player).str
#define PlayerSmar (*Player).smar
#define PlayerMag (*Player).mag 


/*
Makes aproprate changes to player stats when then enter a new slot
requires a pointer to the player struct and slot being entered 
modifies the player struct in acordence to the slot it is entering
*/

void EnterSlot(struct PlayerStruct *Player, int SlotType){
	
	
	
	switch(SlotType){
		case 0:  //If flat land
			break;
			
		case 1:  //If hill
			if(PlayerDex < 50) PlayerStr -=10;  
			else if(PlayerDex >= 60) PlayerStr +=10;
			break;
			
		case 2:  //If city
			if( PlayerSmar > 60) PlayerMag +=10;
			if( PlayerSmar <= 50) PlayerDex -=10;
			break;
		
		default:
			printf("invlad slotType on enter");
	}  //End of switch
	
	
}//end of enter slot


/*
reverts a players stats to what they were before entering the slot
requires a pointer to the player struct and slot being exited 
modifies the player struct in acordence to the slot it is entering
*/

void ExitSlot(struct PlayerStruct *Player, int SlotType){
	
	switch(SlotType){
		case 0://if flat land
			break;
			
		case 1://if hill
			if(PlayerDex < 50) PlayerStr +=10;  
			else if(PlayerDex >= 60) PlayerStr -=10;
			break;
			
		case 2://if city
			if( PlayerSmar > 60) PlayerMag -=10;
			if( PlayerSmar<= 50) PlayerDex +=10;
			break;
		
		default:
			printf("invlad slotType on exit");
	}//end of switch
	
}//end of exit slot

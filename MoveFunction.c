#include "OurFunctions.h"

void Move(struct player *Player, MapSlot MapSlots[], int enterSlot, int exitSlot){
	
	ExitSlot(Player, exitSlot);
	
	
	EnterSlot(Player, enterSlot);
	
}  //End of move

//Defines to make it easyer to change player struct
#define PlayerDex (*Player).dexterity
#define PlayerStr (*Player).strength
#define PlayerSmar (*Player).smartness
#define PlayerMag (*Player).magic_skills


/*
Makes aproprate changes to player stats when then enter a new slot
requires a pointer to the player struct and slot being entered 
modifies the player struct in acordence to the slot it is entering
*/

void EnterSlot(struct player *Player, int SlotType){
	
	
	
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

void ExitSlot(struct player *Player, int SlotType){
	
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

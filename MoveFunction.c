#include "OurFunctions.h"

/*
Calls ExitSlot then changes data of were the player and finaly calles enter slot
needs a player the map array and the directions Left is less, right is more
returns nothing
*/

int Move(struct player *Player,int PlayerIndex, MapSlot MapSlots[], int direction){
	
	if((MapSlots[((*Player).mapslot)+direction]).PlayerHere != -1){
		
		//if location is full
		printf("That Location is ocupied\n\n");
		return 1;//returning 1 says to main that this didnt work
		
	}//end of ocupied check
	
	
	ExitSlot(Player, (MapSlots[(*Player).mapslot]).thisSlotType);//change player stats for base
	
	//move player in the data
	(*Player).mapslot += direction;
	(MapSlots[((*Player).mapslot) - direction]).PlayerHere = -1;
	(MapSlots[(*Player).mapslot]).PlayerHere = PlayerIndex;
	
	EnterSlot(Player, (MapSlots[(*Player).mapslot]).thisSlotType);//change player stats to location modified
	
	return 0;//move exicuted fine
	
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
			printf("Invalid slotType on enter\n");
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
			printf("Invalid slotType on exit\n");
	}//end of switch
	
}//end of exit slot

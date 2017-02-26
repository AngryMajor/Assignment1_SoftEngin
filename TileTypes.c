#include <stdio.h>

//defines so i dont have to go through everything to adjuct for a difrent player struct
#define PlayerDex (*Player).dex
#define PlayerStr (*Player).str
#define PlayerSmar (*Player).smar
#define PlayerMag (*Player).mag 

/*
dumy player struct
*/
struct PlayerStruct{
	int dex;
	int str;
	int smar;
	int mag;
};

void EnterSlot(struct PlayerStruct *Player, int SlotType);
void ExitSlot(struct PlayerStruct *Player, int SlotType);
void Move(struct PlayerStruct *Player, int EnterSlot, int ExitSlot);


/*
disposable main for testing
*/
int main(){
	
	int enterSlot;
	int exitSlot;
	
	struct PlayerStruct Dummy;
	Dummy.dex = 40;
	Dummy.str = 10;
	Dummy.smar = 40;
	Dummy.mag = 10;
	
	scanf("%d", &enterSlot);
	scanf("%d", &exitSlot);
	
	Move(&Dummy, enterSlot, exitSlot);
	
}//end of main

///////////////////////////////////
//actual functions for use
/////////////////////////////////////////////////////


/*
makes aproprate changes to player stats when then enter a new slot
requires a pointer to the player struct and slot being entered 
modifies the player struct in acordence to the slot it is entering
*/

void EnterSlot(struct PlayerStruct *Player, int SlotType){
	
  //switch to see what slot type the palyer is entering
	switch(SlotType){
		case 0:
			break;
			
		case 1:
			if(PlayerDex < 50) PlayerStr -=10;  
			else if(PlayerDex >= 60) PlayerStr +=10;
			break;
			
		case 2:
			if( PlayerSmar > 60) PlayerMag +=10;
			if( PlayerSmar <= 50) PlayerDex -=10;
			break;
		
		default:
			printf("invlad slotType on enter");
	}//end of switch
	
}//end of enter slot


/*
reverts a players stats to what they were before entering the slot
requires a pointer to the player struct and slot being exited 
modifies the player struct in acordence to the slot it is entering
*/

void ExitSlot(struct PlayerStruct *Player, int SlotType){
	
  //switch to check what slot type the player is leaving
	switch(SlotType){
		case 0:
			break;
			
		case 1:
			if(PlayerDex < 50) PlayerStr +=10;  
			else if(PlayerDex >= 60) PlayerStr -=10;
			break;
			
		case 2:
			if( PlayerSmar > 60) PlayerMag -=10;
			if( PlayerSmar<= 50) PlayerDex +=10;
			break;
		
		default:
			printf("invlad slotType on exit");
	}//end of switch
	
}//end of exit slot


/*
simply calls ExitSlot, moves the character then Calles enterslot on the character
*/
void Move(struct PlayerStruct *Player, int enterSlot, int exitSlot){
	
		ExitSlot(&Player, exitSlot);
		
		EnterSlot(&Player, enterSlot);
	
}//end of move

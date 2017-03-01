#include <stdio.h>

//defines to make it easyer to change player struct
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
	
	printf("%d %d %d %d\n",Dummy.dex, Dummy.str,Dummy.smar, Dummy.mag);
	
	scanf("%d", &enterSlot);
	scanf("%d", &exitSlot);
	
	EnterSlot(&Dummy, enterSlot);
	
	printf("%d %d %d %d\n",Dummy.dex, Dummy.str,Dummy.smar, Dummy.mag);
	
	ExitSlot(&Dummy, exitSlot);
	
	
	printf("%d %d %d %d\n",Dummy.dex, Dummy.str,Dummy.smar, Dummy.mag);
	
	//Move(&Dummy, enterSlot, exitSlot);
	
	
}//end of main



/*
makes aproprate changes to player stats when then enter a new slot
requires a pointer to the player struct and slot being entered 
modifies the player struct in acordence to the slot it is entering
*/

void EnterSlot(struct PlayerStruct *Player, int SlotType){
	
	
	
	switch(SlotType){
		case 0://if flat land
			break;
			
		case 1://if hill
			if(PlayerDex < 50) PlayerStr -=10;  
			else if(PlayerDex >= 60) PlayerStr +=10;
			break;
			
		case 2://if city
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



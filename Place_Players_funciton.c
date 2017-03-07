#include<stdio.h>
#include<stdlib.h>
#include<time.h>


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

typedef enum SlotTypes{FlatGround,Hill,City}SlotTypes;//defineing the slot types to integers for easyer use

typedef struct MapSlot {
	
	SlotTypes thisSlotType;//stors an int represening the slot type
	int PlayerHere;//stors the index from the player list of the player who is in this slot, 
	
} MapSlot;//end of map slot struct

void PlacePlayer(struct players Players[], int playersSize, struct MapSlot MapArray[], int mapsize);
void EnterSlot(struct players *Player, int SlotType);

/*
Dummy main for testing
*/

int main(){
	srand(time(NULL));
	
	struct players Players[2];
	
	MapSlot Map[3];
	Map[0].PlayerHere = -1;
	Map[1].PlayerHere = -1;
	Map[2].PlayerHere = -1;

	PlacePlayer(Players,2,Map,3);
	
	for(int i=0;i<2;i++) printf("%d  %d\n",i,Players[i].mapslot);
	
	
}//end of main

/*
places each player in a random index location in the map
takes the map and player arrays as well as ints of there sizes as input
returns nothing but changes the location variables in the map and the players
note srand must be called before running this function and all map slots must have their player here set to -1 inishaly
also check that there are not more players then slots
*/
void PlacePlayer(struct players Players[], int playersSize, struct MapSlot MapArray[], int MapSize){
	
	int playerNum=0;
	int PlayerPlace;
		
	while(playerNum<playersSize){
		
		//clear player place data
		Players[playerNum].mapslot = -1;
		
		//store posable locatoin for player to be put
		PlayerPlace = rand()%MapSize;
		
		//check if that location has a player in it, if not then put the player there
		while(Players[playerNum].mapslot == -1){
			
			if(MapArray[PlayerPlace].PlayerHere  == -1){
				
				MapArray[PlayerPlace].PlayerHere = playerNum;
				Players[playerNum].mapslot = PlayerPlace;
				playerNum++;
			}else{
				PlayerPlace = ((PlayerPlace+1)%3);}
		}//end of while
		
		EnterSlot(&Players[playerNum],PlayerPlace);
		
	}//end of i loop
}//end of place player

/*
dummy functions for testing only 
*/
void EnterSlot(struct players *Player, int SlotType){
	printf("EnterSlot");	
}

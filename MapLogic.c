#include "OurFunctions.h"


/*
Places each player in a random index location in the map
takes the map and player arrays as well as ints of there sizes as input
returns nothing but changes the location variables in the map and the players
note srand must be called before running this function and all map slots must have their player here set to -1 inishaly
also check that there are not more players then slots
*/
void PlacePlayer(struct player Players[], int playersSize, struct MapSlot MapArray[], int MapSize){
	
	int playerNum=0;
	int PlayerPlace;
		
	while(playerNum<playersSize){
		
		//Clear player place data
		Players[playerNum].mapslot = -1;
		
		//Store posable locatoin for player to be put
		PlayerPlace = rand()%MapSize;
		
		//Check if that location has a player in it, if not then put the player there
		while(Players[playerNum].mapslot == -1){
			
			if(MapArray[PlayerPlace].PlayerHere  == -1){
				
				MapArray[PlayerPlace].PlayerHere = playerNum;
				Players[playerNum].mapslot = PlayerPlace;
				playerNum++;
			}else{
				PlayerPlace = ((PlayerPlace+1)%MapSize);}
		}  //End of while
		
		EnterSlot(&Players[playerNum],(MapArray[(Players[playerNum]).mapslot]).thisSlotType);
		
	}  //End of i loop
}  //End of place player



void PrintMapSlotType(MapSlot toPrint){
	
	char *SlotNames[] = {"Flat Ground","Hill","City"};
	
	printf("%s",SlotNames[toPrint.thisSlotType]);
	
}  //End of printmapslot


MapSlot CreatMapSlot(){
	MapSlot Curr;
	
	Curr.thisSlotType = rand()%3;
	Curr.PlayerHere = -1;
	
	return Curr;
}  //End of creat map slot

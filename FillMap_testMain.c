#include "OurFunctions.h"

#define NumOfSlotTypes 3

/*
Fills an array of type mapslot with random types assigned 
requires stdlib.h and time.h and srand to have been called
FillMapArray(array of all map slots, size of the array)
returns nothing
*/

void FillMapArray(MapSlot MapSlots[], int MapSize){

	for(int i=0;i<MapSize;i++){
		MapSlots[i].thisSlotType = rand()%NumOfSlotTypes;
		MapSlots[i].PlayerHere = -1;  //Setting all the values storying player locations to -1 or empty to be filled later
	}  //End of for loop
	
}  //End of fill map array


void PrintMapSlotChar(MapSlot toPrint){
	
	char *SlotNames[] = {"Flat Ground","Hill","City"};
	
	printf("%s\n",SlotNames[toPrint.thisSlotType]);
	if(toPrint.PlayerHere != -1) printf(   "%d\n",toPrint.PlayerHere);
	puts("");
}  //End of printmapslot

void PrintPlayerStats(struct player Player){
	
	printf("type:  %d\nname:  %d\nlife points: %d\nsmartness:  %d\nstrength:  %d\nmagic skills:  %d\nluck:  %d\ndexterity:  %d\n",Player.type, Player.name, Player.life_points, Player.smartness, Player.strength, Player.magic_skills, Player.luck, Player.dexterity);
	
}//end of print player stats

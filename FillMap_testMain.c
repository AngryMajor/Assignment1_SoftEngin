/*
contains the MapSlot struc and the function to fill the MapSlot array and a defenition for number of slot types
also headers and main eclusivly for testing perposes
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NumOfSlotTypes 3


typedef struct MapSlot {
	
	int SlotType;//stors an int represening the slot type, 0=flat ground, 1=hill, 2=city
	int PlayerHere;//stors the index from the player list of the player who is in this slot, 
	
} MapSlot;//end of map slot struct


void FillMapArray(MapSlot MapSlots[], int MapSize);

/*
disposable main function
*/
int main(void){
	
	int MapSize = 3;
	
	MapSlot MapSlots[MapSize];
	
	srand(time(NULL));

	FillMapArray(MapSlots, MapSize);
	
	for(int i=0;i<sizeof(MapSlots)/sizeof(MapSlot);i++) printf("%d ",MapSlots[i].SlotType);
}//end of main




/*
Fills an array of type mapslot with random types assined 
requires stdlib.h and time.h and srand to have been called
FillMapArray(array of all map slots, size of the array)
returns nothing
*/

void FillMapArray(MapSlot MapSlots[], int MapSize){

	for(int i=0;i<MapSize;i++){
		MapSlots[i].SlotType = rand()%NumOfSlotTypes;
		MapSlots[i].PlayerHere = -1;//setting all the values storying player locations to -1 or empty to be filled later
	}//end of for loop
	
}//end of fill map array

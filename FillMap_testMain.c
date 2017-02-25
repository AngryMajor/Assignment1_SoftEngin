#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct MapSlot {
	
	int SlotType;//stors a single character representing the type, G is for level ground, H is for hill, C is for city
	int PlayerHere;//stors the index from the player list of the player who is in this slot, 
	
} MapSlot;//end of map slot struct


void FillMapArray(MapSlot MapSlots[], int MapSize);


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
		MapSlots[i].SlotType = rand()%3;
		MapSlots[i].PlayerHere = -1;//setting all the values storying player locations to -1 or empty to be filled later
	}//end of for loop
	
}//end of fill map array

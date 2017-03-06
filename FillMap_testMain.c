#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NumOfSlotTypes 3//

typedef enum SlotTypes{FlatGround,Hill,City}SlotTypes;//defineing the slot types to integers for easyer use

typedef struct MapSlot {
	
	SlotTypes thisSlotType;//stors an int represening the slot type
	int PlayerHere;//stors the index from the player list of the player who is in this slot, 
	
} MapSlot;//end of map slot struct


void FillMapArray(MapSlot MapSlots[], int MapSize);
void PrintMapSlot(MapSlot toPrint);

/*
disposable main function
*/
int main(void){
	
	int MapSize = 3;
	
	MapSlot MapSlots[MapSize];
	
	srand(time(NULL));

	FillMapArray(MapSlots, MapSize);
	
	for(int i=0;i<sizeof(MapSlots)/sizeof(MapSlot);i++) PrintMapSlot(MapSlots[i]);
}//end of main




/*
Fills an array of type mapslot with random types assined 
requires stdlib.h and time.h and srand to have been called
FillMapArray(array of all map slots, size of the array)
returns nothing
*/

void FillMapArray(MapSlot MapSlots[], int MapSize){

	for(int i=0;i<MapSize;i++){
		MapSlots[i].thisSlotType = rand()%NumOfSlotTypes;
		MapSlots[i].PlayerHere = -1;//setting all the values storying player locations to -1 or empty to be filled later
	}//end of for loop
	
}//end of fill map array


void PrintMapSlot(MapSlot toPrint){
	
	char *SlotNames[] = {"Flat Ground","Hill","City"};
	
	printf("%s",SlotNames[toPrint.thisSlotType]);
	if(toPrint.PlayerHere !=) printf(   "%d",toPrint.PlayerHere);
	put("");
}//end of printmapslot

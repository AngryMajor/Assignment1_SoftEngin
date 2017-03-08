#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"OurTypes.h"


MapSlot CreatMapSlot();
void PrintMapSlot(MapSlot toPrint);

/*
simple function that creates a map slot to be stored
takes no arguments and returns a map slot
*/

MapSlot CreatMapSlot(){
	MapSlot Curr;
	
	Curr.thisSlotType = rand()%3;
	Curr.PlayerHere = -1;
	
	return Curr;
}//end of creat map slot


void PrintMapSlot(MapSlot toPrint){
	
	char *SlotNames[] = {"Flat Ground","Hill","City"};
	
	printf("%s",SlotNames[toPrint.thisSlotType]);
	if(toPrint.PlayerHere !=) printf(   "%d",toPrint.PlayerHere);
	put("");
}//end of printmapslot

#include "OurFunctions.h"

void PrintPlayer(struct player CurrPlayer){
	
	//Change the player type from the working int into a printable string
	char CurrPlayerType[7];	
	switch (CurrPlayer.type){
		case 1:
			strcpy(CurrPlayerType,"Elf");
			break;
		case 2:
			strcpy(CurrPlayerType,"Human");
			break;
		case 3:
			strcpy(CurrPlayerType,"Ogre");
			break;
		case 4:
			strcpy(CurrPlayerType,"Wizard");
			break;
		default:
			printf("error:player type value undefined %d",CurrPlayer.type);
	}  //End of switch
	
	printf("%s (%s, %d)\n",CurrPlayer.name,CurrPlayerType,CurrPlayer.life_points);  //Print the relevent player stats with new line
	
}  //End of print player

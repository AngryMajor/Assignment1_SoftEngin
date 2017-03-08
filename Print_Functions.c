#include<stdio.h>
#include<string.h>
#include"OurTypes.h"



void PrintPlayer(struct player CurrPlayer);

/*
prints a players relevent stats for the end of the game
takes a player sturct as input and returns nothing
changes no values, just prints the stats
*/

void PrintPlayer(struct player CurrPlayer){
	
	//change the player type from the working int into a printable string
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
	}//end of switch
	
	printf("%s (%s, %d)\n",CurrPlayer.name,CurrPlayerType,CurrPlayer.life_points);//print the relevent player stats with new line
	
}//end of print player

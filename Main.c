#include "OurFunctions.h"
#include "OurTypes.h"

int main(void)
{

	//creat player array
	int PlayerNum;
	printf("Please input how many players are playing the game: \n");
	scanf("%d", &PlayerNum);
	struct player player[PlayerNum];

	//fill player array
	for(int i = 0; i < PlayerNum; i++)
	{
		player[i] = type();
	}

	//creat map array
	int MapSize;
	printf("Please input how many slots are in the map: \n");
	scanf("%d", &MapSize);
	MapSlot Map[MapSize];

	//fill map array
	for(int i = 0; i < MapSize; i++)
	{
		Map[i] = CreatMapSlot();
	}

	//for(int i=0;i<PlayerNum;i++){
		PlacePlayer(player, PlayerNum, Map, MapSize);
	//}//end of place players loop

	for(int i=0;i<MapSize;i++) printf("%s %d\n",PrintMapSlotType(Map[i]),Map[i].PlayerHere);

	int choise;
	int Failed;
	for(int i=0;i<PlayerNum;i++){
		printf("It is Player %d's turn. Would you like to\n1. Move or 2. Attack the closest player\n",i+1);
		scanf("%d",&choise);

		if(choise == 1){
			int direction;
				
				printf("Which direction would you like to move? 0 for down, 1 for up");
				scanf("%d",&direction);
				
				switch(direction){
					case 0:
						Failed = Move(&player[i],i,Map,-1);
						break;
					case 1:
						Failed= Move(&player[i],i,Map,1);
						break;
					default:
						Failed = 1;
						printf("Invalid direction, please try again\n");
						break;
				}//end of up down switch
		}else{
			find_players(player, i, Map, MapSize);
			//attack
		}//choise if
	}//end of looping through players

	for(int i=0;i<PlayerNum;i++){
		PrintPlayer(player[i]);
	}//end of print players
 
}//end of main

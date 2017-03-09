#include "OurFunctions.h"
#include "OurTypes.h"

int main(void)
{

	//creat player array
	int PlayerNum;
	printf("Please input how many players are playing the game: ");
	scanf("%d", &PlayerNum);
	struct player player[PlayerNum];

	//fill player array
	for(int i = 0; i < PlayerNum; i++)
	{
		player[i] = type();
	}

	//creat map array
	int MapSize;
	printf("Please input how many slots are in the map: ");
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

	//print map
	for(int i=0;i<MapSize;i++){
		PrintMapSlotType(Map[i]);
		printf("  %d",Map[i].PlayerHere);
		puts("");
	}

	int choise;
	int Failed;
	for(int i=0;i<PlayerNum;i++){
		printf("Player %d's turn, would you like to\n1:Move 2:Attack closest player",i+1);
		scanf("%d",&choise);

		if(choise == 1){
			int direction;
				
				printf("Please input which direction you would like to move, 0 for down, 1 for up");
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
						printf("invalid direction, please try again\n");
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

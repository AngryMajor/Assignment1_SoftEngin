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

	for(int i=0;i<PlayerNum;i++){
		//place players
	}//end of place players loop


	int choise;
	for(int i=0;i<PlayerNum;i++){
		printf("");
		scanf("",choise);

		if(choise == 1){
			//move
		}else{
			//attack
		}//choise if
	}//end of looping through players

	for(int i=0;i<PlayerNum;i++){
		PrintPlayer(player[i]);
	}//end of print players
 
}//end of main

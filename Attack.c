#include "OurFunctions.h"

void attack(struct player *AttackerPlayer, struct player *AttackedPlayer)
{
	if(AttackedPlayer->strength <=70)
	{
		AttackedPlayer->life_points = AttackedPlayer->life_points - (0.5 * AttackedPlayer->strength);
		printf("1. Attacked Player Life points = %d\n", AttackedPlayer->life_points);
	}
	
	else if(AttackedPlayer->strength > 70)
	{
		AttackerPlayer->life_points = AttackerPlayer->life_points - (0.3 * AttackedPlayer->strength);
		printf("2. Attcker Player Life Points = %d\n", AttackerPlayer->life_points);
	}
	
}

int find_players(struct player player[], int i, MapSlot map[], int MapSize)
{
	int a = player->mapslot;
	int b;
	int x;
	int y;
	int decision;
	
	for(int j = 1; j < MapSize; j++)
	{
	if(a - j < 0)
	{
		x = 0;
	}
	else
	{
		x = a - j;
	}
	if(a + j > MapSize)
	{
		y = MapSize;
	}
	else
	{
		y = a + j;
	}
	if (map[x].PlayerHere != -1)
	{
		b = map[x].PlayerHere;	
	}
	if(map[x].PlayerHere != -1)
	{
		b = map[y].PlayerHere;
	}
	
	if(map[x].PlayerHere != -1 && map[y].PlayerHere != -1)
		{
		do{
			
			printf("Which player do you want to attack? 1 = up, 2 = down: ");
			scanf("%d", &decision);
			switch(decision)
			{
				case 1:
				b = map[x].PlayerHere;
				break;
				case 2:
				b = map[y].PlayerHere;
				break;
				default:
				printf("Not a valid option.\n");
				
			}
		}	while(decision >2 || decision <1);
		}
	}
		attack(&player[i], &player[b]);
}

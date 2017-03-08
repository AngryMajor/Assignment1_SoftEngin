/* This is a header file to contain all the functions we defined throughout the project */

#ifndef _OURFUNCTIONSH_
#define _OURFUNCTIONSH_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "OurTypes.h"

void elf(struct player *Current_Player);  //Function prototype
void human(struct player *Current_Player);   //Function prototype
void ogre(struct player *Current_Player);   //Function prototype
void wizard(struct player *Current_Player);   //Function prototype 
void type();  //Function prototype

void EnterSlot(struct player *Player, int SlotType);   //Function prototype
void ExitSlot(struct player *Player, int SlotType);   //Function prototype
void Move(struct player *Player, int EnterSlot, int ExitSlot);   //Function prototype

void PlacePlayer(struct player Player[], int playersSize, struct MapSlot MapArray[], int mapsize);  //Function prototype

void PrintPlayer(struct player CurrPlayer);  //Function prototype

void attack(struct player *AttackerPlayer, struct player *AttackedPlayer);

#endif

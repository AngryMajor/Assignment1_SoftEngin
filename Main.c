include<stdio.h>
include"OurTypes.h"
// creat header for func prototypes
  
void elf(struct player *Current_Player);  //Function prototype
void human(struct player *Current_Player);   //Function prototype
void ogre(struct player *Current_Player);   //Function prototype
void wizard(struct player *Current_Player);   //Function prototype 
void type();

int main()
{
int choice;
printf("Please input how many players are playing the game: ");
scanf("%d", &choice);
struct player player[choice];
 for(int i = 0; i < choice; i++)
 {
   type();
   //returns a player witch we stor in an array
 }
  
  //same thing for map slots
  
  for(number of players){
  //creat menue for turns
  }
    
}//end of main

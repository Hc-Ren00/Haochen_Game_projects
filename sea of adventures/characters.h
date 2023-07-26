#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Struct called Character
struct Character
{
   char* name; //name of the character
   char* description; //description of the character
   struct Room* room; //room with the character
   struct Item* items; //items that the character has
};

//Create a pointer to a new character
//   param name: name of the character
//   param description: description of the character
//   param room: room with the character
//   param fitem: linkedlist of character's items
//   return: pointer to a new character
struct Character* character(char* name, char* description, struct Room* room, struct Item* fitem);

//Move the character to another room
//   param character: the character you want to move
//   param room: the room you want to move to
void move_character(struct Character* character, struct Room* room);

//Get the items of character
//   param character: a certain character you want to know
//   return: character's first item
struct Item* get_item(struct Character* character);

//Add a new item to character
//   param character: character you want to add to
//   param item: item you want to add
void character_get_item(struct Character* character, struct Item* item);

//Drop an item for a character
//   param character: a character you want to drop item from
//   param item: the item you want to drop
void character_drop_item(struct Character* character, struct Item* item);


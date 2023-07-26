#include "characters.h"
#include "items.h"
#include "rooms.h"

//Create a pointer to a new character
//   param name: name of the character
//   param description: description of the character
//   param room: room with the character
//   param fitem: linkedlist of character's items
//   return: pointer to a new character
struct Character* character(char* name, char* description, struct Room* room, struct Item* fitem)
{
   struct Character* new_char = (struct Character*)malloc(sizeof(struct Character));
   new_char -> name = name;
   new_char -> description = description;
   new_char -> room = room;
   new_char -> items = fitem;
   return new_char;
}

//Move the character to another room
//   param character: the character you want to move
//   param room: the room you want to move to
void move_character(struct Character* character, struct Room* room)
{
   character -> room = room;
}

//Get the items of character
//   param character: a certain character you want to know
//   return: character's first item
struct Item* get_item(struct Character* character)
{
   struct Item* it = character -> items;
   return it;
}

//Add a new item to character
//   param character: character you want to add to
//   param item: item you want to add
void character_get_item(struct Character* character, struct Item* item)
{
   if(character -> items == NULL)
   {
      character -> items = item;
   }
   else
   {
      struct Item* node = character -> items;
      while(node -> next != NULL)
      {
         node = node -> next;
      }
      node -> next = item;
   }
}

//Drop an item for a character
//   param character: a character you want to drop item from
//   param item: the item you want to drop
void character_drop_item(struct Character* character, struct Item* item)
{
   struct Item* node = item_take(item -> name, character -> items);
   if(node == NULL)
   {
      printf("%s\n", "You currently don't have this in your inventory.");
   }
   else if(strcmp(node -> name, character -> items -> name) == 0)
   {
      character -> items = character -> items -> next;
   } 
}




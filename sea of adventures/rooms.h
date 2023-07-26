#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//A struct called Room
struct Room
{
   char* name; //name of the room
   char* description; //description of the room
   struct Item* items; //items in the room
   struct Room* north; //north room
   struct Room* south; //south room
   struct Room* east; //east room
   struct Room* west; //west room
};

//This function creates a pointer to a new room
//   param name: name of the room
//   param description: description of the room
//   param items: items in the room
//   param north: north room
//   param south: south room
//   param east: east room
//   param west: west room
//   return: pointer to a new room
struct Room* room(char* name,
                  char* description, struct Item* items,
                  struct Room* north, struct Room* south,
                  struct Room* east, struct Room* west);

//Get name of the room
//   param room: current room
//   return: name of the room
char* get_name(struct Room* toom);

//Set north room of current room
//   param current: current room
//   param other: the room you want to set
void room_exit_north(struct Room* current, struct Room* other);

//Set south room of current room
//   param current: current room
//   param other: the room you want to set
void room_exit_south(struct Room* current, struct Room* other);

//Set east room of current room
//   param current: current room
//   param other: the room you want to set
void room_exit_east(struct Room* current, struct Room* other);

//Set west room of current room
//   param current: current room
//   param other: the room you want to set
void room_exit_west(struct Room* current, struct Room* other);



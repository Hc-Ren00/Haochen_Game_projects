#include "rooms.h"
#include "items.h"

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
                  struct Room* east, struct Room* west)
{
   struct Room* new_room = (struct Room*) malloc(sizeof(struct Room));
   new_room -> name = name;
   new_room -> description = description;
   new_room -> items = items;
   new_room -> north = north;
   new_room -> south = south;
   new_room -> east = east;
   new_room -> west = west;
   return new_room;
}

//Get name of the room
//   param room: current room
//   return: name of the room
char* get_name(struct Room* room)
{
   return room -> name;
}

//Set north room of current room
//   param current: current room
//   param other: the room you want to set
void room_exit_north(struct Room* current, struct Room* other)
{
   current -> north = other;
}

//Set south room of current room
//   param current: current room
//   param other: the room you want to set
void room_exit_south(struct Room* current, struct Room* other)
{
   current -> south = other;
}

//Set east room of current room
//   param current: current room
//   param other: the room you want to set
void room_exit_east(struct Room* current, struct Room* other)
{
   current -> east = other;
}

//Set west room of current room
//   param current: current room
//   param other: the room you want to set
void room_exit_west(struct Room* current, struct Room* other)
{
   current -> west = other;
}

 

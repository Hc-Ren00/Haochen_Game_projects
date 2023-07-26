#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//A struct called Item
struct Item
{
   char* name; //name of the Item
   char* description; //description of the Item
   struct Item* next; //next Item
};

//Create a pointer to a new Item struct
//   param name: name of item
//   param description: description of item
//   param next: link to next item
//   return: pointer to a new Item struct
struct Item* item(char name[], char* description, struct Item* next);

//Get the name of a item
//   param item: an item
//   return: name of the item
char* item_name(struct Item* item);

//Get the description of an item
//   param item: an item
//   return: description of the item
char* item_description(struct Item* item);

//Get next item
//   param item: an item
//   return: next item
struct Item* item_next(struct Item* item);

//Remove an item named name in the linklist started from itemhead
//   param name: the name you search for
//   itemhead: head of the linkedlist
//   return: node with the name you searched for if success, NULL otherwise
struct Item* item_take(char* name, struct Item* itemhead);

//Add a new item to a linkedlist
//   param fitem: head of the linkedlist
//   param new_item: the item you want to add
void add_item(struct Item* fitem, struct Item* new_item);

//Remove an item from the linkedlist
//   param fitem: head of the linkedlist
//   param drop: the item that you want to remove
void drop_item(struct Item* fitem, struct Item* drop);


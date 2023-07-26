#include "items.h"
#include "rooms.h"
#include "characters.h"
#include <string.h>

//Create a pointer to a new Item struct
//   param name: name of item
//   param description: description of item
//   param next: link to next item
//   return: pointer to a new Item struct
struct Item* item(char* name, char* description, struct Item* next)
{
   struct Item* it = (struct Item*) malloc(sizeof(struct Item));
   it -> name = name;
   it -> description = description;
   it -> next = next;
   return it;
}

//Get the name of a item
//   param item: an item
//   return: name of the item
char* item_name(struct Item* item)
{
   char* name = item -> name;
   return name;
}

//Get the description of an item
//   param item: an item
//   return: description of the item
char* item_description(struct Item* item)
{
   char* description = item -> description;
   return description;
}

//Get next item
//   param item: an item
//   return: next item
struct Item* item_next(struct Item* item)
{
   struct Item* next = item -> next;
   return next;
}

//Remove an item named name in the linklist started from itemhead
//   param name: the name you search for
//   itemhead: head of the linkedlist
//   return: node with the name you searched for if success, NULL otherwise
struct Item* item_take(char* name, struct Item* itemhead)
{
   struct Item* head = item("dummy", "fake head", itemhead);
   if(itemhead == NULL)
   {
      return NULL;
   }
   struct Item* node = itemhead;
   while(head -> next != NULL)
   {
      if(strcmp(itemhead -> name, name) == 0)
      {
         return itemhead;
      }
      else if(strcmp(name, node -> name)== 0)
      {
         head -> next = node -> next;
         break;
      }
      else
      {
         node = node -> next;
         head = head -> next;
      }
   }
   return node;
}

//Add a new item to a linkedlist
//   param fitem: head of the linkedlist
//   param new_item: the item you want to add
void add_item(struct Item* fitem, struct Item* new_item)
{
   if(fitem == NULL)
   {
      fitem = new_item;
      printf("%s\n", fitem -> name);
   }
   else
   {
      struct Item* node = fitem;
      while(node -> next != NULL)
      {
         node = node -> next;
      }
      node -> next = new_item;
   }
}

//Remove an item from the linkedlist
//   param fitem: head of the linkedlist
//   param drop: the item that you want to remove
void drop_item(struct Item* fitem, struct Item* drop)
{
   item_take(drop -> name, fitem);
}


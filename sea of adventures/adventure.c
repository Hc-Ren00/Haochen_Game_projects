#include "rooms.h"
#include "items.h"
#include "characters.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//reset the game status, randomly initialize the game board
//   param rooms[]: arraylist to store the rooms after randomly initialization
//   param list_room[]: arraylist to store the rooms before randomly initialization
//   param list_items[]: arraylist to store all the items
//   param characters[]: arraylist to store all the characters
void reset(struct Room* rooms[], struct Room* list_room[], struct Item* list_items[], struct Character* characters[])
{
   int j;
   for(int i = 0; i < 9; i++) //Radomly initialize room status
   {
      srand(time(0));
      j = rand() % 9;
      while(rooms[j] != NULL)
      {
         srand(time(0));
         j = rand() % 9;
      }
      rooms[j] = list_room[i]; 
   }
   
   room_exit_east(rooms[0], rooms[1]);
   room_exit_south(rooms[0], rooms[3]);
   room_exit_east(rooms[1], rooms[2]);
   room_exit_south(rooms[1], rooms[4]);
   room_exit_west(rooms[1], rooms[0]);
   room_exit_south(rooms[2], rooms[5]);
   room_exit_west(rooms[2], rooms[1]);
   room_exit_north(rooms[3], rooms[0]);
   room_exit_east(rooms[3], rooms[4]);
   room_exit_south(rooms[3], rooms[6]);
   room_exit_north(rooms[4], rooms[1]);
   room_exit_east(rooms[4], rooms[5]);
   room_exit_south(rooms[4], rooms[7]);
   room_exit_west(rooms[4], rooms[3]);
   room_exit_north(rooms[5], rooms[2]);
   room_exit_south(rooms[5], rooms[8]);
   room_exit_west(rooms[5], rooms[4]);
   room_exit_north(rooms[6], rooms[3]);
   room_exit_east(rooms[6], rooms[7]);
   room_exit_north(rooms[7], rooms[4]);
   room_exit_east(rooms[7], rooms[8]);
   room_exit_west(rooms[7], rooms[6]);
   room_exit_north(rooms[8], rooms[5]);
   room_exit_west(rooms[8], rooms[7]);
   int i;
   srand(time(0));
   for(int j = 0; j < 6; j++) //Randomly initialize the position of all characters
   {
      i = rand() % 9;
      move_character(characters[j], rooms[i]);
   }
   for(int k = 0; k < 6; k++) //Randomly initialize the position of all items
   {
      i = rand() % 9;
      while(rooms[i] -> items != NULL)
      {
         i = rand() % 9;
      }
      rooms[i] -> items = list_items[k];
   }
   
}

//Compare the user input with each command and behave as expected
//   param command[]: user input
//   param characters[]: the arraylist of characters
//   param rooms[]: the arraylist of rooms
//   param list_items[]: the arraylist of items
//   return: 2 if user input equal to any of the command other than clue commands, 1 otherwise 
int Command(char command[], struct Character* characters[], struct Room* rooms[], struct Item* list_items[])
{
   char help[] = "help";
   char list[] = "list";
   char look[] = "look";
   char gn[] = "go north";
   char gs[] = "go south";
   char gw[] = "go west";
   char ge[] = "go east";
   char tgt[] = "take golden tooth";
   char tnmos[] = "take necklace made of stone";
   char tmt[] = "take monocular telescope";
   char tgr[] = "take golden ring";
   char tc[] = "take compass";
   char td[] = "take diary";
   char dgt[] = "drop golden tooth";
   char dnmos[] = "drop necklace made of stone";
   char dmt[] = "drop monocular telescope";
   char dgr[] = "drop golden ring";
   char dc[] = "drop compass";
   char dd[] = "drop diary";
   char inventory[] = "inventory";

   
   if(strcmp(command, help) == 0) //compare with help command
   {
      printf("%14s ----- %s\n", "help", "lookup the command in the table");
      printf("%14s ----- %s\n", "list", "lookup the list of items, rooms, and characters");
      printf("%14s ----- %s\n", "look", "see the rooms in each direction, the characters in the room, and the items in the room");
      printf("%14s ----- %s\n", "go DIRECTION", "move your avatar through each room using this command where DIRECTION is one of these 4 directions: north, south, east, west"); 
      printf("%14s ----- %s\n", "take ITEM", "pick up an item using this where ITEM is the name of an item in a room");
      printf("%14s ----- %s\n", "drop ITEM", "drop an item using this where ITEM is the name of an item in your inventory");
      printf("%14s ----- %s\n", "inventory", "check items in your inventory");
      printf("%14s ----- %s\n", "clue CHARACTER", "make a guess of the game");
      return 2;
   }

   if(strcmp(command, list) == 0) //compare with list command
   {
      printf("\n%s\n", "Rooms:");
      for(int i = 0; i < 9; i++) //listing all rooms
      {
        printf("%s\n", get_name(rooms[i]));
      }

      printf("\n%s\n", "Items:");
      for(int j = 0; j < 9; j++) //listing all items
      {
         if(rooms[j] -> items == NULL)
         {
            continue;
         }
         else 
         {
            struct Item* node = rooms[j] -> items;
            while(node != NULL)
            {
              printf("%s\n", node -> name);
              node = node -> next;
            } 
         }
      }

      printf("\n%s\n", "Characters:");
      for(int k = 0; k < 6; k++) //listing all characters
      {
         printf("%s\n", characters[k] -> name);
      }
      return 2;
   }

   if(strcmp(command, look) == 0) //compare with look command
   {
      struct Room* nnode = characters[5] -> room -> north;
      if(nnode == NULL)
      {
         printf("%s\n", "You cannot go any further north.");
      }
      else
      {
         printf("%6s %s\n", "north:", nnode -> name);
      }

      struct Room* snode = characters[5] -> room -> south;
      if(snode == NULL)
      {
         printf("%s\n", "You cannot go any further south.");
      }
      else
      {
         printf("%6s %s\n", "south:", snode -> name);
      }

      struct Room* wnode = characters[5] -> room -> west;
      if(wnode == NULL)
      {
         printf("%s\n", "You cannot go any further west.");
      }
      else
      {
         printf("%6s %s\n", "west:", wnode -> name);
      }

      struct Room* enode = characters[5] -> room -> east;
      if(enode == NULL)
      {
         printf("%s\n", "You cannot go any further east.");
      }
      else
      {
         printf("%6s %s\n", "east:", enode -> name);
      }
   
      printf("\n%s\n", "Characters in this room:"); //look all characters in this room
      for(int i = 0; i < 6; i++)
      {
         if(characters[i] -> room -> name == characters[5] -> room -> name)
         {
            printf("%s\n", characters[i] -> name);
         }
      }
 
      printf("\n%s\n", "Items in this room:"); //look all items in this room
      struct Item* node = characters[5] -> room -> items;
      if(node == NULL)
      {
         printf("%s\n", "There is no item in this room.");
      }
      else
      {
         while(node != NULL)
         {
            printf("%26s ----- %s\n", node -> name, node -> description);
            node = node -> next;
         }
      }
      return 2;
   }

   if(strcmp(command, gn) == 0) //compare with go north command
   {
      if(characters[5] -> room -> north == NULL)
      {
         printf("%s\n", "You cannot go any further north.");
      }
      else
      {
         move_character(characters[5], characters[5] -> room -> north);
         printf("%s\n\n", characters[5] -> room -> description);
      }
      return 2;
   }
 
   if(strcmp(command, gs) == 0) //compare with go south command
   {
      if(characters[5] -> room -> south == NULL)
      {
         printf("%s\n", "You cannot go any further south.");
      }
      else
      {
         move_character(characters[5], characters[5] -> room -> south);
         printf("%s\n\n", characters[5] -> room -> description);
      }
      return 2;
   }

   if(strcmp(command, gw) == 0) //compare with go west command
   {
      if(characters[5] -> room -> west == NULL)
      {
         printf("%s\n", "You cannot go any further west.");
      }
      else
      {
         move_character(characters[5], characters[5] -> room -> west);
         printf("%s\n\n", characters[5] -> room -> description);
      }
      return 2;
   }

   if(strcmp(command, ge) == 0) //compare with go east command
   {
      if(characters[5] -> room -> east == NULL)
      {
         printf("%s\n", "You cannot go any further east.");
      }
      else
      {
         move_character(characters[5], characters[5] -> room -> east);
         printf("%s\n\n", characters[5] -> room -> description);
      }
     return 2;
   }
   
   if(strcmp(command, tgt) == 0) //compare with take command
   {
      struct Item* node = item_take(list_items[0] -> name, characters[5] -> room -> items);
      if(node == NULL)
      {
         printf("%s\n", "Can't find the item.");
      }
      else 
      {
         if(strcmp(node -> name, characters[5] -> room -> items -> name) == 0)
         {
            characters[5] -> room -> items = characters[5] -> room -> items -> next;
         }
         character_get_item(characters[5], list_items[0]);
         printf("%s\n", "Done.");
      }
      return 2;
   }

   if(strcmp(command, tnmos) == 0) //compare with take command
   {
      struct Item* node = item_take(list_items[1] -> name, characters[5] -> room -> items);
      if(node == NULL)
      {
         printf("%s\n", "Can't find the item.");
      }
      else 
      {     
         if(strcmp(node -> name, characters[5] -> room -> items -> name) == 0)
         {
            characters[5] -> room -> items = characters[5] -> room -> items -> next;
         }
         character_get_item(characters[5], list_items[1]);
         printf("%s\n", "Done.");
      }
      return 2;
   }

   if(strcmp(command, tmt) == 0) //compare with take command
   {
      struct Item* node = item_take(list_items[2] -> name, characters[5] -> room -> items);
      if(node == NULL)
      {
         printf("%s\n", "Can't find the item.");
      }
      else
      {
         if(strcmp(node -> name, characters[5] -> room -> items -> name) == 0)
         {
            characters[5] -> room -> items = characters[5] -> room -> items -> next;
         }
         character_get_item(characters[5], list_items[2]);
         printf("%s\n", "Done.");
      }
      return 2;
   }

   if(strcmp(command, tgr) == 0) //compare with take command
   {
      struct Item* node = item_take(list_items[3] -> name, characters[5] -> room -> items);
      if(node == NULL)
      {
         printf("%s\n", "Can't find the item.");
      }
      else 
      {
         if(strcmp(node -> name, characters[5] -> room -> items -> name) == 0)
         {
            characters[5] -> room -> items = characters[5] -> room -> items -> next;
         }
         character_get_item(characters[5], list_items[3]);
         printf("%s\n", "Done.");
      }
      return 2;
   }
   
   if(strcmp(command, tc) == 0) //compare with take command
   {
      struct Item* node = item_take(list_items[4] -> name, characters[5] -> room -> items);
      if(node == NULL)
      {
         printf("%s\n", "Can't find the item.");
      }
      else
      {
         if(strcmp(node -> name, characters[5] -> room -> items -> name) == 0)
         {
            characters[5] -> room -> items = characters[5] -> room -> items -> next;
         }
         character_get_item(characters[5], list_items[4]);
         printf("%s\n", "Done.");
      }
      return 2;
   }

   if(strcmp(command, td) == 0) //compare with take command
   {
      struct Item* node = item_take(list_items[5] -> name, characters[5] -> room -> items);
      if(node == NULL)
      {
         printf("%s\n", "Can't find the item.");
      }
      else 
      {
         if(strcmp(node -> name, characters[5] -> room -> items -> name) == 0)
         {
            characters[5] -> room -> items = characters[5] -> room -> items -> next;
         }
         character_get_item(characters[5], list_items[5]);
         printf("%s\n", "Done.");
      }
      return 2;
   }

   if(strcmp(command, dgt) == 0) //compare with drop command
   {
      character_drop_item(characters[5], list_items[0]);
      if(characters[5] -> room -> items == NULL)
      {
         characters[5] -> room -> items = list_items[0];
      }
      else 
      {
         struct Item* node = characters[5] -> room -> items;
         while(node -> next != NULL)
         {
            node = node -> next;
         }
         node -> next = list_items[0];
      }
      printf("%s\n", "Done.");
      return 2;
   }

   if(strcmp(command, dnmos) == 0) //compare with drop command
   {
      character_drop_item(characters[5], list_items[1]);
      if(characters[5] -> room -> items == NULL)
      {
         characters[5] -> room -> items = list_items[1];
      }
      else
      {
         struct Item* node = characters[5] -> room -> items;
         while(node -> next != NULL)
         {
            node = node -> next;
         }
         node -> next = list_items[1];
      }
      printf("%s\n", "Done.");
      return 2;
   }
 
   if(strcmp(command, dmt) == 0) //compare with drop command
   {
      character_drop_item(characters[5], list_items[2]);
      if(characters[5] -> room -> items == NULL)
      {
         characters[5] -> room -> items = list_items[2];
      }
      else
      {
         struct Item* node = characters[5] -> room -> items;
         while(node -> next != NULL)
         {
            node = node -> next;
         }
         node -> next = list_items[2];
      }
      printf("%s\n", "Done.");
      return 2;
   }

   if(strcmp(command, dgr) == 0) //compare with drop command
   {
      character_drop_item(characters[5], list_items[3]);
      if(characters[5] -> room -> items == NULL)
      {
         characters[5] -> room -> items = list_items[3];
      }
      else
      {
         struct Item* node = characters[5] -> room -> items;
         while(node -> next != NULL)
         {
            node = node -> next;
         }
         node -> next = list_items[3];
      }
      printf("%s\n", "Done.");
      return 2;
   }

   if(strcmp(command, dc) == 0) //compare with drop command
   {
      character_drop_item(characters[5], list_items[4]);
      if(characters[5] -> room -> items == NULL)
      {
         characters[5] -> room -> items = list_items[4];
      }
      else
      {
         struct Item* node = characters[5] -> room -> items;
         while(node -> next != NULL)
         {
            node = node -> next;
         }
         node -> next = list_items[4];
      }
      printf("%s\n", "Done.");
      return 2;
   }

   if(strcmp(command, dd) == 0) //compare with drop command
   {
      character_drop_item(characters[5], list_items[5]);
      if(characters[5] -> room -> items == NULL)
      {
         characters[5] -> room -> items = list_items[5];
      }
      else
      {
         struct Item* node = characters[5] -> room -> items;
         while(node -> next != NULL)
         {
            node = node -> next;
         }
         node -> next = list_items[5];
      }
      printf("%s\n", "Done.");
      return 2;
   }

   if(strcmp(command, inventory) == 0) //compare with inventory command
   {
      struct Item* node = characters[5] -> items;
      if(node == NULL)
      {
         printf("%s\n", "no items in you inventory");
      }
      else
      {
         while(node != NULL)
         {
            printf("%s\n", node -> name);
            node = node -> next;
         }
      }
      return 2;
   }
   return 1;
}

//This function is built to help calculate the clue command and find the game result
//   param character: the character you call clue on
//   param characters[]: the arraylist of characters
//   param answer_room: the answer of room
//   param answer_character: the answer of character
//   param answer_item: the answer of item
//   param try_time: an int counting for the time of try
//   return:0 if lose, 1 if win, and 2 if nothing happens 
int clue(struct Character* character, struct Character* characters[], struct Room* answer_room, struct Character* answer_character, struct Item* answer_item, int try_time)
{   
   move_character(character, characters[5] -> room);
   if(strcmp(characters[5] -> room -> name, answer_room -> name) == 0)
   {
      printf("%s\n", "Room Match");
   }
   if(strcmp(get_name(characters[5] -> room), get_name(answer_character -> room)) == 0)
   {
      printf("%s\n", "Character Match");
   }
   struct Item* node1 = characters[5] -> room -> items;
   while(node1 != NULL)
   {
      if(strcmp(node1 -> name, answer_item -> name) == 0)
      {
         printf("%s\n", "Item Match");
         break;
      }
      else
      {
         node1 = node1 -> next;
      }
   }
   struct Item* node2 = characters[5] -> items;
   if(node1 == NULL)
   {
      while(node2 != NULL)
      {
         if(strcmp(node2 -> name, answer_item -> name) == 0)
         {
            printf("%s\n", "Item Match");
            break;
         }
         else
         {
            node2 = node2 -> next;
         }
      }
   }
   if(try_time == 10 && (strcmp(characters[5] -> room -> name, answer_room -> name) != 0 || strcmp(characters[5] -> room -> name, answer_character -> room -> name) != 0 || (node1 == NULL && node2 == NULL)))
   {
      printf("%s\n", "Game Over! Please try again!");
      return 0;
   }
   else if(try_time <= 10 && strcmp(characters[5] -> room -> name, answer_room -> name) == 0 && strcmp(characters[5] -> room -> name, answer_character -> room -> name) == 0 && (node1 != NULL || node2 != NULL))
   {
      printf("%s\n", "Congratulations! You won the game!");
      return 1;
   }      
   return 2;
}

//The main function         
void main()
{
   struct Room* roomA = room("beach", "Taking a deep breath, you find out that you are now on a beach. The salty smell from the sea wind makes you feel relaxed and refreshing, however, you have a feeling that there must be something strange and mysterious under this unrealistic or even frightening peace.", NULL, NULL, NULL, NULL, NULL);


   struct Room* roomB = room("coast", "You are now walking along the coast. Suddenly, a harsh sound from somewhere near you got your attention. It is already midnight and you know you definitly need a light to find out which direction the squeaks come from. The trembling light from the lamp lights up the darkness, you cautiously step toward the noise. Under a huge rock, there is a skeleton lying in a really strange posture. As the moment you find it, a weired but bright green light flashes on the head of the skeleton and then vanishes in the dark. OMG! Is that magic or some kind of witchcraft? You are totally scared and just want to leave this place as soon as possible.", NULL, NULL, NULL, NULL, NULL);


   struct Room* roomC = room("forest", "Now you are in a forest and there is a log cabin standing up there with many old and broken pirate flags. This cabin seems has been spared for many decades. Creepers and vines interwines the whole building and you finally find a way to enter. There are many paintings on the wall describing the scenary pirates hunting enormous creatures in the waves of the deep sea.", NULL, NULL, NULL, NULL, NULL);
          

   struct Room* roomD = room("cliff", "Standing on a steep cliff, you see something bright jumping among the waves near the coast. Maybe just the moonlight? You thought. Wait, it is not normal, it is so bright and so penetrating! You use the rope in your backpack and climbed down to the remains of the ship. The woodens of the ship are decomposed and the ship it self has became home for many sea creatures.", NULL, NULL, NULL, NULL, NULL);

    
   struct Room* roomE = room("tree hole", "You find a tree hole in the forest, with a signature on it. But many years or decades have past and it is hard to find out what his name is.", NULL, NULL, NULL, NULL, NULL);
    
    
   struct Room* roomF = room("cave", "You find a cave in the deep forest. With many vivid frescos inside, the cave may have a lot of stories to tell. You can read from the frescos that there was a bloody battle between a group of pirates and an incredibly huge octopus. After winning that big octopus, those pirates continued their adventure for another challenge.", NULL, NULL, NULL, NULL, NULL);


   struct Room* roomG = room("hill", "You climb to the top of the hill where you can see the whole island. Staring up at the stars, you dicide to have a short break.", NULL, NULL, NULL, NULL, NULL);


   struct Room* roomH = room("grave", "You notice there is little pile of soil that looks very soft and different from other places. You touch the soil with your hands softly and discover a stone botten under it. Along with a heavy sound, a path to the underground appears in front of you. As you carefully go down the stairs, the path becomes brighter and brighter. It is a grave for pirates. Boxes and boxes of jewleries and weapons are placed against the wall. In the middle of the grave, a gorgeously dressed skeleton sit in a golden chair in a dignifies gesture. Winds blowing in the grave, and the moonlight makes the pirate's sword glowing.", NULL, NULL, NULL, NULL, NULL);


   struct Room* roomI = room("bones", "You see a giant pile of bones of a monster on the beach with many crabs crawling around. Right next to it is a shabby camp.", NULL, NULL, NULL, NULL, NULL);


   struct Character* charA = character("The soul of White Beard", "White Beard is a legend pirate who has defeated many monsters in his life. He is 6.8 ft tall and his voice is super intimidating.", NULL, NULL);


   struct Character* charB = character("The soul of Big Jay", "Big Jay is a big man with a careful mind. He loves painting and worked as a navigator in the group", NULL, NULL);


   struct Character* charC = character("The soul of Rose", "Rose is the only woman in her team and has a beautiful face and soft voice. Looking at her, nobody is gonna think her as a pirate.", NULL, NULL);


   struct Character* charD = character("The soul of Cici", "Cici is a parrot with tiery red body and yellow tail who loves singing to the sea.",
                                     NULL, NULL);

   struct Character* charE = character("The soul of Doggie", "Doggie is a thief who is very good at fighting. His main goal as a pirate is to find unlimited treasures.", NULL, NULL);

   struct Character* user = character("Haochen", "You are a college student who accidently recieved a message from an anonymous person. You click the link he attached and fall into another world. You are told to win this clue game to get things back to normal. If you fail, you will never leave this island where night stays forever. You already have a lamp, a rope, a shovel, and a knife in your backpack.", NULL, NULL);


   struct Item* itemA = item("A golden tooth", "This might be helpful for you to get out of this place. Don't laugh! Probably it will, who knows?", NULL);


   struct Item* itemB = item("A necklace made of stone", "It is quite heavy, but one of a kind. It has a letter J on it.", NULL);


   struct Item* itemC = item("A monocular telescope", "It is probably used by pirates for navigation.", NULL);


   struct Item* itemD = item("A golden ring", "This ring has plenty of little gems on it. After so many years, it is still very shiny.", NULL);


   struct Item* itemE = item("A compass", "A compass is a good tool to navigate while sailing.", NULL);


   struct Item* itemF = item("A diary", "This diary is written to record daily stuff happened on a team of pirates. The writter's name is Rose.", NULL);

   struct Room* rooms[9] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
   struct Room* list_room[9] = {roomA, roomB, roomC, roomD, roomE, roomF, roomG, roomH, roomI};
   struct Item* list_items[6] = {itemA, itemB, itemC, itemD, itemE, itemF};
   struct Character* characters[6] = {charA, charB, charC, charD, charE, user};
   srand(time(0));
   int a = rand() % 9;
   struct Room* answer_room = list_room[a]; //randomly initialize the answer of room
   int b = rand() % 6;
   struct Item* answer_item = list_items[b]; //randomly initialize the answer of item
   int c = rand() % 5;
   struct Character* answer_character = characters[c]; //randomly initialize the answer of character

   int try_time = 0; //initialize the try_time
   int n = 2; //n = 2 because nothing happens here at the beginning
   char command[99]; //to store the user input
   int result;
   reset(rooms, list_room, list_items, characters); //reset game board
   printf("%s\n", characters[5] -> room -> description);
   printf("%s\n", "Game Start! Please type in your command.");
   while(n == 2) //while(nothing happens)
   {
      scanf("%[^\n]%*c", command);
      result = Command(command, characters, rooms, list_items);
      char cwb[] = "clue White Beard";
      char cbj[] = "clue Big Jay";
      char crose[] = "clue Rose";
      char ccici[] = "clue Cici";
      char cdoggie[] = "clue Doggie"; 
      if(strcmp(command, cwb) == 0)
      {
         try_time++;
         n = clue(characters[0], characters, answer_room, answer_character, answer_item, try_time);
         printf("guess time: %d\n", try_time);
      }
      if(strcmp(command, cbj) == 0)
      {
         try_time++;
         n = clue(characters[1], characters, answer_room, answer_character, answer_item, try_time);
         printf("guess time: %d\n", try_time);
      }
      if(strcmp(command, crose) == 0)
      {
         try_time++;
         n = clue(characters[2], characters, answer_room, answer_character, answer_item, try_time);
         printf("guess time: %d\n", try_time);
      }
      if(strcmp(command, ccici) == 0)
      {
         try_time++;
         n = clue(characters[3], characters, answer_room, answer_character, answer_item, try_time);
         printf("guess time: %d\n", try_time);
      }
      if(strcmp(command, cdoggie) == 0)
      {
         try_time++;
         n = clue(characters[4], characters, answer_room, answer_character, answer_item, try_time);
         printf("guess time: %d\n", try_time);
      }
      if(result == 1 &&  strcmp(command, cwb) != 0 && strcmp(command, cbj) != 0 && strcmp(command, crose) != 0 && strcmp(command, ccici) != 0 && strcmp(command, cdoggie) != 0)
      {
         printf("%s\n", "Sorry, I can't understand you. Please try again.");
      }
   }
   printf("%s\n", "Thanks for playing!");
}     

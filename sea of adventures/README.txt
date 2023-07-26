In this game, you are an adventurer whose ship was wrecked in a storm. When you wake up, you found
that you are now on an island, in the middle of the sea. Your final goal is to collect the right item, bring that
item to the right person you meet on the island, and then escape in a right place. Otherwise, you will never
get a chance to get out here!

Before the game begins, I create 3 arraylists containing characters, items, and rooms. And then create another 
arraylist for rooms after randomly initialization. I use rand() to randomly initialize the position of each room, 
and use rand() to put each item and characters in the rooms. Here, I can get the avatar by using characters[5] because the
avatar is always placed at the end of the array. Answers of room, character, item are all randomly selected by using rand(). 
The input from the user is passed to the Command function to see what the game should do with it and either returns 1 or 2. 
It returns 2 if a command other than clue has been processed, and returns 1 otherwise. In the main function, I check if the 
user's input matches one of the clue command and if so, I process it with the clue function. If not matches, then display a 
sentence says that I can't understand the command. In the clue function, clue commands are processed and the clue result 
will be given. Also, try times are counted at each time when the user's command is clue CHARACTER, and the game result 
will show on screen if the game is end.    


Video: https://drive.google.com/file/d/1Ndv_J4ygC9XtHdamwqSwS0wTheuR8Ugc/view?usp=sharing

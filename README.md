# Dungeon-Game-Applying-BST-and-Heaps
An interactive adventure game where you explore a dungeon to find wonderful items with different grade and rarity!

How to Run the Code
To run this code, you need to have a C++ development environment set up. Here's how you can compile and run it:
1.	Install a C++ Compiler:
	- On Linux, you can use g++.
	- On Windows, you can use MinGW or Visual Studio's C++ compiler.
	- On macOS, you can use clang++.
	- On Android, you can use Cxxdroid
6.	Save the Code:
	- Copy and paste the code into a text file and save it with a .cpp extension, e.g., dungeon_escape.cpp.
8.	Compile the Code:
	- Open a terminal or command prompt.
10.	Run the Program
	- Open a terminal or command prompt.



**Description of Each Functionality**


1. DungeonNode Structure
   -	Represents a room in the dungeon.
   -	Contains the following data members:
   -	  roomID: An integer ID for the room.
   -	  treasure: A string representing the treasure in the room.
   -	  tier: A string that categorizes the rarity of the treasure (e.g., "Common", "Rare").
   -	  rarity: An integer representing the rarity level of the treasure.
   -	  left and right: Pointers to left and right child nodes, representing the binary search tree structure.
3. Dungeon Class
   - A binary search tree (BST) to store the rooms of the dungeon.
   - Functions:
       - addRoom(int, string, string, int): Adds a room to the dungeon by creating a DungeonNode and placing it at the correct position in the BST based on the roomID.
       - exploreDungeon(DungeonNode*): Recursively explores the dungeon by traversing the BST and printing out details of each room.
       - explore(): Initiates the exploration of the dungeon. It calls exploreDungeon if the dungeon is not empty.
       - findRoom(DungeonNode*, int): Searches for a room in the dungeon by its roomID using a binary search approach.
       - findRoom(int): A wrapper around the recursive findRoom function to search from the root of the BST.
5. TreasureBag Class
   - Implements a max-heap to store treasures with their rarity.
   - Functions:
       - addTreasure(int, string): Adds a treasure to the bag, ensuring that the heap property is maintained by calling heapifyUp.
       - retrieveMostValuable(): Retrieves and removes the most valuable treasure from the bag (the one with the highest rarity), while maintaining the heap property by calling heapifyDown.
       - displayTreasures(): Displays all the treasures currently in the treasure bag.
7. GameMenu Function
   - Displays a menu with options for the player to interact with the game. These options include adding a room, exploring the dungeon, collecting treasures, and more.
9. getRandomTier Function
    - Generates a random treasure tier from a list of predefined tiers ("Common", "Rare", "Epic", "Legendary", "Transcended") using the rand() function.
11. Main Function
    - Initializes the game by setting up a dungeon and treasure bag.
    - Presents a loop where the player can choose an action (add room, explore, collect treasures, etc.).
    - Each action is handled by calling the appropriate function in the Dungeon or TreasureBag class.

****Detailed Functionalities and Flow****
1.	Adding a Room:
    - The player can add a room to the dungeon. A random room ID and a random treasure are generated. The room is inserted into the dungeon using the binary search tree (BST) structure.
3.	Exploring the Dungeon:
    - The player can explore the dungeon, which triggers an in-order traversal of the BST. This prints the details of all rooms in the dungeon in ascending order of their roomID.
4.	Collecting Treasures:
    - The player can collect a treasure from a specific room by entering the room's ID. If the room exists in the dungeon, the treasure is added to the player's treasure bag. The treasure is added according to its rarity to ensure that higher rarity treasures are prioritized.
6.	Retrieving the Most Valuable Treasure:
    - The player can retrieve the most valuable treasure from the treasure bag (based on rarity). The treasure is removed from the heap, and the heap property is maintained.
8.	Displaying Treasures:
    - The player can view all treasures currently in their treasure bag, including their rarity.
10.	Escaping the Dungeon:
    - The player can choose to escape the dungeon, which ends the game.

   ======== (sample output)
   ========
   ========
**Welcome to the Dungeon Escape Game!**
   ========


=== Dungeon Escape Game ===
1. Add a room to the dungeon
2. Explore the dungeon
3. Collect treasure from a room
4. Retrieve the most valuable treasure from your bag
5. Display treasures in your bag
6. Escape the dungeon
===========================
Choose an action: 1
Added Room 35 with a Rare Sapphire (Rarity: 30).

=== Dungeon Escape Game ===
1. Add a room to the dungeon
2. Explore the dungeon
3. Collect treasure from a room
4. Retrieve the most valuable treasure from your bag
5. Display treasures in your bag
6. Escape the dungeon
===========================
Choose an action: 3
Enter the room ID to collect treasure: 35
Collected Sapphire (Rarity: 30) from Room 35.

=== Dungeon Escape Game ===
1. Add a room to the dungeon
2. Explore the dungeon
3. Collect treasure from a room
4. Retrieve the most valuable treasure from your bag
5. Display treasures in your bag
6. Escape the dungeon
===========================
Choose an action: 4
Retrieved your most valuable treasure: Sapphire!




  



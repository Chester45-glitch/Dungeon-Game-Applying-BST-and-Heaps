#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Binary Tree Node for Dungeon
struct DungeonNode {
    int roomID;
    string treasure;
    string tier;
    int rarity;
    DungeonNode* left;
    DungeonNode* right;
    DungeonNode(int id, string item, string t, int rare)
        : roomID(id), treasure(item), tier(t), rarity(rare), left(nullptr), right(nullptr) {}
};

// Dungeon (Binary Search Tree) Class
class Dungeon {
public:
    DungeonNode* root;

    Dungeon() : root(nullptr) {}

    DungeonNode* addRoom(DungeonNode* node, int roomID, string treasure, string tier, int rarity) {
        if (!node) return new DungeonNode(roomID, treasure, tier, rarity);
        if (roomID < node->roomID)
            node->left = addRoom(node->left, roomID, treasure, tier, rarity);
        else
            node->right = addRoom(node->right, roomID, treasure, tier, rarity);
        return node;
    }

    void addRoom(int roomID, string treasure, string tier, int rarity) {
        root = addRoom(root, roomID, treasure, tier, rarity);
    }

    void exploreDungeon(DungeonNode* node) {
        if (!node) return;
        exploreDungeon(node->left);
        cout << "Room " << node->roomID << " contains a " << node->tier << " " << node->treasure
             << " (Rarity: " << node->rarity << ").\n";
        exploreDungeon(node->right);
    }

    void explore() {
        if (!root)
            cout << "The dungeon is empty!\n";
        else
            exploreDungeon(root);
    }

    DungeonNode* findRoom(DungeonNode* node, int roomID) {
        if (!node || node->roomID == roomID) return node;
        if (roomID < node->roomID) return findRoom(node->left, roomID);
        return findRoom(node->right, roomID);
    }

    DungeonNode* findRoom(int roomID) {
        return findRoom(root, roomID);
    }
};

// Max-Heap for Treasure Collection
class TreasureBag {
private:
    vector<pair<int, string>> treasures; // Pair of rarity and treasure name

    void heapifyUp(int index) {
        while (index > 0 && treasures[(index - 1) / 2].first < treasures[index].first) {
            swap(treasures[index], treasures[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < treasures.size() && treasures[left].first > treasures[largest].first)
            largest = left;
        if (right < treasures.size() && treasures[right].first > treasures[largest].first)
            largest = right;

        if (largest != index) {
            swap(treasures[index], treasures[largest]);
            heapifyDown(largest);
        }
    }

public:
    void addTreasure(int rarity, string treasure) {
        treasures.push_back({rarity, treasure});
        heapifyUp(treasures.size() - 1);
    }

    string retrieveMostValuable() {
        if (treasures.empty()) throw runtime_error("Your treasure bag is empty!");
        string treasure = treasures[0].second;
        treasures[0] = treasures.back();
        treasures.pop_back();
        heapifyDown(0);
        return treasure;
    }

    void displayTreasures() {
        cout << "Treasures in your bag: ";
        for (auto& treasure : treasures)
            cout << treasure.second << " (Rarity: " << treasure.first << ") ";
        cout << endl;
    }
};

// Game Menu
void gameMenu() {
    cout << "\n=== Dungeon Escape Game ===\n";
    cout << "1. Add a room to the dungeon\n";
    cout << "2. Explore the dungeon\n";
    cout << "3. Collect treasure from a room\n";
    cout << "4. Retrieve the most valuable treasure from your bag\n";
    cout << "5. Display treasures in your bag\n";
    cout << "6. Escape the dungeon\n";
    cout << "===========================\n";
    cout << "Choose an action: ";
}

// Helper function to get a random tier
string getRandomTier() {
    vector<string> tiers = {"Common", "Rare", "Epic", "Legendary", "Transcended"};
    return tiers[rand() % tiers.size()];
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Extended list of possible treasures
    vector<pair<string, int>> treasureList = {
        {"Sapphire", 30}, {"Demon Sword", 50}, {"Magic Robe", 40},
        {"Assault Cuirass", 45}, {"Wand of Eternity", 60}, {"Healing Potion", 20},
        {"Mystic Orb", 35}, {"Phoenix Feather", 55}, {"Dragon Scale", 65},
        {"Cursed Amulet", 25}, {"Golden Crown", 70}, {"Ancient Relic", 50},
        {"Enchanted Boots", 30}, {"Shadow Cloak", 40}, {"Crystal Dagger", 55},
        {"Inferno Shield", 65}, {"Ethereal Armor", 75}, {"Ring of Time", 80},
        {"Emerald Gem", 40}, {"Frozen Fang", 50}, {"Soul Fragment", 60}
    };

    Dungeon dungeon;
    TreasureBag treasureBag;
    int choice, roomID;

    cout << "Welcome to the Dungeon Escape Game!\n";

    while (true) {
        gameMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            roomID = rand() % 100 + 1; // Random room ID
            int index = rand() % treasureList.size(); // Random treasure
            string tier = getRandomTier(); // Random tier
            dungeon.addRoom(roomID, treasureList[index].first, tier, treasureList[index].second);
            cout << "Added Room " << roomID << " with a " << tier << " " << treasureList[index].first
                 << " (Rarity: " << treasureList[index].second << ").\n";
            break;
        }
        case 2:
            dungeon.explore();
            break;

        case 3: {
            cout << "Enter the room ID to collect treasure: ";
            cin >> roomID;
            DungeonNode* room = dungeon.findRoom(roomID);
            if (room) {
                treasureBag.addTreasure(room->rarity, room->treasure);
                cout << "Collected " << room->treasure << " (Rarity: " << room->rarity
                     << ") from Room " << roomID << ".\n";
            } else {
                cout << "Room " << roomID << " does not exist in the dungeon!\n";
            }
            break;
        }
        case 4: {
            try {
                string treasure = treasureBag.retrieveMostValuable();
                cout << "Retrieved your most valuable treasure: " << treasure << "!\n";
            } catch (runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 5:
            treasureBag.displayTreasures();
            break;

        case 6:
            cout << "Escaping the dungeon with your treasures. Goodbye, adventurer!\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}

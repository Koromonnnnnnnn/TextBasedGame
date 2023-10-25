#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
using namespace std;

// gens
string monsterGen();
string lootGen();

// battle
void initiatebossFight();
void initiatenormalFight();
void chestFunction();

// songs
void deathSong();
void victorySong();
void welcomeSong();
void attackSong();
void damageSong();

// inventory
const int inventorySize = 10;
int itemCount = 0;
string inventory[inventorySize]; // Create a list to store weapons
void inventoryMenu();

// data
int hasbeenRoom1 = 0;
int hasbeenRoom2 = 0;
int hasbeenRoom3 = 0;
int hasbeenRoom4 = 0;
int hasbeenRoom5 = 0;
int hasbeenRoom6 = 0;
int hasbeenRoom7 = 0;
int hasbeenRoom8 = 0;
int hasbeenRoom9 = 0;
int hasbeenRoom10 = 0;

// health and damage
int playerHealth = 100;
int playerDamage = 25;
int monsterHealth = 50;
int monsterDamage = 10;
int bossHealth = 50;
int bossDamage = 10;

// gameloop
bool gameGoing = true;

// inventory
char inventoryChoice;

// return
string monster;
string chestLoot;

// other functions

int main()
{
    // nav
    char destination;
    int roomIn;

    // questions after battle
    char initialQuestion;
    char finalQuestion;

    // battle
    int playerHealth = 100;
    int playerDamage = 25;
    int monsterHealth = 50;
    int monsterDamage = 10;
    int bossHealth = 200;
    int bossDamage = 30;

    cout << "Welcome to \"The Forgotten Prophecy\"" << endl;
    cout << "You wake up somewhere unknown. Bright green grass and orange trees surround you." << endl;
    cout << "Your memory is foggy and you can't quite remember anything about yourself, or how you got to this mysterious place." << endl;
    cout << "The only path forward is a steep set of ancient stone stairs." << endl;
    cout << "Press '0' to play..." << endl;
    cin >> roomIn;

    while (gameGoing)
    {
        switch (roomIn)
        {
        case 0:
            while (hasbeenRoom1 != 0)
            {
                cout << "Continue? Y/N" << endl;
                cin >> initialQuestion;
                if (initialQuestion == 'y' || initialQuestion == 'Y')
                {
                    cout << "You are in 'Room One', do you wish to go (E)ast towards 'Room Two'?" << endl;
                    cin.ignore();
                    cin >> destination;
                    if (destination == 'e' || destination == 'E')
                        roomIn = 1; // 2
                }
                else if (initialQuestion == 'n' || initialQuestion == 'N')
                {
                    cout << "Terminal Destroyed..." << endl;
                    gameGoing = false;
                    break;
                }
                else
                {
                    cout << "Not a valid option..." << endl;
                }
            }
            cout << "You are currently in Room One" << endl;
            initiatenormalFight();
            cout << "Continue? Y/N" << endl;
            cin >> finalQuestion;
            if (finalQuestion == 'y' || finalQuestion == 'Y')
            {
                cout << "You are in 'Room One', do you wish to go (E)ast towards 'Room Two'?" << endl;
                cin.ignore();
                cin >> destination;
                if (destination == 'e' || destination == 'E')
                    roomIn = 1; // 2
            }
            else if (finalQuestion == 'n' || finalQuestion == 'N')
            {
                cout << "Terminal Destroyed..." << endl;
                gameGoing = false;
                break;
            }
            else
            {
                cout << "Not a valid option..." << endl;
            }
            break;
        case 1:
            monsterHealth += monsterHealth; // revive monster for next fight
            while (hasbeenRoom2 != 1)
            {
                cout << "Press enter to heal" << endl;
                cin.ignore();
                cin.get();
                playerHealth += monsterDamage; // heals player from previous fight damage
                cout << "You have been healed!" << endl;
                hasbeenRoom2++;
            }
            cout << "You are in 'Room Two', do you wish to go (S)outh towards 'Room Three'? Or (W)est back to 'Room One'" << endl;
            cin >> destination;
            if (destination == 's' || destination == 'S')
                roomIn = 2; // 3
            if (destination == 'w' || destination == 'W')
                roomIn = 0; // 1
            break;
        case 2:
            cout << "You are in 'Room Three', you can go (S)outh to 'Room Four' (Cave), or (N)orth back to 'Room Two'" << endl;
            cin >> destination;
            if (destination == 's' || destination == 'S')
                roomIn = 3; // 4
            if (destination == 'n' || destination == 'N')
                roomIn = 1; // 2
            break;
        case 3:
            cout << "You are in 'Room Four', you can go (E)ast to 'Room Five', or (N)orth back to 'Room Three'" << endl;
            cin >> destination;
            if (destination == 'e' || destination == 'E')
                roomIn = 4; // 5
            if (destination == 'n' || destination == 'N')
                roomIn = 2; // 3
            break;
        case 4:
            cout << "You are in 'Room Five', you can go (N)orth to 'Room Six', or (W)est back to 'Room Four'" << endl;
            cin >> destination;
            if (destination == 'n' || destination == 'N')
                roomIn = 5; // 6
            if (destination == 'w' || destination == 'W')
                roomIn = 3; // 3
            break;
        case 5:
            cout << "You are in 'Room Six', you can go (E)ast to 'Room Seven', or (S)outh back to 'Room Five'" << endl;
            cin >> destination;
            if (destination == 'e' || destination == 'E')
                roomIn = 6; // 7
            if (destination == 's' || destination == 'S')
                roomIn = 4; // 5
            break;
        }
    }
}

string monsterGen()
{
    string monsterItems[] = {"Witch", "Kraken", "Alien", "Dog", "Mysterious Entity"};

    int numItems = sizeof(monsterItems) / sizeof(monsterItems[0]);

    srand(time(0));

    int randomIndex = rand() % numItems;

    return monsterItems[randomIndex];
}

string lootGen()
{
    string chestItems[] = {"Sword", "Spear", "Trident", "Bow", "Godly Bolt"};

    int numItems = sizeof(chestItems) / sizeof(chestItems[0]);

    srand(time(0));

    int randomIndex = rand() % numItems;

    return chestItems[randomIndex];
}

void inventoryMenu()
{
    if (itemCount < inventorySize)
    {
        cout << "Enter the name of the weapon to add: ";
        cin >> inventory[itemCount];
        itemCount++;
        cout << "Weapon added to your inventory." << endl;
    }
    else
    {
        cout << "Alright then" << endl;
    }
}

void deathSong()
{

    int notes[] = {392, 349, 330, 293, 261};
    int durations[] = {200, 200, 200, 400, 400};

    for (int i = 0; i < 5; i++)
    {
        Beep(notes[i], durations[i]);
        Sleep(100);
    }
}

void victorySong()
{

    int notes[] = {523, 587, 659, 698, 783, 880, 987, 1046};
    int durations[] = {500, 500, 500, 500, 500, 500, 500, 1000};

    for (int i = 0; i < 8; i++)
    {
        Beep(notes[i], durations[i]);
        Sleep(100);
    }
}

void damageSong()
{
}

void attackSong()
{
}

void welcomeSong()
{
}

void initiatebossFight()
{
}

void initiatenormalFight()
{
    while (monsterHealth > 0 && playerHealth > 0)
    {
        monster = monsterGen();
        cout << "A wild " << monster << " appears!" << endl;
        monsterGen();
        cout << "Press enter to attack" << endl;
        cin.ignore();
        cin.get();
        monsterHealth -= playerDamage;
        cout << "You attack the " << monster << " for " << playerDamage << " damage" << endl;
        if (playerHealth > 0)
        {
            playerHealth -= monsterDamage;
            cout << monster << " attacks you for " << monsterDamage << " damage" << endl;
        }
        if (playerHealth <= 0)
        {
            deathSong();
            cout << "You are dead..." << endl;
            gameGoing = false; // End the game if the player dies
            break;
        }

        if (!gameGoing)
        {
            break; // incase if for some reason it doesnt already quit
        }

        cout << "Press enter to attack again" << endl;
        cin.ignore();
        cin.get();
        cout << "You have slayed " << monster << endl;
        monsterHealth -= playerDamage; // kills monster here
        hasbeenRoom1++;
    }
}

void chestFunction()
{
    while (playerHealth > 0)
    {
        cout << "You look around the room and spot a chest!" << endl;
        cout << "Press enter to open the chest..." << endl;
        chestLoot = lootGen();
        cin.ignore();
        cin.get();
        cout << "You have found " << chestLoot << endl;
        cout << "Would you like to add this item to your inventory? Y/N" << endl;
        cin >> inventoryChoice;
        if (inventoryChoice == 'y' || inventoryChoice == 'Y')
        {
            inventoryMenu();
        }
        else if (inventoryChoice == 'n' || inventoryChoice == 'N')
        {
            break;
        }
        else
        {
            cout << "invalid option" << endl;
            gameGoing = false;
            break;
        }

        if (!gameGoing)
        {
            break; // incase if for some reason it doesnt already quit
        }
    }
}

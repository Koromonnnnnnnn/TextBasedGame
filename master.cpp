#include <iostream>
#include <Windows.h>
using namespace std;

bool gameLoop = true;

// Shop
int gold = 0;
void shop();

// Gens
string monsterGen();
string lootGen();

// Inventory
string inventory[10];

// Return
string monster;
string loot;

// Battle
void initiatebossFight();
void initiatenormalFight();

// Songs
void deathSong();
void victorySong();
void welcomeSong();
void attackSong();
void damageSong();

int main()
{
    for (int i = 0; i < 10; i++)
        inventory[i] = " ";

    int room = 1;
    char direction;

    cout << "Welcome to \"The Forgotten Prophecy\"" << endl;
    cout << "You wake up somewhere unknown. Bright green grass and orange trees surround you." << endl;
    cout << "Your memory is foggy and you can't quite remember anything about yourself, or how you got to this mysterious place." << endl;
    cout << "The only path forward is a steep set of ancient stone stairs." << endl;

    while (1)
    {
        switch (room)
        {
        case 1:
            cout << "You are in 'Room One', do you wish to go (E)ast towards 'Room Two'?" << endl;
            if (inventory[0] != "Key")
                cout << "You see a (K)ey on the floor." << endl;
            cin >> direction;
            if (direction == 'E' || direction == 'e')
                room = 2;
            if (direction == 'K' || direction == 'k')
                inventory[0] = "Key";
            break;
        case 2:
            cout << "You are in 'Room Two', do you wish to go (S)outh towards 'Room Three'? Or (W)est back to 'Room One'" << endl;
            cin >> direction;
            if (direction == 'W' || direction == 'w')
                room = 1;
            if (direction == 'S' || direction == 's')
                room = 3;
            break;
        case 3:
            cout << "You are in 'Room Three', you can go (S)outh to 'Room Four' (Cave), or (N)orth back to 'Room Two'" << endl;
            cin >> direction;
            if (direction == 'N' || direction == 'n')
                room = 2;
            if (direction == 'S' || direction == 's')
                room = 4;
            break;
        case 4:
            cout << "You are in 'Room Four', you can go (E)ast to 'Room Five', or (N)orth back to 'Room Three'" << endl;
            cin >> direction;
            if (direction == 'N' || direction == 'n')
                room = 3;
            if (direction == 'E' || direction == 'e')
                room = 5;
            break;
        case 5:
            cout << "You are in 'Room Five', you can go (N)orth to 'Room Six', or (W)est back to 'Room Four'" << endl;
            cin >> direction;
            if (direction == 'W' || direction == 'w')
                room = 4;
            if (direction == 'N' || direction == 'N')
                room = 6;
            break;
        case 6:
            cout << "You are in 'Room Six', you can go (E)ast to 'Room Seven', or (S)outh back to 'Room Five'" << endl;
            cin >> direction;
            if (direction == 'E' || direction == 'e')
                room = 4; // fix when add more rooms (change to 7)
            if (direction == 'S' || direction == 'e')
                room = 5;
            break;
        case 7:

        case 8:

        case 9:

        case 10:
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

void shop()
{
    int input;
    while (input != '0')
    {
        cout << "welcome to the shop" << endl;
        cout << "items for sale:" << endl;
        cout << "1) Cupcake: $5" << endl;
        cout << "2) Sock: $10" << endl;
        cout << "3) Key: $50" << endl;
        cout << "Your Inventory:" << endl;
        cout << "0 to QUIT" << endl;
        cout << "Your Gold: " << gold << endl;
        for (int i = 0; i < 10; i++)
            cout << inventory[i] << " ";
        cout << endl;
        cout << "What would you like to purchase?" << endl;
        cin >> input;
        if (input == 1)
        {
            if (gold >= 5)
            {
                cout << "You bought the cupcake!" << endl;
                inventory[1] = "Cupcake";
                gold -= 5;
            }
            else
                cout << "You dont have enough gold!" << endl;
        }
        else if (input == 2)
        {
            if (gold >= 10)
            {
                cout << "You bought the sock!" << endl;
                inventory[2] = "Sock";
                gold -= 10;
            }
        }
        else if (input == 3)
        {
            if (gold > -50)
            {
                cout << "You bought the key!" << endl;
                inventory[0] = "Key";
                gold -= 50;
            }
        }
        else
        {
            cout << "not an option, dummy" << endl;
        }
        break;
    }
}
#include <iostream>
#include <Windows.h>
using namespace std;

bool gameLoop = true;

// Shop
int gold = 0;
void shop();

// Gens
string monsterGen();
string weaponGen();
string attackGen();
int damageGen();

// Inventory
string inventory[10];
string shopInventory[10]; // second inventory for organization

// data
string monstersData[5];
string chestData[5];
string roomData[10];
string marketData[1];

// Battle
string initiatebossFight();
string initiatenormalFight();

// Songs
void deathSong();
void victorySong();
void welcomeSong();
void attackSong();
void damageSong();

// Other

void blackMarket();

// Pet
string petActions();
string petGenerator();
int petAffinity = 0;
string pet[1];

int main()
{
    for (int i = 0; i < 10; i++)
        inventory[i] = " ";

    for (int i = 0; i < 1; i++)
        pet[i] = " ";

    for (int i = 0; i < 5; i++)
        monstersData[i] = "false";

    for (int i = 0; i < 5; i++)
        chestData[i] = "false";

    for (int i = 0; i < 1; i++)
        marketData[i] = "false";

    for (int i = 0; i < 10; i++)
        roomData[i] = "false";

    int room = 1;
    char direction;

    string monster;
    string damage;
    string weapon;
    string attack;
    string petRand;
    string currentPet;

    cout << "Welcome to \"The Forgotten Prophecy\"" << endl;
    cout << "You wake up somewhere unknown. Bright green grass and orange trees surround you." << endl;
    cout << "Your memory is foggy and you can't quite remember anything about yourself, or how you got to this mysterious place." << endl;
    cout << "The only path forward is a steep set of ancient stone stairs." << endl;

    while (gameLoop)
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
                cout << "you pick up a key!" << endl;
            inventory[0] = "Key";
            break;
        case 2:
            cout << "You are in 'Room Two', do you wish to go (S)outh towards 'Room Three'? Or (W)est back to 'Room One'" << endl;
            cin >> direction;
            if (direction == 'W' || direction == 'w')
                room = 1;
            if (direction == 'S' || direction == 's')
                if (inventory[0] == "Key")
                {
                    cout << "you unlock the door with the key!" << endl;
                    inventory[0] = " ";
                    room = 3;
                }
                else
                    cout << "the door is locked" << endl;
            break;
        case 3:
            weapon = weaponGen();
            monster = monsterGen();
            attack = attackGen();
            if (chestData[0] != "true")
                cout << "A mysterious (C)hest is to your left." << endl;
            if (chestData[0] == "true")
                cout << "You are in 'Room Three', you can go (S)outh to 'Room Four' (Cave), or (N)orth back to 'Room Two'" << endl;
            cin >> direction;
            if (direction == 'N' || direction == 'n')
                room = 2;
            if (direction == 'S' || direction == 's')
                if (roomData[2] != "false")
                    room = 4;
                else
                    cout << "A wild " << monster << " lurks in the corner of the room! It is blocking the enterance to the Cave." << endl;
                    cout << "The monster" << attack << endl;
            if (chestData[0] == "false" && direction == 'C' || direction == 'c')
                cout << "You open the chest and receive a " << weapon << endl;
            inventory[0] = weapon;
            chestData[0] = "true";
            break;
        case 4:
            petRand = petActions();
            currentPet = petGenerator();
            cout << "You are in 'Room Four' (Cave), you can go (E)ast to 'Room Five', or (N)orth back to 'Room Three'" << endl;
            cout << "A (p)et approaches you, would you like to pet it?" << endl;
            cin >> direction;
            if (direction == 'N' || direction == 'n')
                room = 3;
            if (direction == 'E' || direction == 'e')
                room = 5;
            if (direction == 'P' || direction == 'p')
                cout << "You pet the " << currentPet << petRand << endl;
            petAffinity++;
            cout << "Current pet affinity is: " << petAffinity << endl;
            pet[0] = currentPet;

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

string weaponGen()
{
    string chestItems[] = {"Sword", "Spear", "Trident", "Bow", "Godly Bolt"};

    int numItems = sizeof(chestItems) / sizeof(chestItems[0]);

    srand(time(0));

    int randomIndex = rand() % numItems;

    return chestItems[randomIndex];
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

string attackGen()
{

    string attackItems[] = {" slams you onto the ground", " attacks you", " throws you", " claws you", " punches you"};

    int numItems = sizeof(attackItems) / sizeof(attackItems[0]);

    srand(time(0));

    int randomIndex = rand() % numItems;

    return attackItems[randomIndex];
}

void shop()
{
    int input;
    while (input != '0')
    {
        cout << "----------------------------" << endl;
        cout << "Welcome to the shop" << endl;
        cout << "Items for sale:" << endl;
        cout << "1) Cupcake: $5" << endl;
        cout << "2) Sock: $10" << endl;
        cout << "3) Key: $50" << endl;
        cout << "Your Inventory:" << endl;
        cout << "0 to QUIT" << endl;
        cout << "Your Gold: " << gold << endl;
        for (int i = 0; i < 10; i++)
            cout << shopInventory[i] << " ";
        cout << endl;
        cout << "What would you like to purchase?" << endl;
        cout << "----------------------------" << endl;
        cin >> input;
        if (input == 1)
        {
            if (gold >= 5)
            {
                cout << "You bought the cupcake!" << endl;
                shopInventory[1] = "Cupcake";
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
                shopInventory[2] = "Sock";
                gold -= 10;
            }
        }
        else if (input == 3)
        {
            if (gold > -50)
            {
                cout << "You bought the key!" << endl;
                shopInventory[0] = "Key";
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

void blackMarket()
{
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "----------------------------" << endl;
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "cool" && userPassword == "kid")
        {
            cout << "Welcome to the black market!\n";
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n"
                 << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
        cout << "Too many login attempts! The program will now terminate.";
    }

    cout << "Thank you for logging in.\n";
    cout << "How would you like to proceed \n";
}

string petActions()
{

    string petItems[] = {"Pet: Moo!", "Pet: Scratches behind ear.", "Pet: Wags tail."};

    int numItems = sizeof(petItems) / sizeof(petItems[0]);

    srand(time(0));

    int randomIndex = rand() % numItems;

    return petItems[randomIndex];
}

string petGenerator()
{

    string petgenItems[] = {"Dog", "Dragon", "Bird", "Undead", "Godly Cat"};

    int numItems = sizeof(petgenItems) / sizeof(petgenItems[0]);

    srand(time(0));

    int randomIndex = rand() % numItems;

    return petgenItems[randomIndex];
}

int damageGen()
{
}
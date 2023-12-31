#include <iostream>
#include <windows.h>
#include <string>
#include "data.h"
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
string monstersData[5]; // What monsters has the player defeated?
string chestData[5];    // What chests has the user already opened?
string roomData[10];    // What rooms has the user been in?
string marketData[1];   // Has the user opened the black market yet?
string doorData[5];     // Doors Opened

// Songs
void deathSong();
void victorySong();

// Health Values
int playerHealth = 100;
int monsterHealth = 50;
int bossHealh = 200;

// Other

void blackMarket();

// Pet
string petActions();
string petGenerator();
int petAffinity = 0; // self-explanitory
string pet[1];       // this way I can make sure the player only generates one pet.

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

    for (int i = 0; i < 5; i++)
        doorData[i] = "false";

    for (int i = 0; i < 10; i++)
        shopInventory[i] = " ";

    // initialize all of the lists

    int room = 1;
    char direction;

    string monster;
    int damage;
    string weapon;
    string attack;
    string petRand;
    string currentPet;

    // strings to store the value that my generator functions return.
    cout << "───────────────────────────────────────────────────────────────────────" << endl;
    cout << R"(
__        __   _                          
\ \      / /__| | ___ ___  _ __ ___   ___ 
 \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \
  \ V  V /  __/ | (_| (_) | | | | | |  __/
   \_/\_/ \___|_|\___\___/|_| |_| |_|\___|

    )" << endl;
    Sleep(1000);
    tree();
    Sleep(1000);
    cout << "Welcome to \"The Forgotten Prophecy\"" << endl; // introduction
    Sleep(1000);
    cout << "You wake up somewhere unknown. Bright green grass and orange trees surround you." << endl;
    Sleep(1000);
    cout << "Your memory is foggy and you can't quite remember anything about yourself, or how you got to this mysterious place." << endl;
    Sleep(1000);
    cout << "The only path forward is a steep set of ancient stone stairs." << endl;
    Sleep(1000);
    cout << "Note: All input should be single character. Typing multi-character input could break the game." << endl;
    Sleep(1000);
    cout << "───────────────────────────────────────────────────────────────────────" << endl;

    while (gameLoop)
    {
        switch (room)
        {
        case 1:
            if (roomData[0] != "true")
            {
                cout << "A thick mist coated the grass." << endl;
                Sleep(1000);
                cout << "As you look around, it seems safe to go forward..." << endl;
                Sleep(1000);
            }
            cout << "You are in 'Room One', do you wish to go (E)ast towards 'Room Two'?" << endl;
            Sleep(1000);
            if (inventory[0] != "Key")
                cout << "You see a (K)ey on the floor." << endl;
            cin >> direction;
            if (direction == 'E' || direction == 'e')
                room = 2;
            if (direction == 'K' || direction == 'k')
                cout << "you pick up a key!" << endl;
            if (roomData[0] != "true")
            {
                key();
                roomData[0] = "true";
                inventory[0] = "Key";
            } // This key will be required to open the door in the next room

            cout << "───────────────────────────────────────────────────────────────────────" << endl;
            break;
        case 2:
            if (roomData[1] != "true")
            {
                cout << "Face to face with 2 giant slate doors; a small keyhole in the middle." << endl;
                Sleep(1000);
            }
            cout << "You are in 'Room Two', do you wish to go (S)outh towards 'Room Three'? Or (W)est back to 'Room One'" << endl;
            cin >> direction;
            if (direction == 'W' || direction == 'w')
                room = 1;
            if (direction == 'S' || direction == 's')
                if (inventory[0] == "Key" && roomData[1] != "true")
                {
                    cout << "you unlock the door with the key!" << endl;
                    Sleep(1000);
                    cout << "The ground rumbles as the giant doors creak open..." << endl;
                    inventory[0] = " "; // remove key from inventory
                    roomData[1] = "true";
                    doorData[0] = "true";
                    room = 3;
                }
                else if (roomData[1] == "true" && doorData[0] == "true")
                {
                    room = 3; // if door already open then go straight to room 3
                }
                else
                    cout << "the door is locked" << endl;

            cout << "───────────────────────────────────────────────────────────────────────" << endl;
            break;
        case 3:
            weapon = weaponGen();
            monster = monsterGen();
            attack = attackGen();
            damage = damageGen();
            if (chestData[0] != "true")
                cout << "A mysterious (C)hest is to your left." << endl;
            if (chestData[0] == "true")
            {
                if (monstersData[0] == "false")
                {
                    cout << "This place is awfully dark. You notice a pair of glowing eyes staring in your direction..." << endl;
                    Sleep(1000);
                }
                cout << "You are in 'Room Three', you can go (S)outh to 'Room Four' (Cave), or (N)orth back to 'Room Two'" << endl;
                cout << "Note: You might have to type input twice." << endl;
                Sleep(1000);
            }
            cin >> direction;
            if (direction == 'N' || direction == 'n')
                room = 2;
            if (direction == 'S' || direction == 's' && monstersData[0] == "true")
                room = 4;
            else if (direction == 'S' || direction == 's' && monstersData[0] == "false")
            {
                cout << "You may not pass, there is a monster blocking the entrance!"; // force player to fight monster if they try to avoid it
                Sleep(1000);
            }
            if (chestData[0] == "false" && direction == 'C' || direction == 'c')
            {
                chest();
                cout << "You open the chest and receive a " << weapon << endl;
                inventory[0] = weapon; // store the weapon generated
                chestData[0] = "true"; // so that player can't open the chest twice
                Sleep(1000);
            }
            if (chestData[0] == "true" && monstersData[0] == "false")
            {
                cout << "A wild " << monster << " lurks in the corner of the room! It is blocking the enterance to the Cave." << endl;
                Sleep(1000);
                cout << "Press 0  to attack!" << endl;
            }
            cin >> direction;
            if (direction == '0' || direction == '0' && monstersData[0] == "false") // battle
            {
                Sleep(1000);
                cout << "The monster" << attack << " and does " << damage << " damage!" << endl;
                playerHealth -= damage;
                Sleep(1000);
                cout << "Your health is now " << playerHealth << endl;
                Sleep(1000);
                cout << "You strike down the " << monster << " with your " << weapon << endl;
                cout << "Incredible victory music plays..." << endl;
                victorySong();
                monstersData[0] = "true";
                Sleep(1000);
            }

            cout << "───────────────────────────────────────────────────────────────────────" << endl;
            break;
        case 4:
            petRand = petActions();
            currentPet = petGenerator();
            if (roomData[3] != "true")
            {
                cout << "Your footsteps echo as you walk through the cave. Torches line the stone walls and mysterious crystals liter the floors." << endl;
                Sleep(1000);
            }
            cout << "You are in 'Room Four' (Cave), you can go (E)ast to 'Room Five', or (N)orth back to 'Room Three'" << endl;
            Sleep(1000);
            if (roomData[3] != "true")
            {
                cout << "A (p)et approaches you, would you like to pet it? [Pet it now!]" << endl;
                roomData[3] = "true";
            }
            cin >> direction;
            if (direction == 'N' || direction == 'n')
                room = 3;
            if (direction == 'E' || direction == 'e')
                room = 5;
            if (direction == 'P' || direction == 'p' && pet[0] != currentPet)
            {
                cout << "You pet the " << currentPet << endl;
                Sleep(1000);
                cout << petRand << endl;
                Sleep(1000);
                petAffinity++;
                cout << "Current pet affinity is: " << petAffinity << endl;
                pet[0] = currentPet;
            }

            cout << "───────────────────────────────────────────────────────────────────────" << endl;
            break;
        case 5:
            if (roomData[4] != "true")
            {
                cout << "As you exit the cave, you walk into a vast room with big orange trees and bright red bushes everywhere." << endl;
                Sleep(1000);
            }
            cout << "You are in 'Room Five', you can go (N)orth to 'Room Six', or (W)est back to 'Room Four'" << endl;
            Sleep(1000);
            if (roomData[4] != "true")
            {
                cout << "You spot some food on the ground..." << endl;
                Sleep(2000);
                burger();
                Sleep(1000);
                cout << "Thoughts: I'm starving, maybe I should eat this mysterious (B)urger." << endl;
            }
            cin >> direction;
            if (direction == 'W' || direction == 'w')
                room = 4;
            if (direction == 'N' || direction == 'n')
                room = 6;
            if (direction == 'B' || direction == 'b' && roomData[4] != "true")
            {
                cout << "You feel powered up and some of your wounds from the previous battle are now healed!" << endl;
                playerHealth += 35;
                cout << "Thoughts: Wow that was a good burger!" << endl;
                Sleep(1000);
                cout << "Health is now: " << playerHealth << endl;
                Sleep(1000);
                roomData[4] = "true";
            }

            cout << "───────────────────────────────────────────────────────────────────────" << endl;
            break;
        case 6:
            if (roomData[5] != "true")
            {
                cout << "Rocks are spread out everywhere. A rough wind blows through the air." << endl;
                Sleep(1000);
            }
            cout << "You are in 'Room Six', you can go (E)ast to 'Room Seven', or (S)outh back to 'Room Five'" << endl;
            Sleep(1000);
            if (roomData[5] != "true")
            {
                cout << "There are some (C)oins on the ground!" << endl;
                Sleep(1000);
                coins();
            }
            cin >> direction;
            if (direction == 'E' || direction == 'e')
                room = 7;
            if (direction == 'S' || direction == 's')
                room = 5;
            if (direction == 'C' || direction == 'c' && roomData[5] != "true")
            {
                gold += 200;
                cout << "You now have " << gold << " gold!" << endl;
                roomData[5] = "true";
            }

            cout << "───────────────────────────────────────────────────────────────────────" << endl;
            break;
        case 7:
            if (roomData[5] != "true")
            {
                cout << "You make your way into a smaller, less intimidating room. A tree is in the corner." << endl;
                Sleep(1000);
                roomData[6] = "true";
            }
            cout << "You are in 'Room Seven', you can go (E)ast to 'Room Eight', or (W)est back to 'Room Six'" << endl;
            Sleep(1000);
            if (roomData[6] != "true")
            {
                cout << "There is a (s)hop in the corner!" << endl;
                cout << "Hint: The Girl Crusher Perfume might be useful later on!" << endl;
            }
            cin >> direction;
            if (direction == 'E' || direction == 'e')
                room = 8;
            if (direction == 'W' || direction == 'w')
                room = 6;
            if (direction == 'S' || direction == 's' && roomData[6] != "true")
            {
                market();
                Sleep(1000);
                shop();
                cout << "The shop self destructed" << endl;
                roomData[6] = "true";
            }

            cout << "───────────────────────────────────────────────────────────────────────" << endl;
            break;
        case 8:
            if (roomData[7] != "true")
            {
                cout << "You notice your " << pet[0] << " acting strange..." << endl;
                Sleep(1000);
                roomData[7] = "true";
            }
            cout << "There is nothing strange in sight to warrant this behaviour, so you continue your journey throughout this unknown place..." << endl;
            Sleep(1000);
            cout << "You are in 'Room Eight', you can go (S)outh to 'Room Nine, or (W)est back to 'Room Seven'" << endl;
            cin >> direction;
            if (direction == 'S' || direction == 's')
                room = 9;
            if (direction == 'W' || direction == 'w')
                room = 7;

            cout << "───────────────────────────────────────────────────────────────────────" << endl;
            break;
        case 9:
            if (roomData[8] != "true")
            {
                cout << "This room has nothing special in it. No monsters, no chests, no creatures." << endl;
                Sleep(1000);
                cout << "You start to wonder what the purpose of this place was... Are you dreaming, pehaps?" << endl;
                Sleep(1000);
                roomData[8] = "true";
            }
            cout << "You are in 'Room Nine', you can go North-(E)ast to 'Room 10', or (N)orth back to 'Room Eight'" << endl;
            cin >> direction;
            if (direction == 'E' || direction == 'e')
                room = 10;
            if (direction == 'N' || direction == 'n')
                room = 8;

            cout << "───────────────────────────────────────────────────────────────────────" << endl;
            break;
        case 10:
            cout << "As you walk into what seems to be the final room, you notice that the room is significantly larger than what you've seen before." << endl;
            Sleep(1000);
            cout << "A mysterious fog encircles a tree in the middle of the room." << endl;
            Sleep(1000);
            cout << "You are in 'Room Ten', the ground starts rumbling..." << endl;
            Sleep(2000);
            boss();
            cout << "A boss spawned, fight for your life!" << endl;
            Sleep(1000);
            if (shopInventory[0] == "Girl_Crusher_Perfume") // can only win with the girl crusher perfume
            {
                cout << "Hint: (U)se your Girl Crusher Perfume to completely obliterate the boss!" << endl;
                cin >> direction;
                if (direction == 'U' || direction == 'u')
                {
                    fire();
                    Sleep(1000);
                    cout << "The boss is intoxicated by your sent and explodes into a ball of flames!" << endl;
                    Sleep(1000);
                    cout << "Incredible victory music plays..." << endl;
                    victorySong();
                    cout << "A bright mysterious square of light appears... You walk through and your suddenly back home, like nothing had ever happened" << endl;
                    Sleep(1000);
                    cout << "Was it just a dream? No... It felt too real." << endl;
                    Sleep(1000);
                    cout << "I guess we'll never know" << endl;
                    gameLoop = false;
                }
                else
                {
                    cout << "You fight bravely; with no idea how you got here and you're already fighting an unknown creature with your " << inventory[0] << endl;
                    Sleep(1000);
                    cout << "No matter how hard you try, you can not scratch the boss... You begint to accept your fate" << endl;
                    Sleep(1000);
                    cout << "The boss grabs you and squeezes you till you turn into a donut and perish..." << endl;
                    Sleep(1000);
                    death();
                    Sleep(1000);
                    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_BLUE);
                    cout << "You failed to escape the terrors of this mysterious place..." << endl;
                    Sleep(1000);
                    cout << "Scary death music plays..." << endl;
                    deathSong();
                    gameLoop = false;
                }
            }

            cout << "───────────────────────────────────────────────────────────────────────" << endl;
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
        cout << "3) Girl Crusher Perfume: $50" << endl;
        cout << "Your Inventory:" << endl;
        cout << "0 to QUIT" << endl;
        cout << "Your Gold: " << gold << endl;
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
            else
                cout << "You dont have enough gold!" << endl;
        }
        else if (input == 3)
        {
            if (gold >= 50)
            {
                cout << "You bought the Girl Crusher Perfume!" << endl;
                shopInventory[0] = "Girl_Crusher_Perfume";
                gold -= 50;
            }
            else
                cout << "You dont have enough gold!" << endl;
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
    int damageItems[] = {10, 20, 30, 40, 50};

    int numItems = sizeof(damageItems) / sizeof(damageItems[0]);

    srand(time(0));

    int randomIndex = rand() % numItems;

    return damageItems[randomIndex];
}
#include <iostream>
#include <Windows.h>
using namespace std;

bool gameLoop = true;

// Gens
string monsterGen();
string lootGen();

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
            cout << "you're in room 1, you can go (E)ast" << endl;
            cin >> direction;
            if (direction == 'E')
                room = 2;
            break;
        case 2:
            cout << "you're in room 2, you can go (W)est or (S)outh" << endl;
            cin >> direction;
            if (direction == 'W')
                room = 1;
            if (direction == 'S')
                room = 3;
            break;
        case 3:
            cout << "you're in room 3, you can go (N)orth or (S)outh" << endl;
            cin >> direction;
            if (direction == 'N')
                room = 2;
            if (direction == 'S')
                room = 4;
            break;
        case 4:
            cout << "you're in room 4, you can go (E)ast or (N)orth" << endl;
            cin >> direction;
            if (direction == 'N')
                room = 3;
            if (direction == 'E')
                room = 5;
            break;
        case 5:
            cout << "you're in room 5, you can go (W)est" << endl;
            cin >> direction;
            if (direction == 'W')
                room = 4;
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
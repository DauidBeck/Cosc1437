
#include <iostream>
#include <string>
#include <iostream>
#include <list>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
bool cont = 1;
struct player
{

    string playerName; //Who is the player
    int lives;
    int coins;

    int level; //Where is the player
    int x_position;
    int y_position;

    int special; //Is the player special - if so what items
    bool big;
    string special_items[6];
};

// Initilize the struct variables
void initilaize_variables(player &character, string myName)
{
    character.playerName = myName;
    character.lives = 3;
    character.coins = 0;

    character.level = 0;
    character.x_position = 0;
    character.y_position = 0;

    character.special = 0;
    character.big = false;
    character.special_items[0] = "Nothing";
    character.special_items[1] = "Hammer";
    character.special_items[2] = "Red Mushroom";
    character.special_items[3] = "Green Mushroom";
    character.special_items[4] = "Cape";
    character.special_items[5] = "Star";
}

// Restart the character
void restart(player &character)
{
    character.lives = 3;
    character.coins = 0;
    character.special = 0;
    character.big = false;
}

//Print character
void printCharacter(player &character)
{

    // Print State
    cout << "\t Name: \t\t\t" << character.playerName << "\n";
    cout << "\t Lives: \t\t" << character.lives << "\n";
    cout << "\t Coins: \t\t" << character.coins << "\n";

    // Print Position
    cout << "\t Level: \t\t" << character.level << "\n";
    cout << "\t X Position: \t\t" << character.x_position << "\n";
    cout << "\t Y Position: \t\t" << character.y_position << "\n";

    // Print Special Items
    cout << "\t Character big?: \t" << character.big << "\n";
    cout << "\t Character special?: \t" << character.special << "\n";
    for (int i = 0; i < 5; i++)
        cout << "\t Special_Item[" << i << "]: \t" << character.special_items[i] << "\n";
}
void setPos(player &character, int x, int y)
{
    character.x_position = x;
    character.y_position = y;
}

void getGameState(player &character)
{
    // Print State
    cout << "\t Name: \t\t\t" << character.playerName << "\n";
    cout << "\t Lives: \t\t" << character.lives << "\n";
    cout << "\t Coins: \t\t" << character.coins << "\n";

    // Print Position
    cout << "\t Level: \t\t" << character.level << "\n";
    cout << "\t X Position: \t\t" << character.x_position << "\n";
    cout << "\t Y Position: \t\t" << character.y_position << "\n";

    // Print Special Items
    cout << "\t Character big?: \t" << character.special << "\n";
    cout << "\t Character special?: \t" << character.big << "\n";
}
string toLowerCase(player &character, string s)
{
    string PostProcess = "";
    for (int c = 0; c < s.length(); c++)
    {
        char charAtX = s[c];
        PostProcess += tolower(s[c]);
    }
    return PostProcess;
}

void checkLife(player &character)
{

    if (character.lives == -1)
    {

        cout << "GAME OVER.\n Continue? (0 or 1)" << endl;
        cin >> cont;
        if (cont == 1)
        {
            restart(character);
        }
        if (cont == 0)
        {
            cout << "exiting";
        }
    }
}
void takeDamage(player &character)
{
    if (character.big == 0 && character.special == 0)
    {
        character.lives--;
        checkLife(character);
    }
    if (character.big == 1 || character.special == 1)
    {
        character.big = 0;
        character.special = 0;
    }
}

void Die(player &character)
{
    character.lives--;
    checkLife(character);
}

void collectCoins(player &character, int x)
{
    character.coins += x;

    if (character.coins >= 100)
    {
        character.lives++;
        character.coins = character.coins - 100;
    }
}

void collectPowerup(player &character, int ID)
{
    if (character.big == 0)
    {
        character.big = 1;
        character.special = ID;
        cout << "Setting character special ID to " << ID << endl;
    }
    else if (character.big == 1)
    {
        character.big = 1;
        character.special = ID;
        cout << "Setting character special ID to " << ID << endl;
    }
}

void checkTime(player &character, int time)
{
    if (time >= 0)
    {
        character.lives--;
        cout << "Time ran out!" << endl;
    }
}
void setLevel(player &character, int level)
{
    character.level = level;
}

void parseCommand(player &character, string command)
{
    string cmd = command;
    int x;
    int y;

    //int len = command.length();
    if (command == "die")
    {
        Die(character);
    }
    if (command == "collectpowerup")
    {
        cout << "What is the ID of the powerup?" << endl;
        cin >> x;
        collectPowerup(character, x);
    }
    if (command == "collectcoins")
    {
        cout << "How many coins?" << endl;
        cin >> x;
        collectCoins(character, x);
    }
    if (command == "setpos")
    {
        cout << "What x position?" << endl;
        cin >> x;
        cout << "What y position?" << endl;
        cin >> y;
        setPos(character, x, y);
    }
    if (command == "getgamestate")
    {
        getGameState(character);
    }
    if (command == "exit")
    {
        cont = 0;
    }
    if (command == "setlevel")
    {
        cout << "What level?" << endl;
        cin >> x;
        setLevel(character, x);
    }
    if (command == "takedamage")
    {
        takeDamage(character);
    }
    if (command == "collect1up")
    {
        character.lives++;
    }
    if(command == "help")
    {
        cout<<"valid commands:\n Help - Displays this page\n CollectPowerup\nsetLevel\nCollect1up\ntakeDamage\nexit\ngetGameState\nsetPos\nCollectPoints\ndie"<<endl;
    }
}

int main()
{
    player Mario;
    player Luigi;
    initilaize_variables(Mario, "Mario");
    initilaize_variables(Luigi, "Luigi");
    int time = 500;
    cont = true;
    string command;

    while (cont)
    // string activePlayer = "Luigi";
    {
        cout << "What would you like to do?" << endl;
        cin >> command;
        //command = tolowerCase(Mario, command);
        command = toLowerCase(Luigi, command);
        parseCommand(Luigi, command);
        //toLowerCase(Mario, command);
    }
    //printCharacter(Luigi);
    cout << "\n Final Game State\n";
    getGameState(Luigi);

    return 0;
}

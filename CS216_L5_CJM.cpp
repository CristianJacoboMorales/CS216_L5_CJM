//Cristian Jacobo Morales
//CS 216
//Lab #5
//Section #15562

#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_CREATURES = 10;

// Enum for menu options
enum MenuOptions { PLAY, QUIT };

// Creature class
class Creature {
private:
    string name;
    string type;
    int strength;
    int health;

public:
    Creature(const string& name = "", const string& type = "", int strength = 0, int health = 0) {
        setCreature(name, type, strength, health);
    }

    void setCreature(const string& name, const string& type, int strength, int health) {
        this->name = name;
        this->type = type;
        this->strength = strength;
        this->health = health;
    }

    void takeDamage(int damage) {
        health = max(0, health - damage);
    }
    bool isAlive() const { return health > 0; }

    string toString() const {
        stringstream ss;
        ss << left << setw(20) << name << left << setw(15) << type
            << right << setw(10) << strength << right << setw(10) << health;
        return ss.str();
    }

    int getStrength() const { return strength; }
    int getHealth() const { return health; }
    const string& getName() const { return name; }
};

// Army class
class Army {
private:
    string name;
    array<Creature, MAX_CREATURES> creatures;
    int size;

public:
    Army(const string& name, int size) : name(name), size(size) {
        string creatureNames[MAX_CREATURES] = {
            "Jo the elf", "Lee the demon", "Mara the macara", "Ceffyl the swift",
            "Nuggle the trickster", "Bahamut the mighty", "Zara the brave",
            "Kira the clever", "Owen the strong", "Vera the wise"
        };
        string creatureTypes[4] = { "macara", "ceffyl", "nuggle", "bahamut" };

        for (int i = 0; i < size; i++) {
            creatures[i] = Creature(creatureNames[i], creatureTypes[rand() % 4],
                rand() % 50 + 1, rand() % 100 + 1);
        }
    }

    void printArmyDetails() const {
        cout << left << setw(20) << "Name" << left << setw(15) << "Type"
            << right << setw(10) << "Strength" << right << setw(10) << "Health\n";

        for (int i = 0; i < size; i++)
            cout << creatures[i].toString() << '\n';
    }

    int getTotalHealth() const {
        int totalHealth = 0;
        for (const auto& creature : creatures)
            totalHealth += creature.getHealth();
        return totalHealth;
    }

    Creature& getCreature(int index) { return creatures[index]; }
    const string& getName() const { return name; }
    int getSize() const { return size; }
};

// Game class
class Game {
private:
    Army army1;
    Army army2;

public:
    Game(const string& name1, int size1, const string& name2, int size2)
        : army1(name1, size1), army2(name2, size2) {}

    void battle() {
        cout << "Battle begins between " << army1.getName() << " and " << army2.getName() << "!\n";

        // Battle output
        cout << left << setw(20) << "Attacker" << setw(10) << "Damage" << setw(10) << "Army"
            << setw(20) << "Defender" << setw(20) << "Defender's Health" << setw(10) << "Army\n";

        for (int i = 0; i < army1.getSize(); i++) {
            Creature& creature1 = army1.getCreature(i);
            Creature& creature2 = army2.getCreature(i);

            while (creature1.isAlive() && creature2.isAlive()) {
                // Creature 1 attacks Creature 2
                int damage1 = creature1.getStrength();
                creature2.takeDamage(damage1);
                cout << left << setw(20) << creature1.getName()
                    << setw(10) << damage1
                    << setw(10) << army1.getName()
                    << setw(20) << creature2.getName()
                    << setw(20) << creature2.getHealth()
                    << setw(10) << army2.getName() << '\n';

                if (!creature2.isAlive()) break;

                // Creature 2 attacks Creature 1
                int damage2 = creature2.getStrength();
                creature1.takeDamage(damage2);
                cout << left << setw(20) << creature2.getName()
                    << setw(10) << damage2
                    << setw(10) << army2.getName()
                    << setw(20) << creature1.getName()
                    << setw(20) << creature1.getHealth()
                    << setw(10) << army1.getName() << '\n';
            }

            if (!creature1.isAlive()) cout << creature1.getName() << " has been defeated!\n";
            if (!creature2.isAlive()) cout << creature2.getName() << " has been defeated!\n";
        }

        // Health of each army
        cout << "\n" << army1.getName() << " total health: " << army1.getTotalHealth() << '\n';
        cout << army2.getName() << " total health: " << army2.getTotalHealth() << '\n';

        // Winner
        if (army1.getTotalHealth() > army2.getTotalHealth())
            cout << army1.getName() << " wins!\n";
        else if (army2.getTotalHealth() > army1.getTotalHealth())
            cout << army2.getName() << " wins!\n";
        else
            cout << "It's a tie!\n";
    }
};

// Display Menu
MenuOptions displayMenu() {
    int choice;
    cout << "\nMenu:\n1. Play\n2. Quit\nSelect an option: ";
    cin >> choice;
    return (choice == 1) ? PLAY : QUIT;
}

// Function to handle the game play
void playGame() {
    string armyName1, armyName2;
    int armySize1, armySize2;

    cout << "Enter the name for Army 1: "; cin >> armyName1;
    cout << "Enter the size for Army 1 (up to " << MAX_CREATURES << "): "; cin >> armySize1;
    cout << "Enter the name for Army 2: "; cin >> armyName2;
    cout << "Enter the size for Army 2 (up to " << MAX_CREATURES << "): "; cin >> armySize2;

    if (armySize1 <= MAX_CREATURES && armySize2 <= MAX_CREATURES) {
        Game game(armyName1, armySize1, armyName2, armySize2);
        game.battle();
    }
    else {
        cout << "Army sizes must be less than or equal to " << MAX_CREATURES << ".\n";
    }
}

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator
    MenuOptions choice;

    do {
        choice = displayMenu();
        if (choice == PLAY) playGame();
    } while (choice != QUIT);

    cout << "Quitting the game.\n";
    return 0;
}

/* Output: Menu:

1. Play
2. Quit
Select an option: 1

Enter the name for Army 1: ry
Enter the size for Army 1 (up to 10): 3
Enter the name for Army 2: kr
Enter the size for Army 2 (up to 10): 4

Battle begins between ry and kr!

Attacker            Damage    Army      Defender            Defender's Health   Army      
Jo the elf          46        ry        Jo the elf          7                   kr        
Jo the elf          38        kr        Jo the elf          8                   ry        
Jo the elf          46        ry        Jo the elf          0                   kr        
Jo the elf has been defeated!
Lee the demon       32        ry        Lee the demon       11                  kr        
Lee the demon       34        kr        Lee the demon       0                   ry        
Lee the demon has been defeated!
Mara the macara     12        ry        Mara the macara     72                  kr        
Mara the macara     37        kr        Mara the macara     0                   ry        
Mara the macara has been defeated!

ry total health: 8
kr total health: 131
kr wins!
*/

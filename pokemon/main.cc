#include <iostream>
#include <iomanip>
#include <string>

class Pokemon {
private:
    //Class Pokemon members
    std::string name;
    std::string type;
    int maxHP;
    std::string skillNames[4];
    std::string skillTypes[4];
    int skillDamages[4];
    int maxTries[4];
    int numOfTries[4];

    Pokemon* pairedPokemon;

public:
    // Constructor
    Pokemon(std::string name, std::string type, int maxHP, std::string skills[][5])
        : name(name), type(type), maxHP(maxHP), pairedPokemon(nullptr) {
        for (int i = 0; i < 4; ++i) {
            skillNames[i] = skills[i][0];
            skillTypes[i] = skills[i][1];
            skillDamages[i] = std::stoi(skills[i][2]);
            maxTries[i] = std::stoi(skills[i][3]);
            numOfTries[i] = std::stoi(skills[i][4]); 
        }
    }

    // Getter for maxHP
    int getMaxHP() const {
        return maxHP;
    }

    //Getter for name
    std::string getName() const {
        return name;
    }

    // Display Pokemon information
    void displayInfo(bool isCurrentPlayer) const {
        std::cout << "+-------------------------------------------------------------+\n";
        std::cout << "| " << std::left << std::setw(59) << "2023000000 OOP Computer Science" << " |\n";
        std::cout << "+------------------------------+------------------------------+\n";

        // Check if it's the current player's turn
        if (isCurrentPlayer) {
            std::cout << "| " << std::left << std::setw(29) << name + " (*)" << "| " << std::setw(28) << std::left << pairedPokemon->name << " |\n";
            std::cout << "| " << std::left << std::setw(29) << "Type: " + type << "| Type: " << std::setw(22) << std::left << (pairedPokemon ? pairedPokemon->type : "") << " |\n";
            std::cout << "| " << std::left << std::setw(29) << "HP: " + std::to_string(maxHP) << "| HP: " << std::setw(24) << std::left << (pairedPokemon ? pairedPokemon->maxHP : 0) << " |\n";
            std::cout << "+------------------------------+------------------------------+\n";
                for (int i = 0; i < 4; ++i) {
                    std::cout << "| (" << i << ") " << std::left << std::setw(24) << skillNames[i] << " | (" << i << ") " << std::setw(24) << (pairedPokemon ? pairedPokemon->skillNames[i] : "") << " |\n";
                    std::cout << "|     - Type: " << std::left << std::setw(16) << skillTypes[i] << " |     - Type: " << std::setw(16) << (pairedPokemon ? pairedPokemon->skillTypes[i] : "") << " |\n";
                    std::cout << "|     - Damage: " << std::left << std::setw(14) << skillDamages[i] << " |     - Damage: " << std::setw(14) << (pairedPokemon ? pairedPokemon->skillDamages[i] : 0) << " |\n";
                    std::cout << "|     - Count: " << std::left << std::setw(15) << std::to_string(maxTries[i]) + "(" + std::to_string(numOfTries[i]) + ")" << " |     - Count: " << std::setw(16) << std::to_string((pairedPokemon ? pairedPokemon->maxTries[i] : 0)) + "(" + std::to_string((pairedPokemon ? pairedPokemon->numOfTries[i] : 0)) + ")" << "|\n";
            }
        } else {
            std::cout << "| " << std::left << std::setw(29) << pairedPokemon->name << "| " << std::setw(28) << std::left << name + " (*)" << " |\n";
            std::cout << "| " << std::left << std::setw(29) << "Type: " + (pairedPokemon ? pairedPokemon->type : "") << "| Type: " << std::setw(22) << std::left << type << " |\n";
            std::cout << "| " << std::left << std::setw(29) << "HP: " + std::to_string((pairedPokemon ? pairedPokemon->maxHP : 0)) << "| HP: " << std::setw(24) << std::left << maxHP << " |\n";
            std::cout << "+------------------------------+------------------------------+\n";
                for (int i = 0; i < 4; ++i) {
                    std::cout << "| (" << i << ") " << std::left << std::setw(24) << (pairedPokemon ? pairedPokemon->skillNames[i] : "") << " | (" << i << ") " << std::setw(24) << skillNames[i] << " |\n";
                    std::cout << "|     - Type: " << std::left << std::setw(16) << (pairedPokemon ? pairedPokemon->skillTypes[i] : "") << " |     - Type: " << std::setw(16) << skillTypes[i] << " |\n";
                    std::cout << "|     - Damage: " << std::left << std::setw(14) << (pairedPokemon ? pairedPokemon->skillDamages[i] : 0) << " |     - Damage: " << std::setw(14) << skillDamages[i] << " |\n";
                    std::cout << "|     - Count: " << std::left << std::setw(15) << std::to_string((pairedPokemon ? pairedPokemon->maxTries[i] : 0)) + "(" + std::to_string((pairedPokemon ? pairedPokemon->numOfTries[i] : 0)) + ")" << " |     - Count: " << std::setw(16) << std::to_string(maxTries[i]) + "(" + std::to_string(numOfTries[i]) + ")" << "|\n";
            }

        }

        std::cout << "+------------------------------+------------------------------+\n";
    }

    // Check the effectiveness Function
    std::string getTypeEffectiveness(const std::string& attackerType, const std::string& defenderType) const {
        if (attackerType == "Ground") {
            if (defenderType == "Electric" || defenderType == "Fire") {
                return "super effective";
            } else if (defenderType == "Glass") {
                return "not very effective";
            }
        } else if (attackerType == "Electric") {
            if (defenderType == "Water") {
                return "super effective";
            } else if (defenderType == "Ground" || defenderType == "Electric" || defenderType == "Glass") {
                return "not very effective";
            }
        } else if (attackerType == "Water") {
            if (defenderType == "Ground" || defenderType == "Fire") {
                return "super effective";
            } else if (defenderType == "Water" || defenderType == "Glass") {
                return "not very effective";
            }
        } else if (attackerType == "Glass") {
            if (defenderType == "Glass") {
                return "super effective";
            } else if (defenderType == "Fire" || defenderType == "Ground" || defenderType == "Glass") {
                return "not very effective";
            }
        } else if (attackerType == "Fire") {
            if (defenderType == "Glass") {
                return "super effective";
            } else if (defenderType == "Water" || defenderType == "Fire") {
                return "not very effective";
            }
        }

        // Default case
        return "effective";
    }

    // Attack Function
    void Attack(int skillChoice) {
        if (skillChoice < 0 || skillChoice >= 4) {
            std::cout << "Invalid skill choice.\n";
        }
        // Check if the Pokemon has run out of tries for this skill
        else if (maxTries[skillChoice] == 0) {
            std::cout << name << " failed to perform " << skillNames[skillChoice] << ".\n";
            std::cout << std::endl;
        }

        // Showing the name used skill
        else {
            std::cout << name << " used " << skillNames[skillChoice] << ".\n";

            // Calculate the damage to be dealt
            int damageDealt = skillDamages[skillChoice];

            // Adjust damage based on type effectiveness
            std::string effectiveness = getTypeEffectiveness(skillTypes[skillChoice], pairedPokemon->type);
            if (effectiveness == "super effective") {
                damageDealt += 5;
            } else if (effectiveness == "not very effective") {
                damageDealt -= 3;
            }

            // Reduce the opponent's HP only if the attack was successful
            pairedPokemon->maxHP -= damageDealt;

            // Ensure that opponent's HP doesn't go below 0
            if (pairedPokemon->maxHP < 0) {
                pairedPokemon->maxHP = 0;
            }

            // Update the opponent's pairedPokemon pointer
            pairedPokemon->pairedPokemon = this;

            std::cout << "The attack was " << effectiveness << ".\n";
            std::cout << std::endl;

            // Decrease the number of tries for this skill
            maxTries[skillChoice]--;

            // Update the opponent's pairedPokemon pointer
            pairedPokemon->pairedPokemon = this;
        }
    }

    // Check the Over Battle Fuction
    bool isBattleOver() const {
        return maxHP <= 0;
    }

    // Set opponent of the Pokemon by pointer
    void setPair(Pokemon& pairedPokemon) {
        // Swap pair
        this->pairedPokemon = &pairedPokemon;
        pairedPokemon.pairedPokemon = this;
    }

};

int main() {
    // Define Pokemon data
    std::string pikachuSkills[][5] = {
        {"Tackle", "Normal", "4", "5", "5"},
        {"Glass Knot", "Glass", "8", "5", "5"},
        {"Thunderbolt", "Electric", "10", "5", "5"},
        {"Megabolt", "Electric", "15", "3", "3"}
    };

    std::string dratiniSkills[][5] = {
        {"Wrap", "Normal", "4", "10", "10"},
        {"Aqua Tail", "Water", "3", "5", "5"},
        {"Water Pulse", "Water", "13", "2", "2"},
        {"Hyper Beam", "Normal", "20", "1", "1"}
    };

    std::string eeveeSkills[][5] = {
        {"Tackle", "Normal", "4", "5", "5"},
        {"Sand Attack", "Ground", "8", "3", "3"},
        {"Bite", "Normal", "12", "3", "3"},
        {"Rain Dance", "Water", "15", "1", "1"}
    };

    std::string charmanderSkills[][5] = {
        {"Tackle", "Normal", "4", "5", "5"},
        {"Flamethrower", "Fire", "11", "5", "5"},
        {"Dig", "Ground", "7", "5", "5"},
        {"Heat Wave", "Fire", "14", "5", "5"}
    };

    std::string palkiaSkills[][5] = {
        {"Hydro Pump", "Water", "12", "10", "10"},
        {"Earth Power", "Ground", "15", "10", "10"},
        {"Surf", "Water", "13", "10", "10"},
        {"Spatial Rend", "Normal", "30", "10", "10"}
    };

    // Create Pokemon objects
    Pokemon pokemonList[] = {
        Pokemon("Pikachu", "Electric", 35, pikachuSkills),
        Pokemon("Dratini", "Water", 41, dratiniSkills),
        Pokemon("Eevee", "Normal", 55, eeveeSkills),
        Pokemon("Charmander", "Fire", 39, charmanderSkills),
        Pokemon("Palkia", "Water", 90, palkiaSkills)
    };

    // Choose two Pokemon for the battle
    int firstPokemonIndex, secondPokemonIndex;

    std::cout << "Choose a Pokemon (0~4): ";
    std::cin >> firstPokemonIndex;

    // Validate the input
    while (firstPokemonIndex < 0 || firstPokemonIndex >= 5) {
        std::cout << "Invalid input. Choose a Pokemon (0~4): ";
        std::cin >> firstPokemonIndex;
    }

    std::cout << "Choose another Pokemon (0~4): ";
    std::cin >> secondPokemonIndex;

    // Validate the input
    while (secondPokemonIndex < 0 || secondPokemonIndex >= 5 || secondPokemonIndex == firstPokemonIndex) {
        std::cout << "Invalid input. Choose another Pokemon (0~4): ";
        std::cin >> secondPokemonIndex;
    }

    // Pair up the selected Pokemon for display
    pokemonList[firstPokemonIndex].setPair(pokemonList[secondPokemonIndex]);
    pokemonList[secondPokemonIndex].setPair(pokemonList[firstPokemonIndex]);

    // Variable to represent turn
    int firstPlayerIndex = firstPokemonIndex;
    int secondPlayerIndex = secondPokemonIndex;

    // Console of battle
    while (!pokemonList[firstPlayerIndex].isBattleOver() && !pokemonList[secondPlayerIndex].isBattleOver()) {
        // Display information for the current Player
        pokemonList[firstPlayerIndex].displayInfo(true);

        // Prompt for skill choice
        int skillChoice;
        std::cout << "Choose a skill (0~3): ";
        std::cin >> skillChoice;

        // Validate the input
        while (skillChoice < 0 || skillChoice >= 4) {
            std::cout << "Invalid skill choice. Choose a skill (0~3): ";
            std::cin >> skillChoice;
        }

        // Perform the attack for the current player
        pokemonList[firstPlayerIndex].Attack(skillChoice);

        if (pokemonList[secondPlayerIndex].getMaxHP() <= 0) {
            break;
        } 

        // Display information for the opponent Player
        pokemonList[secondPlayerIndex].displayInfo(false);

        // Prompt for skill choice
        std::cout << "Choose a skill (0~3): ";
        std::cin >> skillChoice;

        // Validate the input
        while (skillChoice < 0 || skillChoice >= 4) {
            std::cout << "Invalid skill choice. Choose a skill (0~3): ";
            std::cin >> skillChoice;
        }

        // Perform the attack for the opponent player
        pokemonList[secondPlayerIndex].Attack(skillChoice);
    }
        // Show the result of who is the winner
        if (pokemonList[firstPlayerIndex].getMaxHP() > 0 && pokemonList[secondPlayerIndex].getMaxHP() == 0) {
            std::cout << "===============================================================\n";
            std::cout << "Match Result: " << pokemonList[firstPlayerIndex].getName() << " defeats " << pokemonList[secondPlayerIndex].getName() << std::endl;
        } else if (pokemonList[secondPlayerIndex].getMaxHP() > 0 && pokemonList[firstPlayerIndex].getMaxHP() == 0) {
            std::cout << "===============================================================\n";
            std::cout << "Match Result: " << pokemonList[secondPlayerIndex].getName() << " defeats " << pokemonList[firstPlayerIndex].getName() << std::endl;
        }
        return 0;
}
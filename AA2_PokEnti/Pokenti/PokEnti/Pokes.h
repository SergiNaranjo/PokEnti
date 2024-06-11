#pragma once
#include "Util.h"
#include "Ash.h"
#include "Combat.h"
#include "SceneManager.h"
#include "Map.h"
#include "GameOver.h"
#include <cstdlib>

struct Area {
    int startX; 
    int startY;
    int endX; 
    int endY;
};

enum class Pokes{
    RATTATA, 
    PIDGEY, 
    CATERPIE,
    MAGIKARP, 
    PIKACHU,
    COUNT
};

const char* PokeToString(Pokes poke) {

    switch (poke) {
    case Pokes::RATTATA: return "RATTATA";
    case Pokes::PIDGEY: return "PIDGEY";
    case Pokes::CATERPIE: return "CATERPIE";
    case Pokes::MAGIKARP: return "MAGIKARP";
    case Pokes::PIKACHU: return "PIKACHU";
    }
}

void GenerateRandomPokes() {
    srand(time(NULL));
    int randomIndex = rand() % static_cast<int>(Pokes::COUNT);
    Pokes randomPoke = static_cast<Pokes>(randomIndex);


}

void GeneratePokeballs(char** map, Area& area)
{
    for (int i = 0; i < MIN_POKES; ++i)
    {
        int randX = area.startX + rand() % (area.endX - area.startX + 1);
        int randY = area.startY + rand() % (area.endY - area.startY + 1);

        if (map[randY][randX] == ' ')
        {
            map[randY][randX] = POKEBALL;
        }
        else
        {
            --i;
        }
    }
}

void GenerateMewtwo(char** map, Ash ashPosition) {
    
    int startX2 = MAP_WIDTH/2 +1;
    int startY2 = MAP_HEIGHT/2 + 1;
    int endX2 = MAP_WIDTH - 1;
    int endY2 = MAP_HEIGHT - 1;

        int randX = startX2 + rand() % (endX2 - startX2 + 1);
        int randY = startY2 + rand() % (endY2 - startY2 + 1);

        if(map[randX][randY] == ' ') {
            map[randX][randY] = MEWTWO;
        }
        if (map[ashPosition.x][ashPosition.y] == map[randY][randX] && GetAsyncKeyState(VK_SPACE))
        {
            CombatOptions();
        }
    
}

void GeneratePokes(char** map, Area& area, Ash ashPosition)
{
    int randX = area.startX + rand() % (area.endX - area.startX + 1);
    int randY = area.startY + rand() % (area.endY - area.startY + 1);

    if (map[randY][randX] == ' ')
    {
        map[randY][randX] = POKES;
    }
    if (map[ashPosition.x][ashPosition.y] == map[randY][randX] && GetAsyncKeyState(VK_SPACE))
    {
        CombatOptions();
    }
}

void ReGeneratePokes(char** map, const Area& area) {
    while (true) {
        int randX = area.startX + rand() % (area.endX - area.startX + 1);
        int randY = area.startY + rand() % (area.endY - area.startY + 1);

        if (map[randY][randX] == ' ')
        {
            map[randY][randX] = POKES;
            break;
        }
    }
}

void CapturePokeballs(Ash ashPosition, char** map, int& pokeballs, SceneManager currentScene, Area& area)
{
  
    if (ashPosition.y > 0 && map[ashPosition.y - 1][ashPosition.x] == POKEBALL)
    {
        map[ashPosition.y - 1][ashPosition.x] = ' ';
        pokeballs++;
    }
    if (ashPosition.y < MAP_HEIGHT - 1 && map[ashPosition.y + 1][ashPosition.x] == POKEBALL)
    {
        map[ashPosition.y + 1][ashPosition.x] = ' ';
        pokeballs++;
    }
    if (ashPosition.x > 0 && map[ashPosition.y][ashPosition.x - 1] == POKEBALL)
    {
        map[ashPosition.y][ashPosition.x - 1] = ' ';
        pokeballs++;
    }
    if (ashPosition.x < MAP_WIDTH - 1 && map[ashPosition.y][ashPosition.x + 1] == POKEBALL)
    {
        map[ashPosition.y][ashPosition.x + 1] = ' ';
        pokeballs++;
    }
}

void CapturePokes(Ash ashPosition, char** map, int& pokedex, int& pokeballs, SceneManager currentScene, Area& area)
{
    bool capturedPokes = false;
    bool pokeAlive = true;
    int actualHealth = POKES_HEALTH;
    srand(time(NULL));
    int randomIndex = rand() % static_cast<int>(Pokes::COUNT);
    Pokes randomPoke = static_cast<Pokes>(randomIndex);

    if (pokeballs > 0) {
     
            if (ashPosition.y > 0 && map[ashPosition.y - 1][ashPosition.x] == POKES)
            {
                while (pokeAlive) {
                    std::cout << "You found a wild " << PokeToString(randomPoke) << std::endl;
                    std::cout << actualHealth << std::endl;
                    CombatOptions();

                    int combatDecision;
                    std::cin >> combatDecision;


                    if (combatDecision == 1)
                    {

                        if (actualHealth > 0) {
                            actualHealth -= PIKACHU_ATACK;
                        }
                        else if (actualHealth == 0) {
                            map[ashPosition.y - 1][ashPosition.x] = ' ';
                            pokeAlive = false;
                        }

                    }
                    else if (combatDecision == 2)
                    {
                        map[ashPosition.y - 1][ashPosition.x] = ' ';
                        pokedex++;
                        std::cout << pokedex;
                        pokeballs--;
                        std::cout << pokeballs;
                        pokeAlive = false;
                    }
                    else if (combatDecision == 3)
                    {
                        currentScene.currentScene = Scenes::MAP; 
                        pokeAlive = false;
                    }
                    capturedPokes = true;
                }
            }
            if (ashPosition.y < MAP_HEIGHT - 1 && map[ashPosition.y + 1][ashPosition.x] == POKES)
            {
                while (pokeAlive) {
                    std::cout << "You found a wild " << PokeToString(randomPoke) << std::endl;
                    std::cout << actualHealth << std::endl;
                    CombatOptions();

                    int combatDecision;
                    std::cin >> combatDecision;


                    if (combatDecision == 1)
                    {
                        if (actualHealth > 0) {
                            actualHealth -= PIKACHU_ATACK;
                        }
                        else if (actualHealth == 0) {
                            map[ashPosition.y + 1][ashPosition.x] = ' ';
                            pokeAlive = false;
                        }
                    }

                    else if (combatDecision == 2)
                    {
                        map[ashPosition.y + 1][ashPosition.x] = ' ';
                        pokedex++;
                        std::cout << pokedex;
                        pokeballs--;
                        std::cout << pokeballs;
                        pokeAlive = false;
                    }
                    else if (combatDecision == 3)
                    {
                        currentScene.currentScene = Scenes::MAP;
                        pokeAlive = false;
                    }
                    capturedPokes = true;
                }
            }
            if (ashPosition.x > 0 && map[ashPosition.y][ashPosition.x - 1] == POKES)
            {
                while (pokeAlive) {
                    std::cout << "You found a wild " << PokeToString(randomPoke) << std::endl;
                    std::cout << actualHealth << std::endl;
                    CombatOptions();

                    int combatDecision;
                    std::cin >> combatDecision;

                    if (combatDecision == 1)
                    {
                        if (actualHealth > 0) {
                            actualHealth -= PIKACHU_ATACK;
                        }
                        else if (actualHealth == 0) {
                            map[ashPosition.y][ashPosition.x - 1] = ' ';
                            pokeAlive = false;
                        }
                    }
                    else if (combatDecision == 2)
                    {
                        map[ashPosition.y][ashPosition.x - 1] = ' ';
                        pokedex++;
                        std::cout << pokedex;
                        pokeballs--;
                        std::cout << pokeballs;
                        pokeAlive = false;
                    }
                    else if (combatDecision == 3)
                    {
                        currentScene.currentScene = Scenes::MAP;
                        pokeAlive = false;
                    }
                    capturedPokes = true;
                }
            }
            if (ashPosition.x < MAP_WIDTH - 1 && map[ashPosition.y][ashPosition.x + 1] == POKES)
            {
                while (pokeAlive) {
                    std::cout << "You found a wild " << PokeToString(randomPoke) << std::endl;
                    std::cout << actualHealth << std::endl;
                    CombatOptions();

                    int combatDecision;
                    std::cin >> combatDecision;

                    if (combatDecision == 1)
                    {
                        if (actualHealth > 0) {
                            actualHealth -= PIKACHU_ATACK;
                        }
                        else if (actualHealth == 0) {
                            map[ashPosition.y][ashPosition.x + 1] = ' ';
                            pokeAlive = false;
                        }
                    }
                    else if (combatDecision == 2)
                    {
                        map[ashPosition.y][ashPosition.x + 1] = ' ';
                        pokedex++;
                        std::cout << pokedex;
                        pokeballs--;
                        std::cout << pokeballs;
                        pokeAlive = false;
                    }
                    else if (combatDecision == 3)
                    {
                        currentScene.currentScene = Scenes::MAP;
                        pokeAlive = false;
                    }
                    capturedPokes = true;
                }
            }
            if (capturedPokes) {
                ReGeneratePokes(map, area);
            }
    }
}

void CaptureMewtwo(Ash ashPosition, char** map, int& pokedex, int& pokeballs, SceneManager currentScene, Area& area)
{
    bool capturedPokes = false;
    bool pokeAlive = true;
    int actualHealth = MEWTWO_HEALTH;

    if (pokeballs > 0) {

        if (ashPosition.y > 0 && map[ashPosition.y - 1][ashPosition.x] == MEWTWO)
        {
            while (pokeAlive) {
                std::cout << "You found Mewtwo " << std::endl;
                std::cout << actualHealth << std::endl;
                CombatOptions();

                int combatDecision;
                std::cin >> combatDecision;


                if (combatDecision == 1)
                {

                    if (actualHealth > 0) {
                        actualHealth -= PIKACHU_ATACK;
                    }
                    else if (actualHealth == 0) {
                        map[ashPosition.y - 1][ashPosition.x] = ' ';
                        pokeAlive = false;
                    }

                }
                else if (combatDecision == 2)
                {
                    map[ashPosition.y - 1][ashPosition.x] = ' ';
                    pokedex++;
                    std::cout << pokedex;
                    pokeballs--;
                    std::cout << pokeballs;
                    pokeAlive = false;
                }
                else if (combatDecision == 3)
                {
                    currentScene.currentScene = Scenes::MAP;
                    pokeAlive = false;
                }
            }
        }
        if (ashPosition.y < MAP_HEIGHT - 1 && map[ashPosition.y + 1][ashPosition.x] == MEWTWO)
        {
            while (pokeAlive) {
                std::cout << "You found Mewtwo " << std::endl;
                std::cout << actualHealth << std::endl;
                CombatOptions();

                int combatDecision;
                std::cin >> combatDecision;


                if (combatDecision == 1)
                {
                    if (actualHealth > 0) {
                        actualHealth -= PIKACHU_ATACK;
                    }
                    else if (actualHealth == 0) {
                        map[ashPosition.y + 1][ashPosition.x] = ' ';
                        pokeAlive = false;
                    }
                }

                else if (combatDecision == 2)
                {
                    map[ashPosition.y + 1][ashPosition.x] = ' ';
                    pokedex++;
                    std::cout << pokedex;
                    pokeballs--;
                    std::cout << pokeballs;
                    pokeAlive = false;
                }
                else if (combatDecision == 3)
                {
                    currentScene.currentScene = Scenes::MAP;
                    pokeAlive = false;
                }
            }
        }
        if (ashPosition.x > 0 && map[ashPosition.y][ashPosition.x - 1] == MEWTWO)
        {
            while (pokeAlive) {
                std::cout << "You found Mewtwo " << std::endl;
                std::cout << actualHealth << std::endl;
                CombatOptions();

                int combatDecision;
                std::cin >> combatDecision;

                if (combatDecision == 1)
                {
                    if (actualHealth > 0) {
                        actualHealth -= PIKACHU_ATACK;
                    }
                    else if (actualHealth == 0) {
                        map[ashPosition.y][ashPosition.x - 1] = ' ';
                        pokeAlive = false;
                    }
                }
                else if (combatDecision == 2)
                {
                    map[ashPosition.y][ashPosition.x - 1] = ' ';
                    pokedex++;
                    std::cout << pokedex;
                    pokeballs--;
                    std::cout << pokeballs;
                    pokeAlive = false;
                }
                else if (combatDecision == 3)
                {
                    currentScene.currentScene = Scenes::MAP;
                    pokeAlive = false;
                }
            }
        }
        if (ashPosition.x < MAP_WIDTH - 1 && map[ashPosition.y][ashPosition.x + 1] == MEWTWO)
        {
            while (pokeAlive) {
                std::cout << "You found Mewtwo " << std::endl;
                std::cout << actualHealth << std::endl;
                CombatOptions();

                int combatDecision;
                std::cin >> combatDecision;

                if (combatDecision == 1)
                {
                    if (actualHealth > 0) {
                        actualHealth -= PIKACHU_ATACK;
                    }
                    else if (actualHealth == 0) {
                        map[ashPosition.y][ashPosition.x + 1] = ' ';
                        pokeAlive = false;
                    }
                }
                else if (combatDecision == 2)
                {
                    map[ashPosition.y][ashPosition.x + 1] = ' ';
                    pokedex++;
                    std::cout << pokedex;
                    pokeballs--;
                    std::cout << pokeballs;
                    pokeAlive = false;
                }
                else if (combatDecision == 3)
                {
                    currentScene.currentScene = Scenes::MAP;
                    pokeAlive = false;
                }
                
            }
        }
        
    }
}

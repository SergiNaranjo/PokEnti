
// Héctor Zornoza y Sergi Naranjo 

#include <iostream>
#include <ctime> 
#include <windows.h>
#include "Ash.h"
#include "Map.h"
#include "Conf.h" // El header no funciona 
#include "Menu.h"
#include "Combat.h"
#include "Util.h"
#include "SceneManager.h"



int Map()
{
    Ash ashPosition = { 0, 0 };
    int pokedex = 0;
    Region currentRegion = Region::PUEBLO_PALETA;
    SceneManager scene;
    scene.currentScene = Scenes::MAP;

    char** map = new char* [MAP_HEIGHT];

    for (int i = 0; i < MAP_HEIGHT; ++i)
    {
        map[i] = new char[MAP_WIDTH];
        for (int j = 0; j < MAP_WIDTH; ++j)
        {
            map[i][j] = ' ';
        }
    }

    for (int i = 0; i < MAP_HEIGHT; ++i)
    {
        for (int j = 0; j < MAP_WIDTH; ++j)
        {
            if (j == MAP_WIDTH / 2 - 1 || j == MAP_WIDTH / 2 || i == MAP_HEIGHT / 2 - 1 || i == MAP_HEIGHT / 2)
            {
                map[i][j] = WALLS;
            }
        }
    }

    generatePokes(map, 0, 0, MAP_WIDTH / 2 - 2, MAP_HEIGHT / 2 - 2);

    while (true)
    {
        printMap(ashPosition, map, pokedex);

        if ((currentRegion == Region::PUEBLO_PALETA && pokedex == MIN_POKES) ||
            (currentRegion == Region::BOSQUE_VERDE && pokedex == MIN_POKES * 2) ||
            (currentRegion == Region::CIUDAD_CELESTE && pokedex == MIN_POKES * 3))
        {
            moveToNextRegion(ashPosition, currentRegion, pokedex, map);
        }

        if (pokedex == 20)
        {
            std::cout << "Felicidades, te has hecho con todos" << std::endl;
        }

        if (GetAsyncKeyState(VK_UP))
        {
            if (canMove(ashPosition, 0, -1, map))
                ashPosition.y--;
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            if (canMove(ashPosition, 0, 1, map))
                ashPosition.y++;
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            if (canMove(ashPosition, -1, 0, map))
                ashPosition.x--;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            if (canMove(ashPosition, 1, 0, map))
                ashPosition.x++;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            capturePokes(ashPosition, map, pokedex, scene);
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            return 0;
        }

        Sleep(1000/NUM_FPS);
    }


    for (int i = 0; i < MAP_HEIGHT; ++i)
    {
        delete[] map[i];
    }
    delete[] map;
}

int main()
{
    SceneManager scenes;
    scenes.currentScene = Scenes::MENU;

  
    srand(time(nullptr));

    switch (scenes.currentScene)
    {
    case Scenes::MENU:
        MainMenu();

        int menuDecision;
        std::cin >> menuDecision;

        if (menuDecision == 1)
        {
            scenes.currentScene = Scenes::MAP;
        }
        else if (menuDecision == 2)
        {
            return -1;
        }

    case Scenes::MAP:
        Map();

        break;

    case Scenes::COMBAT:
        CombatOptions();

        int combatDecision;
        std::cin >> combatDecision;

        if (combatDecision == 1)
        {
            // LOGICA DE VIDA DE LOS POKEMON
        }
        else if (combatDecision == 2)
        {
            
        }
        else if (combatDecision == 3)
        {
            scenes.currentScene = Scenes::MAP;
        }

        break;

    }
}






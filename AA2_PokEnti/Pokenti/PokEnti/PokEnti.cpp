
// Héctor Zornoza y Sergi Naranjo 

#include <iostream>
#include <ctime> 
#include <windows.h>
#include "Ash.h"
#include "Map.h"
#include "Conf.h"  
#include "Menu.h"
#include "Combat.h"
#include "Util.h"
#include "SceneManager.h"

int pokedex = 0;
int pokeballs = 0;

int Map()
{
    Ash ashPosition = { 0, 0 };
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

    GeneratePokes(map, 0, 0, MAP_WIDTH / 2 - 2, MAP_HEIGHT / 2 - 2);
    GeneratePokeballs(map, 0, 0, MAP_WIDTH / 2 - 2, MAP_HEIGHT / 2 - 2);

    while (true)
    {
        PrintMap(ashPosition, map, pokedex);

        if ((currentRegion == Region::PUEBLO_PALETA && pokedex == MIN_POKES) ||
            (currentRegion == Region::BOSQUE_VERDE && pokedex == MIN_POKES * 2) ||
            (currentRegion == Region::CIUDAD_CELESTE && pokedex == MIN_POKES * 3))
        {
            MoveToNextRegion(ashPosition, currentRegion, pokedex, map);
        }

        if (pokedex == MIN_POKES*4)
        {
            std::cout << "Felicidades, te has hecho con todos" << std::endl;
        }

        if (GetAsyncKeyState(VK_UP))
        {
            if (CanMove(ashPosition, 0, -1, map))
                ashPosition.y--;
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            if (CanMove(ashPosition, 0, 1, map))
                ashPosition.y++;
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            if (CanMove(ashPosition, -1, 0, map))
                ashPosition.x--;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            if (CanMove(ashPosition, 1, 0, map))
                ashPosition.x++;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            CapturePokeballs(ashPosition, map, pokedex, scene);
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

    Config config;
   
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
            if (LeerConfig("config.txt", config)) {
                
                std::cout << "Ancho del mapa: " << config.ancho << std::endl;
                std::cout << "Alto del mapa: " << config.alto << std::endl;
                std::cout << "Pokémons en Pueblo Paleta: " << config.pokemonsPueblo << std::endl;
                std::cout << "Pokémons requeridos en Pueblo Paleta: " << config.pokemonsRequeridosPueblo << std::endl;
                std::cout << "Pokémons en el Bosque: " << config.pokemonsBosque << std::endl;
                std::cout << "Pokémons requeridos en el Bosque: " << config.pokemonsRequeridosBosque << std::endl;
            }
            else {
                std::cerr << "Error al leer la configuración." << std::endl;
            }

            break;
        }
        else if (menuDecision == 3)
        {
            return -1;
        }

    case Scenes::MAP:
        Map();

    case Scenes::COMBAT:
        CombatOptions();

        int combatDecision;
        std::cin >> combatDecision;

        if (combatDecision == 1)
        {
            // VIDA DE LOS POKEMON
        }
        else if (combatDecision == 2)
        {
            pokedex++;
            std::cout << pokedex;
        }
        else if (combatDecision == 3)
        {
            Map();
        }
    }
}






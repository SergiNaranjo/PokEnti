
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
#include "GameOver.h"

int pokedex = 0;
int pokeballs = 1;

int Map()
{
    Ash ashPosition = { 0, 0 };
    Region currentRegion = Region::PUEBLO_PALETA;
    SceneManager scene;
    Area area, area1;
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
    area = { 0, 0, MAP_WIDTH / 2 - 2, MAP_HEIGHT / 2 - 2 };
    GeneratePokes(map, area, ashPosition);
    area1 = { 0, 0, MAP_WIDTH / 2 - 2, MAP_HEIGHT / 2 - 2 };
    GeneratePokeballs(map, area1);

    while (true)
    {
        PrintMap(ashPosition, map, pokedex, pokeballs);

        if ((currentRegion == Region::PUEBLO_PALETA && pokedex == MIN_POKES) ||
            (currentRegion == Region::BOSQUE_VERDE && pokedex == MIN_POKES * 2) ||
            (currentRegion == Region::CIUDAD_CELESTE && pokedex == MIN_POKES * 3))
        {
            MoveToNextRegion(ashPosition, currentRegion, pokedex, map, area);
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
            CapturePokeballs(ashPosition, map, pokeballs, scene, area1);
            CapturePokes(ashPosition, map, pokedex, pokeballs, scene, area);
            CaptureMewtwo(ashPosition, map, pokedex, pokeballs, scene, area);
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
    scenes.currentScene = Scenes::MAP;

    Config config;
   
    srand(time(nullptr));

    while (true) {

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
                    std::cout << "Poténcia ataque pikachu: " << config.potenciaPikachu << std::endl;
                    std::cout << "Salud inicial Pokémons: " << config.saludPokes << std::endl;
                    std::cout << "Salud Mewtwo: " << config.saludMewtwo << std::endl;
                    std::cout << "Tiempo de espera min: " << config.minTemp << std::endl;
                    std::cout << "Tiempo de espera max: " << config.maxTemp << std::endl;
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
           
        case Scenes::GAMEOVER:
                GameOver();
                int menuGameOver;
                std::cin >> menuGameOver;
                if (menuGameOver == 1) {
                    Map();
                }
                else if (menuGameOver == 2) {
                    return 0;
                }
                
        }
    }
}






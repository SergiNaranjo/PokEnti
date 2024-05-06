
// Héctor Zornoza y Sergi Naranjo 

#include <iostream>
#include <ctime> 
#include <windows.h>
#include "Ash.h"
#include "Map.h"
#include "Conf.h" // El header no funciona 

int main()
{
    Ash ashPosition = { 0, 0 };       
    int pokedex = 0;                    
    Region currentRegion = Region::PUEBLO_PALETA;    

  
    srand(time(nullptr));


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
                map[i][j] = 'X';
            }
        }
    }

    generatePokes(map, 0, 0, MAP_WIDTH / 2 - 2, MAP_HEIGHT / 2 - 2);

    while (true)
    {
        printMap(ashPosition, map, pokedex);

        if ((currentRegion == Region::PUEBLO_PALETA && pokedex == 5) ||
            (currentRegion == Region::BOSQUE_VERDE && pokedex == 10) ||
            (currentRegion == Region::CIUDAD_CELESTE && pokedex == 15))
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
            capturePokes(ashPosition, map, pokedex);
        }
        if (GetAsyncKeyState(VK_ESCAPE)) 
        {
            return 0;
        }

        Sleep(100);
    }


    for (int i = 0; i < MAP_HEIGHT; ++i)
    {
        delete[] map[i];
    }
    delete[] map;

    return 0;
}




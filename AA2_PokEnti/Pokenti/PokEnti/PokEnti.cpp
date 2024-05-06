
// Héctor Zornoza y Sergi Naranjo 

#include <iostream>
#include <ctime> 
#include <windows.h>
#include "Ash.h"
#include "Map.h"

int main()
{
    Ash ashPosition = { 0, 0 };        
    int pokedex = 0;                       
    Region currentRegion = PUEBLO_PALETA;      

  
    srand(time(nullptr));

    char map[MAP_HEIGHT][MAP_WIDTH]; 

    
    for (int i = 0; i < MAP_HEIGHT; ++i)
    {
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

  
        if ((currentRegion == PUEBLO_PALETA && pokedex == 5) ||
            (currentRegion == BOSQUE_VERDE && pokedex == 10) ||
            (currentRegion == CIUDAD_CELESTE && pokedex == 15))
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

    return 0;
}




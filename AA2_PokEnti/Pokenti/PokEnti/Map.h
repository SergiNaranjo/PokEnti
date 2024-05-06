#pragma once
#include "Pokes.h"

enum Region
{
    PUEBLO_PALETA,
    BOSQUE_VERDE,
    CIUDAD_CELESTE,
    LIGA_POKENTI
};

void printMap(Ash ashPosition, char map[MAP_HEIGHT][MAP_WIDTH], int pokedex)
{
    system("cls");

    for (int i = 0; i < MAP_HEIGHT; ++i)
    {
        for (int j = 0; j < MAP_WIDTH; ++j)
        {
            if (ashPosition.x == j && ashPosition.y == i)
            {
                std::cout << "A";
            }
            else
            {
                std::cout << map[i][j]; 
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Pokédex: " << pokedex << std::endl;
}

void moveToNextRegion(Ash& ashPosition, Region& currentRegion, int pokedex, char map[MAP_HEIGHT][MAP_WIDTH])
{
    if (pokedex >= 5 && pokedex < 10)
    {
        for (int i = 0; i <= MAP_HEIGHT / 2 - 2; ++i)
        {
            for (int j = MAP_WIDTH / 2 - 1; j <= MAP_WIDTH / 2; ++j)
            {
                map[i][j] = ' ';
            }
        }
        currentRegion = BOSQUE_VERDE;
        generatePokes(map, MAP_WIDTH / 2 + 1, 0, MAP_WIDTH - 1, MAP_HEIGHT / 2 - 2);
    }
    else if (pokedex >= 10 && pokedex < 15)
    {
        for (int i = 0; i <= MAP_HEIGHT / 2; ++i)
        {
            for (int j = MAP_WIDTH / 2 + 1; j <= MAP_WIDTH; ++j)
            {
                map[i][j] = ' ';
            }
        }
        currentRegion = CIUDAD_CELESTE;
        generatePokes(map, MAP_WIDTH / 2 + 1, MAP_HEIGHT / 2 + 1, MAP_WIDTH - 1, MAP_HEIGHT - 1); 
    }
    else if (pokedex >= 15)
    {
        for (int i = 0; i <= MAP_HEIGHT; ++i)
        {
            for (int j = MAP_WIDTH / 2 - 1; j <= MAP_WIDTH / 2; ++j)
            {
                map[i][j] = ' ';
            }
        }
        currentRegion = LIGA_POKENTI;
     
        generatePokes(map, 0, MAP_HEIGHT / 2 + 1, MAP_WIDTH / 2 - 2, MAP_HEIGHT - 1);
    }
}
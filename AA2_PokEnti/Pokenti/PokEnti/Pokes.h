#pragma once
#include "Util.h"
#include "Ash.h"
#include <cstdlib>

void generatePokes(char** map, int startX, int startY, int endX, int endY)
{
    for (int i = 0; i < 5; ++i)
    {
        int randX = startX + rand() % (endX - startX + 1);
        int randY = startY + rand() % (endY - startY + 1);

        if (map[randY][randX] == ' ')
        {
            map[randY][randX] = 'P';
        }
        else
        {
            --i; 
        }
    }
}


void capturePokes(Ash ashPosition, char** map, int& pokedex)
{
    if (ashPosition.y > 0 && map[ashPosition.y - 1][ashPosition.x] == 'P')
    {
        map[ashPosition.y - 1][ashPosition.x] = ' ';
        pokedex++;
    }
    if (ashPosition.y < MAP_HEIGHT - 1 && map[ashPosition.y + 1][ashPosition.x] == 'P')
    {
        map[ashPosition.y + 1][ashPosition.x] = ' ';
        pokedex++;
    }
    if (ashPosition.x > 0 && map[ashPosition.y][ashPosition.x - 1] == 'P')
    {
        map[ashPosition.y][ashPosition.x - 1] = ' ';
        pokedex++;
    }
    if (ashPosition.x < MAP_WIDTH - 1 && map[ashPosition.y][ashPosition.x + 1] == 'P')
    {
        map[ashPosition.y][ashPosition.x + 1] = ' ';
        pokedex++;
    }
}
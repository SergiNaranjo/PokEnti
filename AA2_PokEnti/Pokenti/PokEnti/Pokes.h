#pragma once
#include "Util.h"
#include "Ash.h"
#include "Combat.h"
#include "SceneManager.h"
#include "Map.h"
#include <cstdlib>

void GeneratePokeballs(char** map, int startX, int startY, int endX, int endY)
{
    for (int i = 0; i < MIN_POKES; ++i)
    {
        int randX = startX + rand() % (endX - startX + 1);
        int randY = startY + rand() % (endY - startY + 1);

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

void GeneratePokes(char** map, int startX, int startY, int endX, int endY)
{
    int randX = startX + rand() % (endX - startX + 1);
    int randY = startY + rand() % (endY - startY + 1);

    if (map[randY][randX] == ' ')
    {
        map[randY][randX] = POKES;
    }
}


void CapturePokeballs(Ash ashPosition, char** map, int& pokeballs, SceneManager currentScene)
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

void CombatPokes(Ash ashPosition, char** map, SceneManager currentScene)
{
    if (map[ashPosition.x][ashPosition.y] == POKES)
    {
        
    }
}
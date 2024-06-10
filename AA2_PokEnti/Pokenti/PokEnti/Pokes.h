#pragma once
#include "Util.h"
#include "Ash.h"
#include "Combat.h"
#include "SceneManager.h"
#include "Map.h"
#include <cstdlib>

struct Area {
    int startX; 
    int startY;
    int endX; 
    int endY;
};

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

void GeneratePokes(char** map, Area& area)
{
    int randX = area.startX + rand() % (area.endX - area.startX + 1);
    int randY = area.startY + rand() % (area.endY - area.startY + 1);

    if (map[randY][randX] == ' ')
    {
        map[randY][randX] = POKES;
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
    bool capturedPokes = false;

    if (ashPosition.y > 0 && map[ashPosition.y - 1][ashPosition.x] == POKEBALL)
    {
        map[ashPosition.y - 1][ashPosition.x] = ' ';
        pokeballs++;
        capturedPokes = true;
    }
    if (ashPosition.y < MAP_HEIGHT - 1 && map[ashPosition.y + 1][ashPosition.x] == POKEBALL)
    {
        map[ashPosition.y + 1][ashPosition.x] = ' ';
        pokeballs++;
        capturedPokes = true;
    }
    if (ashPosition.x > 0 && map[ashPosition.y][ashPosition.x - 1] == POKEBALL)
    {
        map[ashPosition.y][ashPosition.x - 1] = ' ';
        pokeballs++;
        capturedPokes = true;
    }
    if (ashPosition.x < MAP_WIDTH - 1 && map[ashPosition.y][ashPosition.x + 1] == POKEBALL)
    {
        map[ashPosition.y][ashPosition.x + 1] = ' ';
        pokeballs++;
        capturedPokes = true;
    }
    if (capturedPokes) {
        ReGeneratePokes(map, area);
    }
}

void CombatPokes(Ash ashPosition, char** map, SceneManager currentScene)
{
    if (map[ashPosition.x][ashPosition.y] == POKES)
    {
        
    }
}
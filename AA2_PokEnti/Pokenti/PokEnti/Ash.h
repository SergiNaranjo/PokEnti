#pragma once
#include "Util.h"

enum class AshDirection
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    COUNT
};

struct Ash
{
    int x;
    int y;
    AshDirection lastDirection;
};

bool CanMove(Ash ashPosition, int newAshPositionX, int newAshPositionY, char** map)
{
    
    int newPosX = ashPosition.x + newAshPositionX;
    int newPosY = ashPosition.y + newAshPositionY;

    // Verifica si la nueva posición está dentro de los límites del mapa
    return (newPosX >= 0 && newPosX < MAP_WIDTH && newPosY >= 0 && newPosY < MAP_HEIGHT && map[newPosY][newPosX] != 'X');
}
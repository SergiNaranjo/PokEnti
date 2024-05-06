#pragma once
#include "Util.h"

enum class ashDirection
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
    ashDirection lastDirection;
};

bool canMove(Ash ashPosition, int newAshPositionX, int newAshPositionY, char** map)
{
    // Nueva posici�n
    int newPosX = ashPosition.x + newAshPositionX;
    int newPosY = ashPosition.y + newAshPositionY;

    // Verifica si la nueva posici�n est� dentro de los l�mites del mapa
    return (newPosX >= 0 && newPosX < MAP_WIDTH && newPosY >= 0 && newPosY < MAP_HEIGHT && map[newPosY][newPosX] != 'X');
}
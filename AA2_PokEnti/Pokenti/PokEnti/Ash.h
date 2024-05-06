#pragma once
#include "Util.h"

struct Ash
{
    int x;
    int y;
};

bool canMove(Ash ashPosition, int dx, int dy, char map[MAP_HEIGHT][MAP_WIDTH])
{
    int new_x = ashPosition.x + dx;
    int new_y = ashPosition.y + dy;

    if (new_x < 0 || new_x >= MAP_WIDTH || new_y < 0 || new_y >= MAP_HEIGHT)
    {
        return false;
    }

    if (map[new_y][new_x] == 'X')
    {
        if (map[ashPosition.y][ashPosition.x] == ' ' || map[ashPosition.y][ashPosition.x] == 'P')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return true;
}
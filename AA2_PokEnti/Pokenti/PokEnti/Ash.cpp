#include "Ash.h"

bool movingAsh(Ash ashPosition, int newAshPositionX, int newAshPositionY, char** map)
{

    int newPosX = ashPosition.x + newAshPositionX;
    int newPosY = ashPosition.y + newAshPositionY;


    if (newPosX < 0 || newPosX >= WIDTH || newPosY < 0 || newPosY >= HEIGHT)
    {
        return false;
    }


    if (map[newPosY][newPosX] == 'X')
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
#pragma once
#include "Util.h"

struct Ash
{
    int x;
    int y;
};

bool canMove(Ash ashPosition, int dx, int dy, char map[MAP_HEIGHT][MAP_WIDTH])
{
    // Nueva posici�n
    int new_x = ashPosition.x + dx;
    int new_y = ashPosition.y + dy;

    // Verifica si la nueva posici�n est� dentro de los l�mites del mapa
    if (new_x < 0 || new_x >= MAP_WIDTH || new_y < 0 || new_y >= MAP_HEIGHT)
    {
        return false;
    }

    // Verifica si la nueva posici�n est� bloqueada por una barrera
    if (map[new_y][new_x] == 'X')
    {
        // Si el jugador ha capturado todos los Pok�mon de la zona, puede cruzar las barreras
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
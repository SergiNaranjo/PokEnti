#pragma once
#include "Pokes.h"

enum class Region
{
    PUEBLO_PALETA,
    BOSQUE_VERDE,
    CIUDAD_CELESTE,
    LIGA_POKENTI,
    COUNT
};

void printMap(Ash ashPosition, char** map, int pokedex)
{
    system("cls");

    char ashSymbol;
    if (GetAsyncKeyState(VK_UP)) 
    {
        ashSymbol = '^';
    }
    else if (GetAsyncKeyState(VK_DOWN)) 
    {
        ashSymbol = 'v';
    }
    else if (GetAsyncKeyState(VK_LEFT)) 
    {
        ashSymbol = '<';
    }
    else if (GetAsyncKeyState(VK_RIGHT)) 
    {
        ashSymbol = '>';
    }
    else 
    {
        if (ashPosition.lastDirection == ashDirection::UP)
        {
            ashSymbol = '^';
        }
        else if (ashPosition.lastDirection == ashDirection::DOWN)
        {
            ashSymbol = 'v';
        }  
        else if (ashPosition.lastDirection == ashDirection::LEFT)
        {
            ashSymbol = '<';
        }   
        else if (ashPosition.lastDirection == ashDirection::RIGHT)
        {
            ashSymbol = '>';
        }
        else
        {
            ashSymbol = 'A';
        }
    }

    for (int i = 0; i < MAP_HEIGHT; ++i)
    {
        for (int j = 0; j < MAP_WIDTH; ++j)
        {
            if (ashPosition.x == j && ashPosition.y == i)
            {
                std::cout << ashSymbol;
            }
            else
            {
                std::cout << map[i][j];
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Pokedex: " << pokedex << std::endl;
}

void moveToNextRegion(Ash& ashPosition, Region& currentRegion, int pokedex, char** map)
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
        currentRegion = Region::BOSQUE_VERDE;
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
        currentRegion = Region::CIUDAD_CELESTE;
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
        currentRegion = Region::LIGA_POKENTI;
     
        generatePokes(map, 0, MAP_HEIGHT / 2 + 1, MAP_WIDTH / 2 - 2, MAP_HEIGHT - 1);
    }
}
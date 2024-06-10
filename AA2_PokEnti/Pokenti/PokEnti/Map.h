#pragma once
#include "Pokes.h"
#include "Util.h"

enum class Region
{
    PUEBLO_PALETA,
    BOSQUE_VERDE,
    CIUDAD_CELESTE,
    LIGA_POKENTI,
    COUNT
};

void PrintMap(Ash ashPosition, char** map, int pokeballs)
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
        if (ashPosition.lastDirection == AshDirection::UP)
        {
            ashSymbol = '^';
        }
        else if (ashPosition.lastDirection == AshDirection::DOWN)
        {
            ashSymbol = 'v';
        }  
        else if (ashPosition.lastDirection == AshDirection::LEFT)
        {
            ashSymbol = '<';
        }   
        else if (ashPosition.lastDirection == AshDirection::RIGHT)
        {
            ashSymbol = '>';
        }
       
            ashSymbol = 'A';
        
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

    std::cout << "Pokeballs: " << pokeballs << std::endl;
}

void MoveToNextRegion(Ash& ashPosition, Region& currentRegion, int pokedex, char** map)
{
    if (pokedex >= MIN_POKES && pokedex < MIN_POKES*2)
    {
        for (int i = 0; i <= MAP_HEIGHT / 2 - 2; ++i)
        {
            for (int j = MAP_WIDTH / 2 - 1; j <= MAP_WIDTH / 2; ++j)
            {
                map[i][j] = ' ';
            }
        }
        currentRegion = Region::BOSQUE_VERDE;
        Area area = { MAP_WIDTH / 2 + 1, 0, MAP_WIDTH - 1, MAP_HEIGHT / 2 - 2 };
        GeneratePokeballs(map, area);
    }
    else if (pokedex >= MIN_POKES * 2 && pokedex < MIN_POKES*3)
    {
        for (int i = 0; i <= MAP_HEIGHT / 2; ++i)
        {
            for (int j = MAP_WIDTH / 2 + 1; j <= MAP_WIDTH; ++j)
            {
                map[i][j] = ' ';
            }
        }
        currentRegion = Region::CIUDAD_CELESTE;
        Area area = { MAP_WIDTH / 2 + 1, MAP_HEIGHT / 2 + 1, MAP_WIDTH - 1, MAP_HEIGHT - 1 };
        GeneratePokeballs(map, area);
    }
    else if (pokedex >= MIN_POKES*3)
    {
        for (int i = 0; i < MAP_HEIGHT; ++i)
        {
            for (int j = MAP_WIDTH / 2 - 1; j < MAP_WIDTH; ++j)
            {
                map[i][j] = ' ';
            }
        }
        currentRegion = Region::LIGA_POKENTI;
        Area area = { 0, MAP_HEIGHT / 2 + 1, MAP_WIDTH / 2 - 2, MAP_HEIGHT - 1 };
        GeneratePokeballs(map, area);
    }
}
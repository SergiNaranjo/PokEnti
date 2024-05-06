#include "Mapa.h"

void printMap(Ash ashPosition, char** map, int pokedex, int height)
{

    system("cls");


    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {

            if (ashPosition.x == j && ashPosition.y == i)
            {
                std::cout << "A";
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
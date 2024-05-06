#include "Mapa.h"

void moveNextRegion(Ash& ashPosition, Region& currentZone, int pokedex, char** map)
{

    if (pokedex >= 5 && pokedex < 10)
    {

        for (int i = 0; i <= HEIGHT / 2 - 2; ++i)
        {
            for (int j = WIDTH / 2 - 1; j <= WIDTH / 2; ++j)
            {
                map[i][j] = ' ';
            }
        }
        currentZone = BOSQUE_VERDE;

        generatingPokes(map, WIDTH / 2 + 1, 0, WIDTH - 1, HEIGHT / 2 - 2);
    }
    else if (pokedex >= 10 && pokedex < 15)
    {

        for (int i = 0; i <= HEIGHT / 2; ++i)
        {
            for (int j = WIDTH / 2 + 1; j <= WIDTH; ++j)
            {
                map[i][j] = ' ';
            }
        }
        currentZone = CIUDAD_CELESTE;
        generatingPokes(map, WIDTH / 2 + 1, HEIGHT / 2 + 1, WIDTH - 1, HEIGHT - 1);
    }
    else if (pokedex >= 15)
    {

        for (int i = 0; i < HEIGHT; ++i)
        {
            for (int j = WIDTH / 2 - 1; j < WIDTH / 2 + 1; ++j)
            {
                map[i][j] = ' ';
            }
        }
        currentZone = LIGA_POKENTI;

        generatingPokes(map, 0, HEIGHT / 2 + 1, WIDTH / 2 - 2, HEIGHT - 1);
    }
}
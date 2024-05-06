#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <windows.h>
#include "LectorArchivoConf.h"
#include "Mapa.h"
#include "Ash.h"
#include "Movement.h"
#include "Pokes.h"



int main()
{
    Ash ashPosition = { 0, 0 };        
    int pokedex = 0;                       
    Region currentRegion = PUEBLO_PALETA;      

    
    srand(time(nullptr));

    
    char** map = new char* [HEIGHT];
    for (int i = 0; i < HEIGHT; ++i)
    {
        map[i] = new char[WIDTH];
        for (int j = 0; j < WIDTH; ++j)
        {
            map[i][j] = ' ';
        }
    }

    // Genera las barreras entre las cuatro ubicaciones del mapa
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (j == WIDTH / 2 - 1 || j == WIDTH / 2 || i == HEIGHT / 2 - 1 || i == HEIGHT / 2)
            {
                map[i][j] = 'X';
            }
        }
    }

   
    generatingPokes(map, 0, 0, WIDTH / 2 - 2, HEIGHT / 2 - 2);

    
    while (true)
    {
        printMap(ashPosition, map, pokedex, HEIGHT); // Imprime el mapa con la posición actual de Ash y el contador de la Pokédex

        // Verifica si todos los Pokémon en la zona actual han sido capturados
        if ((currentRegion == PUEBLO_PALETA && pokedex == 5) ||
            (currentRegion == BOSQUE_VERDE && pokedex == 10) ||
            (currentRegion == CIUDAD_CELESTE && pokedex == 15))
        {
            moveNextRegion(ashPosition, currentRegion, pokedex, map);
        }

        if (pokedex == 20)
        {
            std::cout << "Felicidades, te has hecho con todos" << std::endl;
        }

        
        if (GetAsyncKeyState(VK_UP)) 
        {
            if (movingAsh(ashPosition, 0, -1, map))
                ashPosition.y--;
        }
        if (GetAsyncKeyState(VK_DOWN)) 
        {
            if (movingAsh(ashPosition, 0, 1, map))
                ashPosition.y++;
        }
        if (GetAsyncKeyState(VK_LEFT)) 
        {
            if (movingAsh(ashPosition, -1, 0, map))
                ashPosition.x--;
        }
        if (GetAsyncKeyState(VK_RIGHT)) 
        {
            if (movingAsh(ashPosition, 1, 0, map))
                ashPosition.x++;
        }
        if (GetAsyncKeyState(VK_SPACE)) // Espacio (capturar Pokémon)
        {
            capturePokes(ashPosition, map, pokedex);
        }
        if (GetAsyncKeyState(VK_ESCAPE)) 
        {
            return 0;
        }

        // Hace una pausa de 100 milisegundos antes de volver a imprimir el mapa
        Sleep(100);
    }

    
    for (int i = 0; i < HEIGHT; ++i)
    {
        delete[] map[i];
    }
    delete[] map;

    std::string nombreArchivo = "config.txt";
    std::vector<int> valores = leerValoresDesdeArchivo(nombreArchivo);
    if (!valores.empty()) {
        // Asignar valores a variables
        if (valores.size() >= 2) {
            int variable1 = valores[0];
            int variable2 = valores[1];
        }
        else {
            std::cerr << "El archivo no contiene suficientes valores.\n";
        }
    }
    else {
        std::cerr << "No se pudieron leer valores del archivo.\n";
    }

    return 0;
}





#pragma once
#include "Conf.h"

//Las variables globales de la configuración no permiten dividir en cpps y headers

Config config;

bool succes = LeerConfig("config.txt", config);

int pokedex = 0;
int pokeballs = 1;

	const int MAP_WIDTH = config.ancho;
	const int MAP_HEIGHT = config.alto;

	const int MIN_POKES = config.pokemonsPueblo;

	const int NUM_FPS = 10;

	const int POKES_HEALTH = config.saludPokes;
	const int MEWTWO_HEALTH = config.saludMewtwo;
	const int PIKACHU_ATACK = config.potenciaPikachu;

	const char WALLS = 'X';
	const char POKES = 'P';
	const char MEWTWO = 'M';
	const char POKEBALL = 'O';

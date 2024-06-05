#pragma once
#include "Conf.h"

Config config;

int ancho = config.ancho;
int altura = config.alto;

const int MAP_WIDTH = 50;
const int MAP_HEIGHT = 50;

const int MIN_POKES = 5;

const int NUM_FPS = 20;

const char WALLS = 'X';
const char POKES = 'P';
const char MEWTWO = 'M';
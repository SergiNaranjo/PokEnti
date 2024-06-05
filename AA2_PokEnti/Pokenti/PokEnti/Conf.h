# pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


struct Config {
    int ancho;
    int alto;
    int pokemonsPueblo;
    int pokemonsRequeridosPueblo;
    int pokemonsBosque;
    int pokemonsRequeridosBosque;
};

bool leerConfig(const std::string& nombreArchivo, Config& config) {
    std::ifstream configFile(nombreArchivo);
    if (!configFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo de configuración." << std::endl;
        return false;
    }

    std::string line;
    // Leer y procesar la primera línea (ancho y alto del mapa)
    if (std::getline(configFile, line)) {
        std::stringstream ss(line);
        std::string temp;
        if (std::getline(ss, temp, ';')) {
            config.ancho = std::stoi(temp);
        }
        if (std::getline(ss, temp, ';')) {
            config.alto = std::stoi(temp);
        }
    }

    // Leer y procesar la segunda línea (Pokémons en Pueblo Paleta y requeridos)
    if (std::getline(configFile, line)) {
        std::stringstream ss(line);
        std::string temp;
        if (std::getline(ss, temp, ';')) {
            config.pokemonsPueblo = std::stoi(temp);
        }
        if (std::getline(ss, temp, ';')) {
            config.pokemonsRequeridosPueblo = std::stoi(temp);
        }
    }

    // Leer y procesar la tercera línea (Pokémons en el Bosque y requeridos)
    if (std::getline(configFile, line)) {
        std::stringstream ss(line);
        std::string temp;
        if (std::getline(ss, temp, ';')) {
            config.pokemonsBosque = std::stoi(temp);
        }
        if (std::getline(ss, temp, ';')) {
            config.pokemonsRequeridosBosque = std::stoi(temp);
        }
    }

    // Cerrar el archivo de configuración
    configFile.close();
    return true;
}

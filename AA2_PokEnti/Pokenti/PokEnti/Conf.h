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
    int potenciaPikachu;
    int saludPokes;
    int saludMewtwo;
    int minTemp;
    int maxTemp;
};

bool LeerConfig(const std::string& nombreArchivo, Config& config) {
    std::ifstream configFile(nombreArchivo);
    if (!configFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo de configuración." << std::endl;
        return false;
    }

    std::string line;
    
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

    if (std::getline(configFile, line)) {
        std::stringstream ss(line);
        std::string temp;
        if (std::getline(ss, temp, ';')) {
            config.potenciaPikachu = std::stoi(temp);
        }
    }

    if (std::getline(configFile, line)) {
        std::stringstream ss(line);
        std::string temp;
        if (std::getline(ss, temp, ';')) {
            config.saludPokes = std::stoi(temp);
        }
        if (std::getline(ss, temp, ';')) {
            config.saludMewtwo = std::stoi(temp);
        }
    }

    if (std::getline(configFile, line)) {
        std::stringstream ss(line);
        std::string temp;
        if (std::getline(ss, temp, ';')) {
            config.minTemp = std::stoi(temp);
        }
        if (std::getline(ss, temp, ';')) {
            config.maxTemp = std::stoi(temp);
        }
    }
    
    configFile.close();
    return true;
}

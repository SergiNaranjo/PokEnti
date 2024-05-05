#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Función para leer valores desde un archivo
std::vector<int> leerValoresDesdeArchivo(const std::string& nombreArchivo) {
    std::vector<int> valores;
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            try {
                int valor = std::stoi(linea);
                valores.push_back(valor);
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Error: El archivo contiene valores no numéricos.\n";
                return {};
            }
        }
        archivo.close();
    }
    else {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << "\n";
        return {};
    }
    return valores;
}
#pragma once
#include <iostream>
#include <fstream>
#include <string>

void SplashScreen() {
    
    std::string filePath = "SplashScreen.txt";

    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << filePath << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}


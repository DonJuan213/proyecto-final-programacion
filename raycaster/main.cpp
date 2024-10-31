#include <iostream>
#include <vector>
#include "FileReader.h"
#include "Object.h"
#include "Game.h"

int main() {
    Game game;
    game.startGame();  

    std::vector<Object> objectList;

    // Llamar a la funci�n para leer objetos desde el archivo
    if (FileReader::readObjectsFromFile("ObjetosLeer.csv", objectList)) {
        std::cout << "Lectura exitosa. Objetos le�dos:" << std::endl;

        // Mostrar los objetos le�dos
        for (const auto& obj : objectList) {
            std::cout << "Tipo: " << obj.getType()
                << ", Posici�n: (" << obj.getPosition().x << ", " << obj.getPosition().y << ")"
                << ", Escala: " << obj.getScale()
                << ", Shift: " << obj.getShift() << std::endl;
        }
    }
    else {
        std::cerr << "Error al leer el archivo." << std::endl;
    }

    return 0;
}

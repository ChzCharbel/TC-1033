/*
Clase map.h
Charbel Isaias Chavez Zavala
A01711950

Esta clase sirve para crear mapas y mandarlos al menu de mapas en el main.cpp
*/

#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <string>

using namespace std;

class Map{
    private:
        //atributos
        string mapName;

    public:
        //constructores
        Map(){};
        Map(string name):mapName(name){};

        /**
        * getter mapName
        *
        * @param
        * @return string: mapName
        */
        string getMap() const{
            return mapName;
        }
};

//objetos de la clase Mapa
//que representan los mapas del juego.
Map mapa1("Desierto");
Map mapa2("Jungla");
Map mapa3("Nieve");
Map mapa4("Montañas");

#endif
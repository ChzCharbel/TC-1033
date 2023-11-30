#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <string>

using namespace std;

class Map{
    private:
        string mapName;

    public:
        Map(){};
        Map(string name):mapName(name){};

        string getMap() const{
            return mapName;
        }
};

Map mapa1("Desierto");
Map mapa2("Jungla");
Map mapa3("Nieve");
Map mapa4("Montañas");

#endif